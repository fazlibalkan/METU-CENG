#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <functional>
#include <cstddef>
#include <ostream>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <utility>

#include <iostream>   // you may use it for debugging your code


class DefaultBalanceCondition    // default BST, do not change
{
  public:
    bool operator() (int current_height, int ideal_height) const
    {
      return true;
    }
};


template <typename Key, typename Object,
          typename BalanceCondition=DefaultBalanceCondition,
	  typename Comparator=std::less<Key> >
class BinarySearchTree
{
  public:  /* DO NOT CHANGE */
    struct Node   // core structure of BinarySearchTree
    {
       Key key;         // unique key
       Object data;     // data to be stored, characterized by key
       Node * left;     // pointer to left subtree
       Node * right;    // pointer to right subtree
       size_t height;   // height of the node
       size_t subsize;  // size of the subtree node roots including itself

       Node(const Key &, const Object &, 
            Node *, Node *, size_t =0, size_t =1);   // Node constructor
    };

  public:  /* DO NOT CHANGE PROTOTYPES */
    BinarySearchTree();  // zero-parameter constructor
    BinarySearchTree(const std::list<std::pair<Key, Object> > &); // list is always sorted!
    ~BinarySearchTree();  // destructor

  public:  /* DO NOT CHANGE PROTOTYPES */
    void insert(const Key &, const Object &);  // insert new Key-Object
    void remove(const Key &);  // remove Node characterized by Key
    void toCompleteBST();  // convert into a complete BST

  public:  /* DO NOT CHANGE PROTOTYPES */
    Node * find(const Key &) const; // single item
    std::list<Node *> find(const Key &, const Key &) const; // range queries
    int height() const;  // return the height of the tree
    size_t size() const; // return the number of items in the tree
    bool empty() const;  //return whether the tree is empty or not
    Node * getRoot() const; // return a pointer to the root of the tree
    void print(std::ostream &) const;  // print tree structure into an output stream

  private:  /* DO NOT CHANGE DATA TYPES AND IDENTIFIERS */
    Node * root;                     // designated root
    size_t numNodes;                 // size
    Comparator isLessThan;           // operator upon which BST nodes are arranged
    BalanceCondition isBalanced;     // signals whether the BST is balanced or not
  
  private:  /* DO NOT CHANGE PROTOTYPES */
    Node * find(const Key &, Node *) const;
    int height(Node *) const;
    int subsize(Node *) const;
    void print(Node *, std::ostream &) const;

    // Define your const private utility functions below this line
    template <typename iter>
    void createMinHeightCompleteBST(Node * &, int, int,  const std::list<std::pair<Key, Object> > &, iter &) const;
    
  private:
    void makeEmpty(Node * &);       // utility for destructor
    
    // Define your private utility functions below this line
    void toCompleteBSTHelper(int, int, Node * &, std::vector<Node *> &);
    void fillingTheVector(std::vector<Node *> &, Node * &);
    int findRoot(int );
    void insertHelper(const Key &, const Object &, Node * &);
    void removeHelper(Node * &, const Key &, Node * &, int);
    Node *  getMin(Node * &); 
    void findHelper(Node *, const Key &, const Key &, std::list<Node *> &) const;

    
  private: /* DO NOT CHANGE PROTOTYPES: compiler defaults are blocked */  
    BinarySearchTree(const BinarySearchTree &);
    const BinarySearchTree & operator=(const BinarySearchTree &);

  private:  // static utility functions
    template <typename T> //static utility function
    static const T & max(const T &, const T &);

    // Define more below this line if needed
    

};

#endif


// DO NOT CHANGE
template <typename K, typename O, typename B, typename C>
BinarySearchTree<K,O,B,C>::Node::
Node(const K & _k, const O & _d, Node * _l, Node * _r, size_t _h, size_t _s)
  : key(_k), data(_d), left(_l), right(_r), height(_h), subsize(_s)
{
}


// DO NOT CHANGE
template <typename K, typename O, typename B, typename C>
BinarySearchTree<K,O,B,C>::BinarySearchTree()
  : root(NULL), numNodes(0)  //comparator(C() ??)
{
}


