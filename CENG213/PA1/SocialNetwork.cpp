#include "SocialNetwork.h"

#include <iostream>

SocialNetwork::SocialNetwork() {

}

void SocialNetwork::addProfile(const std::string &firstname, const std::string &lastname, const std::string &email) {
    Profile profile;
    profile.setFirstname(firstname);
    profile.setLastname(lastname);
    profile.setEmail(email);
    
    profiles.insertSorted(profile);
}

void SocialNetwork::addPost(const std::string &message, const std::string &email) {
    
    Post post (message);
    posts.insertAtTheTail(post);
    
    Node<Profile> *f = profiles.getFirstNode();
    
    while ( f->data.getEmail() != email ) {
        f = f->next;
    }
    
    f->data.addPost(&((posts.getLastNode())->data)) ;

}

void SocialNetwork::deleteProfile(const std::string &email) {
    
    Node<Profile> *p = profiles.getFirstNode();
    Node<Profile> *willbedeleted = profiles.getFirstNode();
    
    Node<Post *> *like_willbedeleted;
    Node<Post *> *post_willbedeleted;
    
    while ( willbedeleted->data.getEmail() != email ) {
            willbedeleted = willbedeleted->next;
    }
    
    
    while (p != nullptr) {
        
        if ( p->data.getEmail() == email ) {
            p = p->next;
            continue;
        }
        
        like_willbedeleted = willbedeleted->data.getPosts().getFirstNode();
        
        while (like_willbedeleted != nullptr) {
                unlikePost(like_willbedeleted->data->getPostId(), p->data.getEmail());
                like_willbedeleted = like_willbedeleted->next;
        }

        p->data.dropFriend(&(willbedeleted->data));
        
        p = p->next;
    }
    
    //Deleting person's posts from posts
    post_willbedeleted = willbedeleted->data.getPosts().getFirstNode();
    
    while(post_willbedeleted != nullptr){
        this->posts.removeNode(*(post_willbedeleted->data));
        post_willbedeleted = post_willbedeleted->next;
    }
    
    //Deleting the profile content and profile
    willbedeleted->data.getFriends().removeAllNodes();
    willbedeleted->data.getPosts().removeAllNodes();
    willbedeleted->data.getLikes().removeAllNodes();

    profiles.removeNode(willbedeleted->data);
  
}

void SocialNetwork::makeFriends(const std::string &email1, const std::string &email2) {
    Node<Profile> *p1 = profiles.getFirstNode();
    while ( p1->data.getEmail() != email1 ) {
        p1 = p1->next;
    }
    
    Node<Profile> *p2 = profiles.getFirstNode();
    while ( p2->data.getEmail() != email2 ) {
        p2 = p2->next;
    }
    

    p1->data.addFriend(&(p2->data));
    p2->data.addFriend(&(p1->data));
}

void SocialNetwork::likePost(int postId, const std::string &email) {

    Node<Profile> *p = profiles.getFirstNode();
    while ( p->data.getEmail() != email) {
        p = p->next;
    }
    
    Node<Post> *post = posts.getFirstNode();
    while ( post->data.getPostId() != postId) {
        post = post->next;
    }
    
    p->data.addLike(&(post->data));

}

void SocialNetwork::unlikePost(int postId, const std::string &email) {

    Node<Profile> *p = profiles.getFirstNode();
    while ( p->data.getEmail() != email ) {
        p = p->next;
    }
    
    Node<Post> *post = posts.getFirstNode();
    while (post != nullptr && post->data.getPostId() != postId) {
        post = post->next;
    }
    
    if (post == nullptr)
        return;
    
    p->data.dropLike(&(post->data));
    
}

LinkedList<Profile *> SocialNetwork::getMutualFriends(const std::string &email1, const std::string &email2) {
    
    LinkedList<Profile *> mutual;
    
    Node<Profile> *p1 = profiles.getFirstNode();
    while ( p1->data.getEmail() != email1 ) {
        p1 = p1->next;
    }
    
    Node<Profile> *p2 = profiles.getFirstNode();
    while ( p2->data.getEmail() != email2 ) {
        p2 = p2->next;
    }
    
    Node<Profile *> *c1 = p1->data.getFriends().getFirstNode();
    Node<Profile *> *c2 = p2->data.getFriends().getFirstNode();
    
    while (c1 != nullptr) {
        while (c2 != nullptr) {
            if (c1->data == c2->data) {
                mutual.insertAtTheTail(c1->data);
            }
            c2 = c2->next;
        }
        c2 = p2->data.getFriends().getFirstNode();
        c1 = c1->next;
    }

    return mutual;
}

LinkedList<Post *> SocialNetwork::getListOfMostRecentPosts(const std::string &email, int k) {
    LinkedList<Post *> ps;
    
    Node<Profile> *p = profiles.getFirstNode();
    while ( p->data.getEmail() != email) {
        p = p->next;
    }
    
    Node<Post *> *post = p->data.getPosts().getLastNode();
    
    for (int i = 0; i < k; i++) {
        if (post == nullptr) {
			break;
		}
        ps.insertAtTheTail(post->data);
        post = post->prev;
    }
    return ps;
}

void SocialNetwork::print() const {
    std::cout << "# Printing the social network ..." << std::endl;

    std::cout << "# Number of profiles is " << profiles.getNumberOfNodes() << ":" << std::endl;
    profiles.print();

    std::cout << "# Number of posts is " << posts.getNumberOfNodes() << ":" << std::endl;
    posts.print();

    std::cout << "# Printing is done." << std::endl;
}
