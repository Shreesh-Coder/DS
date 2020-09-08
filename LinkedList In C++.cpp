// LinkedList In C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
#include <string>
template <typename T>
class Node final {
public:
    T val;
    Node* next;
};

template <typename T>
class LinkedList final {
    Node<T> *start;
    int totalNodes = 0;
public:
    LinkedList();
    bool isEmpty() const;
    void addNode(T val, int position = -1);
    T deleteNode(int postion);
    void display() const;
    int getLength() const ;
    ~LinkedList();
};

template<typename T>
LinkedList<T>::LinkedList() {
    start = nullptr;
}

template<typename T>
void LinkedList<T>::addNode(T val,int position) {
   
    assert((position <= this->totalNodes || position <= -1) && position != 0
        && "Value of position is not in range.");
    
    Node<T>* newNode = new Node<T>;
    newNode->next = nullptr;
    newNode->val = val;
    
    
    if (isEmpty()) {
        start = newNode;
        this->totalNodes++;
        return;
    }
    if (position == 1) {
        if (this->totalNodes > 1) {
            newNode->next = start;
            start = newNode;
            this->totalNodes++;
            return;
        }
        newNode->next = start;
        start = newNode;
        this->totalNodes++;
        return;
    }
    int count = 1;
    Node<T> *ptr = new Node<T>;
    ptr = start;
    Node<T>* temp = nullptr;
    
    while (ptr != nullptr && position == -1) {
        temp = ptr;
        ptr = ptr->next;
    }

    while (count < position) {
        temp = ptr;
        ptr = ptr->next;
        count++;
    }
    
    newNode->next = ptr;
    temp->next = newNode;
   
    this->totalNodes++;
}

template<typename T>
bool LinkedList<T>::isEmpty() const{
    return start == nullptr;
}

template<typename T>
T LinkedList<T>::deleteNode(int position) {
    assert((position <= this->totalNodes || position < -1) && position != 0
        && "Value of position is not in range.");
    assert(!isEmpty() && "Linked List got empty.");
    
    Node<T>* ptr = start;
    Node<T>* temp = nullptr;
    int count = 1;
    this->totalNodes--;
    
    if (position == 1) {
        start = start->next;
        T item = ptr->val;
        delete ptr;
        return  item;
    }

    while (count < position) {
        temp = ptr;
        ptr = ptr->next;
        count++;
    }
   
    temp->next = ptr->next;
   
    T item = ptr->val;
    delete ptr;

    return  item;
}

template<typename T>
void LinkedList<T>::display() const {
    Node<T>* ptr = start;
    
    std::cout << std::endl;
    
    while (ptr != nullptr) {
        std::cout << ptr->val << " ";
        ptr = ptr->next;
    }
}

template<typename T>
int LinkedList<T>::getLength() const
{
    return totalNodes;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* ptr = start;
    Node<T>* temp = nullptr;
    while (ptr != nullptr) {
        temp = ptr;
        ptr = ptr->next;
        delete(temp);
    }
}

int main()
{
    LinkedList<int> list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3, 1);
    list.addNode(4, 3);

    list.deleteNode(1);
    list.deleteNode(2);

    list.display();

    std::cout << std::endl << list.getLength();

}