// IMPLEMENT
template <typename K, typename O, typename B, typename C>
BinarySearchTree<K,O,B,C>::BinarySearchTree(const std::list<std::pair<K,O> > & datalist)
   : root(NULL), numNodes(0)  // change it as you'd like
{
    int listsize = datalist.size();
    numNodes = listsize;

    typename std::list<std::pair<K,O> >::const_iterator itr = datalist.begin();
    
    createMinHeightCompleteBST(root, 0, listsize, datalist, itr);
    

}


// IMPLEMENT
template <typename K, typename O, typename B, typename C>
void
BinarySearchTree<K,O,B,C>::toCompleteBST()
{
    
    std::vector<Node*> sortedNodes;
    fillingTheVector(sortedNodes, root);
    int vectorsize = sortedNodes.size();
    toCompleteBSTHelper(0, vectorsize-1, root, sortedNodes);

}


// IMPLEMENT
template <typename K, typename O, typename B, typename C>
void
BinarySearchTree<K,O,B,C>::insert(const K & k, const O & x)
{
    insertHelper(k, x, root);
}


// IMPLEMENT
template <typename K, typename O, typename B, typename C>
void
BinarySearchTree<K,O,B,C>::remove(const K & k)
{
    Node * willbedeleted = find(k);
    if (willbedeleted) {
        removeHelper(root, k, root, 0);
        delete willbedeleted;
        numNodes--;
    }
    
}



// DO NOT CHANGE
template <typename K, typename O, typename B, typename C>
typename BinarySearchTree<K,O,B,C>::Node *
BinarySearchTree<K,O,B,C>::find(const K & key) const
{
  return find(key, root);
}


// DO NOT CHANGE
template <typename K, typename O, typename B, typename C>
typename BinarySearchTree<K,O,B,C>::Node *
BinarySearchTree<K,O,B,C>::find(const K & key, Node * t) const
{
  if (t == NULL)
  {
    return NULL;
  }
  else if (isLessThan(key, t->key))
  {
    return find(key, t->left);
  }
  else if (isLessThan(t->key, key))
  {
    return find(key, t->right);
  }
  else //found
  {
    return t;
  }
}


// IMPLEMENT
template <typename K, typename O, typename B, typename C>
std::list<typename BinarySearchTree<K,O,B,C>::Node *>
BinarySearchTree<K,O,B,C>::find(const K & lower, const K & upper) const
{
  std::list<Node *> ranges;
    
    findHelper(root, lower, upper, ranges);

    // IMPLEMENT

  return ranges;
}


// DO NOT CHANGE
template <typename K, typename O, typename B, typename C>
typename BinarySearchTree<K,O,B,C>::Node *
BinarySearchTree<K,O,B,C>::getRoot() const
{
  return root;
}


// DO NOT CHANGE
template <typename K, typename O, typename B, typename C>
int
BinarySearchTree<K,O,B,C>::height() const
{
  return height(root);
}


// DO NOT CHANGE
template <typename K, typename O, typename B, typename C>
int
BinarySearchTree<K,O,B,C>::height(Node * t) const
{
  return (t == NULL) ? -1 : t->height;
}


// private utility
template <typename K, typename O, typename B, typename C>
int
BinarySearchTree<K,O,B,C>::subsize(Node * t) const
{
  return (t == NULL) ? 0 : t->subsize;
}

// my private utilities
template <typename K, typename O, typename B, typename C>
template <typename iter>
void 
BinarySearchTree<K,O,B,C>::createMinHeightCompleteBST(Node * &ptr, int i, int n, const std::list<std::pair<K,O> > & datalist, iter & itr) const 
{
    
    if (i < n) {
        ptr = new Node((datalist.begin())->first, (datalist.begin())->second, NULL, NULL, 0 , 0);
        
        createMinHeightCompleteBST(ptr->left, 2*i+1, n, datalist, itr);
        
        ptr->key = itr->first;
        ptr->data = itr->second;
        ++itr;

        createMinHeightCompleteBST(ptr->right, 2*i+2, n, datalist, itr);
        
        ptr->height = 1 + height(ptr->left);
        ptr->subsize = 1 + subsize(ptr->left) + subsize(ptr->right);
        
    }
}

