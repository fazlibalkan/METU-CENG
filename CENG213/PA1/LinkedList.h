#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <iostream>

#include "Node.h"

template<class T>
class LinkedList {
public: // DO NOT CHANGE THIS PART.
    LinkedList();
    LinkedList(const T arr[], int arrSize);
    LinkedList(const LinkedList<T> &obj);

    ~LinkedList();

    Node<T> *getFirstNode() const;
    Node<T> *getLastNode() const;
    Node<T> *getNode(const T &data) const;

    int getNumberOfNodes() const;
    bool isEmpty() const;
    bool contains(Node<T> *node) const;

    void insertAtTheHead(const T &data);
    void insertAtTheTail(const T &data);
    void insertSorted(const T &data);

    void removeNode(Node<T> *node);
    void removeNode(const T &data);
    void removeAllNodes();

    void print() const;

    T *toArray() const;

    LinkedList<T> &operator=(const LinkedList<T> &rhs);

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.

private: // DO NOT CHANGE THIS PART.
    Node<T> *head;
    Node<T> *tail;
};

template<class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

template<class T>
LinkedList<T>::LinkedList(const T arr[], int arrSize) {
    head = nullptr;
    Node<T> * current;

    for (int i = 0; i < arrSize ; i++) {
        if (head == nullptr) {
            head = new Node<T>();
            head->data = arr[i];
            current = head;
            tail = current;
        } else {
            current->next = new Node<T>(arr[i], nullptr, nullptr);
            current->next->prev = current;
            current = current->next;
            tail = current;
        }
    }
    
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &obj) {

    this->head = nullptr;
    Node<T> *current;
    Node<T> *current_obj = obj.head;
    
    if (obj.head == nullptr) {
        return;
    }
    while ( current_obj != nullptr ) {
        if (head == nullptr) {
            head = new Node<T>();
            head->data = current_obj->data;
            current = head;
            tail = current;
        } else {
            current->next = new Node<T>(current_obj->data, nullptr, nullptr);
            current->next->prev = current;
            current = current->next;
            tail = current;
        }
        
        current_obj = current_obj->next;
    }
    
}

template<class T>
LinkedList<T>::~LinkedList() {
    
    Node<T> * willbedeleted;
    while (head != nullptr) {
        willbedeleted = head;
        head = head->next;
        delete willbedeleted;
    }

}

template<class T>
Node<T> *LinkedList<T>::getFirstNode() const {
    return head;
}

template<class T>
Node<T> *LinkedList<T>::getLastNode() const {
    return tail;
}

template<class T>
Node<T> *LinkedList<T>::getNode(const T &data) const {
    Node<T> *current = head;
    while (current != nullptr) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

template<class T>
int LinkedList<T>::getNumberOfNodes() const {
    Node<T> * counting = head;
    int num = 0;
    while(counting != nullptr) {
        num++;
        counting = counting->next;
    }
    return num;
    
}

template<class T>
bool LinkedList<T>::isEmpty() const {
    if (head == nullptr) {
        return true;
    }
    return false;
    
}

template<class T>
bool LinkedList<T>::contains(Node<T> *node) const {
    Node<T> *current = head;
    while (current != nullptr) {
        if (current == node) {
            return true;
        }
        current = current->next;
    }

    return false;
    
}

template<class T>
void LinkedList<T>::insertAtTheHead(const T &data) {
    Node<T> *node = new Node<T>(data, nullptr, nullptr);
    if (head != nullptr) {
        head->prev = node;
        node->next = head;
    }
    
    head = node;
    if (tail == nullptr)
        tail = node;
    
}

template<class T>
void LinkedList<T>::insertAtTheTail(const T &data) {
    Node<T> *node = new Node<T>(data, nullptr, nullptr);
    
    if (head == nullptr) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    
}

template<class T>
void LinkedList<T>::insertSorted(const T &data) {
    Node<T> *node = new Node<T>(data, nullptr, nullptr);
    
    
    if (head == nullptr) {
        head = node;
        tail = node;
    } else if (head->data > node->data) {
        node->next = head;
        node->next->prev = node;
        head = node;
    } else {
        Node<T> *current = head;
        while (current->next != nullptr && current->next->data < node->data) {
            current = current->next;
        }
        
        //putting it as the last node
        if (current->next == nullptr) {
            current->next = node;
            node->prev = current;
            tail = node;
            return;
        }
        
        //....
        node->next = current->next;
        
        if(current->next != nullptr) {
            node->next->prev = node;
        }
        
        current->next = node;
        node->prev = current;
        
    }
    
    
    
}

template<class T>
void LinkedList<T>::removeNode(Node<T> *node) {

    Node<T> * current = head;
    if (head == nullptr) {
        return;
    }
    while (current != nullptr) {
        if (current == node) {
            if (current == head) {
                if (current == tail) {
                    head = nullptr;
                    tail = nullptr;
                    delete current;
                    return;
                }
                head = current->next;
                current->next->prev = nullptr;
                delete current;
                return;
            }
            if (current == tail) {
                tail = current->prev;
                current->prev->next = nullptr;
                delete current;
                return;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            return;
        }
        current = current->next;
    }

    
}

template<class T>
void LinkedList<T>::removeNode(const T &data) {
        Node<T> * current = head;
    if (head == nullptr) {
        return;
    }
    while (current != nullptr) {
        if (current->data == data) {
            if (current == head) {
                if (current == tail) {
                    head = nullptr;
                    tail = nullptr;
                    delete current;
                    return;
                }
                head = current->next;
                current->next->prev = nullptr;
                delete current;
                return;
            }
            if (current == tail) {
                tail = current->prev;
                current->prev->next = nullptr;
                delete current;
                return;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            return;
        }
        current = current->next;
    }
}

template<class T>
void LinkedList<T>::removeAllNodes() {
    Node<T> * current = head;
    if (head == nullptr) {
        return;
    }
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    tail = nullptr;
    
}

template<class T>
void LinkedList<T>::print() const {
    std::cout << "Printing the linked list ..." << std::endl;

    if (this->isEmpty()) {
        std::cout << "empty" << std::endl;
        return;
    }

    Node<T> *node = this->head;

    while (node) {
        std::cout << *node << std::endl;
        node = node->next;
    }
}

template<class T>
T *LinkedList<T>::toArray() const {
    T * arr;
    if (head == nullptr)
        return nullptr;

    int length = this->getNumberOfNodes();
    arr = new int [length];

    Node<T> *current = head;
    for (int i = 0; i < length; i++) {
        arr[i] = current->data;
        current = current->next;
    }
    return arr;
    
}

template<class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs) {
    
    (*this).removeAllNodes();
    this->head = nullptr;
    Node<T> *current;
    Node<T> *current_rhs = rhs.head;
    
    if (rhs.head == nullptr) {
        return *this;
    }
    while ( current_rhs != nullptr) {
        if (head == nullptr) {
            head = new Node<T>();
            head->data = current_rhs->data;
            current = head;
            tail = current;
        } else {
            current->next = new Node<T>(current_rhs->data, nullptr, nullptr);
            current->next->prev = current;
            current = current->next;
            tail = current;
        }
        
        current_rhs = current_rhs->next;
    }
    return *this;

}



#endif //LINKEDLIST_H
