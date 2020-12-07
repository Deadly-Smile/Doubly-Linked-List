//
// Created by Anik on 11/25/2020.
//

#include <climits>
#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
    size = 0;
}

LinkedList::LinkedList(LinkedList &object) {

    size = object.getSize();
    for(int i = 1; i <= size; i++){
        pushBack(object.at(i));
    }
}

LinkedList::LinkedList(int *start,const int *end) {
    size = 0;
    int *newCurrent = start;
    while (newCurrent != end){
        pushBack(*newCurrent);
        newCurrent++;
        size++;
    }
    newCurrent = nullptr;
    delete newCurrent;
}

int& LinkedList::at(int index) {
    if (size < index || index <= 0){
        throw std::out_of_range("No such position.");
    }

    if (size/2 > index){
        Node *newCurrent{head};
        for(int i = 1; i < index; i++){
            newCurrent = newCurrent->next;
        }
        int *data{&newCurrent->data};

        newCurrent = nullptr;
        delete newCurrent;

        return *data;
    }else{
        Node *newCurrent{tail};
        for(int i = size; i > index; i--){
            newCurrent = newCurrent->previous;
        }
        int *data{&newCurrent->data};

        newCurrent = nullptr;
        delete newCurrent;

        return *data;
    }
}

void LinkedList::pushBack(int data) {
    Node *newCurrent = new Node;
    newCurrent->next = nullptr;
    newCurrent->data = data;

    if(size == 0){
        newCurrent->previous = nullptr;

        head = newCurrent;
        tail = newCurrent;
    }else{
        newCurrent->previous = tail;
        tail->next = newCurrent;
        tail = newCurrent;
    }

    newCurrent = nullptr;
    delete newCurrent;
}

void LinkedList::pushFront(int data) {
    Node *newCurrent = new Node;
    newCurrent->previous = nullptr;
    newCurrent->data = data;

    if(size == 0){
        newCurrent->next = nullptr;

        head = newCurrent;
        tail = newCurrent;
    }else{
        newCurrent->next = head;
        head->previous = newCurrent;
        head = newCurrent;
    }

    newCurrent = nullptr;
    delete newCurrent;
}

void LinkedList::insert(int data, unsigned int position) {

    if(size < position + 1){
        throw std::out_of_range("No such position.");
    }

    if(position == 1){
        pushFront(data);
    } else if(size + 1 == position){
        pushBack(data);
    } else{
        Node *newCurrent = new Node;
        newCurrent->previous = nullptr;
        newCurrent->next = nullptr;
        newCurrent->data = data;

        Node *explorerOne{head};
        Node *explorerTwo{nullptr};
        for (int  i = 1; i < position; i++){
            explorerTwo = explorerOne;
            explorerOne = explorerOne->next;
        }
        newCurrent->next = explorerOne;
        newCurrent->previous = explorerTwo;

        explorerOne->previous = newCurrent;
        explorerTwo->next = newCurrent;

        newCurrent = nullptr;
        delete newCurrent;
        size++;
    }
}

void LinkedList::remove(unsigned int position) {

    if(position == 0 || position > size){
        throw std::out_of_range("No such position.");
    }

    Node *current{head};
    for(int i = 1; i < position; i++){
        current = current->next;
    }
    deleteNode(current);
}

void LinkedList::findAndRemove(int data) {

}

void LinkedList::popFront() {

}

void LinkedList::popBack() {

}

int LinkedList::popAndGetFront() {

}

int LinkedList::popAndGetBack() {

}

int LinkedList::getFront() {

}

int LinkedList::getBack() {

}

int LinkedList::getSize() const {
    return size;
}

int LinkedList::max() {

}

int LinkedList::min() {

}

void LinkedList::search(int data) {

}

void LinkedList::sort() {

}

void LinkedList::display() {

    if(head == nullptr && tail == nullptr){
        std::cout<<"The List is empty"<<std::endl;
        return;
    }

    Node *newCurrent{head};
    std::cout<<"------------The List------------"<<std::endl;
    std::cout<<newCurrent->data<<"\n";
    while (newCurrent != tail){
        newCurrent = newCurrent->next;
        std::cout<<newCurrent->data<<"\n";
    }
}


LinkedList::~LinkedList() {
    if(size == 0){
        delete head;
        delete tail;
        return;
    }

    Node *removingNode{head};

    while (removingNode)
    {
        auto newCurrent = removingNode;
        removingNode = removingNode->next;
        deleteNode(newCurrent);
    }

    head = nullptr;
    tail = nullptr;

    delete head;
    delete tail;
}

void LinkedList::deleteNode(Node *node) {
    if (size == 0)
        throw std::out_of_range("Can't delete from empty list.");
    if (!node)
        throw std::invalid_argument("Can't delete null pointer.");

    if (node == head && node == tail)
    {
        head = tail = nullptr;
        delete node;
    } else if (node == head)
    {
        head = node->next;
        node->next->previous = nullptr;
        delete node;
    }

    else if (node == tail)
    {
        tail = node->previous;
        node->previous->next = nullptr;
        delete node;
    } else{
        node->next->previous = node->previous;
        node->previous->next = node->next;
        delete node;
    }

    size--;
}