template <typename K, typename O, typename B, typename C>
void
BinarySearchTree<K,O,B,C>::fillingTheVector(std::vector<Node *> & ns, Node * &ptr)
{
    if (ptr == NULL) {
        return;
    } else {
        fillingTheVector(ns, ptr->left);
        ns.push_back(ptr);
        fillingTheVector(ns, ptr->right);
    }
    
}

template <typename K, typename O, typename B, typename C>
int
BinarySearchTree<K,O,B,C>::findRoot(int n) {
    if (n == 1) {
        return 0;
    }
    int nodesonlastright, height, maxnodeshminus1, ind;
    nodesonlastright = 0;
    height = ceil(log2(n+1)) - 1; //height of a n node tree
    maxnodeshminus1 = pow(2, height) - 1; //max number of nodes for height - 1

    if ( n - maxnodeshminus1 > pow(2, height-1)) {
        nodesonlastright = n - maxnodeshminus1 - pow(2, height-1);
    }
    ind = (int) (n - nodesonlastright - 1 - ((maxnodeshminus1 - 1)/2));
    
    return ind;
}

template <typename K, typename O, typename B, typename C>
void
BinarySearchTree<K,O,B,C>::toCompleteBSTHelper(int start, int end, Node * & ptr, std::vector<Node *> & sn) 
{
    if (start <= end) {
        int r = findRoot(end - start + 1);
        ptr = sn[start + r];
        ptr->left = NULL;
        ptr->right = NULL;

        toCompleteBSTHelper(start, start + r - 1, ptr->left, sn);
        toCompleteBSTHelper(start + r + 1, end, ptr->right, sn);

        ptr->height = 1 + max(height(ptr->left), height(ptr->right));

        ptr->subsize = 1 + subsize(ptr->left) + subsize(ptr->right);
        
        
    }
    
}

template <typename K, typename O, typename B, typename C>
void
BinarySearchTree<K,O,B,C>::insertHelper(const K & k, const O & x, Node * & ptr)
{
    if ( ptr == NULL ){
        ptr = new Node(k, x, NULL, NULL, 0, 0);
        numNodes++;
    } else {
        if (isLessThan(k, ptr->key)) {
            insertHelper(k, x, ptr->left);
        } else if (isLessThan(ptr->key, k)) {
            insertHelper(k, x, ptr->right);
        } else {
            ptr->data = x;
        }
    }
    
    ptr->height = 1 + max(height(ptr->left), height(ptr->right));
    ptr->subsize = 1 + subsize(ptr->left) + subsize(ptr->right);
    
    if (ptr->subsize > 1) {
        if (!isBalanced(ptr->height, log2(ptr->subsize))) {
            std::vector<Node*> sortedNodes;
            fillingTheVector(sortedNodes, ptr);
            int vectorsize = sortedNodes.size();
            toCompleteBSTHelper(0, vectorsize-1, ptr, sortedNodes);
        }
    }
    
}


template <typename K, typename O, typename B, typename C>
void
BinarySearchTree<K,O,B,C>::removeHelper(Node * & ptr, const K & k, Node * & min, int last)
{
    if ( ptr == NULL ){
        return;
    } else {
        if (isLessThan(k, ptr->key)) {
            removeHelper(ptr->left, k, min, 0);
            ptr->subsize-=1;
        } else if (isLessThan(ptr->key, k)) {
            removeHelper(ptr->right, k, min, 0);
            ptr->subsize-=1;
        } else {
            if (ptr->left == NULL && ptr->right == NULL) {
                ptr = NULL;
            } else if (ptr->left == NULL && ptr->right != NULL) {
                ptr = ptr->right;
            } else if (ptr->left != NULL && ptr->right == NULL) {
                ptr = ptr->left;
            } else if (ptr->left && ptr->right) {
                Node * t = getMin(ptr->right);
                removeHelper(ptr->right, t->key, min, 0);
                t->left = ptr->left;
                t->right = ptr->right;
                t->subsize = ptr->subsize - 1;
                ptr = t;
            }
        }
    }
    if (ptr) {
        ptr->height = 1 + max(height(ptr->left), height(ptr->right));
        ptr->subsize = 1 + subsize(ptr->left) + subsize(ptr->right);
        if (ptr->subsize > 1) {
            if (!isBalanced(ptr->height, log2(ptr->subsize))) {
                std::vector<Node*> sortedNodes;
                fillingTheVector(sortedNodes, ptr);
                int vectorsize = sortedNodes.size();
                toCompleteBSTHelper(0, vectorsize-1, ptr, sortedNodes);
            }
        }
    }
}

    
template <typename K, typename O, typename B, typename C>
typename BinarySearchTree<K,O,B,C>::Node *
BinarySearchTree<K,O,B,C>::getMin(Node * & r) {

    if (r->left == NULL) {
        return r;
    } else {
        getMin(r->left);
    }
}

template <typename K, typename O, typename B, typename C>
void 
BinarySearchTree<K,O,B,C>::findHelper(Node * ptr, const K & lower, const K & upper, std::list<Node *> & list) const{
    if (ptr == NULL) {
        return;
    } else {
        if (isLessThan(upper, ptr->key)) {
            findHelper(ptr->left, lower, upper, list);
        } else if (isLessThan(ptr->key, lower)) {
            findHelper(ptr->right, lower, upper, list);
        } else {
            findHelper(ptr->left, lower, upper, list);
            if (!isLessThan(upper, ptr->key) && !isLessThan(ptr->key ,lower)) {
                list.push_back(ptr);
            }
            findHelper(ptr->right, lower, upper, list);

        }
    }
    
}
  

// DO NOT CHANGE
template <typename K, typename O, typename B, typename C>
size_t
BinarySearchTree<K,O,B,C>::size() const
{
  return numNodes;
}


// DO NOT CHANGE
template <typename K, typename O, typename B, typename C>
bool
BinarySearchTree<K,O,B,C>::empty() const
{
  return numNodes == 0;
}


// DO NOT CHANGE
template <typename K, typename O, typename B, typename C>
void
BinarySearchTree<K,O,B,C>::makeEmpty(Node * & t)
{
  if (t != NULL)
  {
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;

    --numNodes;
  }
  
  t = NULL;
}


// DO NOT CHANGE
template <typename K, typename O, typename B, typename C>
BinarySearchTree<K,O,B,C>::~BinarySearchTree()
{
  makeEmpty(root);
}


// DO NOT CHANGE
template <typename K, typename O, typename B, typename C>
void
BinarySearchTree<K,O,B,C>::print(std::ostream & out) const
{
  print(root, out);
  out << '\n';
}


// DO NOT CHANGE
template <typename K, typename O, typename B, typename C>
void
BinarySearchTree<K,O,B,C>::print(Node * t, std::ostream & out) const
{
  if (t != NULL && t->left != NULL) 
  {
    out << '[';
    print( t->left, out );
  }
  else if (t != NULL && t->left == NULL && t->right != NULL)
  {
    out << "[";
  }

  if (t != NULL)
  {
    if (t->left == NULL && t->right == NULL)
    {
      out << '(' << (t->key) << ')';
    }
    else if (t->left != NULL || t->right != NULL)
    {
      out << '{' << (t->key) << ",H" << t->height << ",S" << t->subsize << '}';
    }
  }
  
  if (t != NULL && t->right != NULL)
  {
    print( t->right, out );
    out << ']';
  }
  else if (t != NULL && t->left != NULL && t->right == NULL)
  {
    out << "]";
  }
}


// do not change
template <typename K, typename O, typename B, typename C>
template <typename T>
const T &
BinarySearchTree<K,O,B,C>::max(const T & el1, const T & el2)
{
  return el1 > el2 ? el1 : el2;
}

