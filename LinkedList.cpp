//
// Created by Anik on 11/25/2020.
//

#include <climits>
#include <iostream>
#include "LinkedList.h"
#define Throw(exception)    throw std::out_of_range(exception)


LinkedList::LinkedList() {
    size = 0;
    head = nullptr;
    tail = nullptr;
    current = head;
}

LinkedList::LinkedList(LinkedList &object) {        // Deep copy
    size = 0;
    head = nullptr;
    tail = nullptr;

    int objectSize = object.getSize();
    object.pointAtHead();
    for(int i = 1; i <= objectSize; i++){
        if (i == 1) pushBack(object.getFront());
        else        pushBack(object.atNext());
    }

    current = head;
}

LinkedList::LinkedList(int *start,const int *end) {

    size = 0;
    head = nullptr;
    tail = nullptr;

    int *newCurrent = start;
    while (newCurrent != end){
        pushBack(*newCurrent);
        newCurrent++;
    }
    newCurrent = nullptr;
    delete newCurrent;

    current = head;
}

int& LinkedList::at(unsigned int index) {
    if (size < index || index == 0){
        Throw("No such position.");
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

int &LinkedList::atPrevious() {
    if(current == nullptr){
        Throw("List is empty");
    }
    if (current->previous == nullptr){
        Throw("No such position.");
    }
    current = current->previous;
    return current->data;
}

int &LinkedList::atNext() {
    if(current == nullptr){
        Throw("List is empty");
    }
    if (current->next == nullptr){
        Throw("No such position.");
    }
    current = current->next;
    return current->data;
}

void LinkedList::pointAt(unsigned int position) {
    if (size < position || position == 0){
        Throw("No such position.");
    }
    if(position == 1)   pointAtHead();
    if (position == size)   pointAtTail();

    if(position < size/2){
        Node *newCurrent{head};
        for (int i = 1; i < position; ++i) {
            newCurrent = newCurrent->next;
        }
        current = newCurrent;
        newCurrent = nullptr;
        delete newCurrent;
    }else{
        Node *newCurrent{tail};
        for (int i = 0; i < size - position; ++i) {
            newCurrent = newCurrent->previous;
        }
        current = newCurrent;
        newCurrent = nullptr;
        delete newCurrent;
    }
}

void LinkedList::pointAtHead() {
    current = head;
}

void LinkedList::pointAtTail() {
    current = tail;
}


void LinkedList::pushBack(int data) {
    Node *newCurrent = new Node;
    newCurrent->next = nullptr;
    newCurrent->data = data;

    if(size == 0){
        newCurrent->previous = nullptr;

        head = newCurrent;
        tail = newCurrent;
        current = head;
    }else{
        newCurrent->previous = tail;
        tail->next = newCurrent;
        tail = newCurrent;
    }
    size++;
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
        current = head;
    }else{
        newCurrent->next = head;
        head->previous = newCurrent;
        head = newCurrent;
    }
    size++;
    newCurrent = nullptr;
    delete newCurrent;
}

void LinkedList::insert(int data, unsigned int position) {

    if(size < position + 1){
        Throw("No such position.");
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

        explorerOne = nullptr;
        delete explorerOne;
        explorerTwo = nullptr;
        delete explorerTwo;
        newCurrent = nullptr;
        delete newCurrent;

        size++;
    }
}

void LinkedList::remove(unsigned int position) {

    if(position == 0 || position > size){
        Throw("No such position.");
    }

    if(position < size/2){
        Node *newCurrent{head};
        for(int i = 1; i < position; i++){
            newCurrent = newCurrent->next;
        }
        deleteNode(newCurrent);
    }else{
        Node *newCurrent{tail};
        for (int i = 0; i < size - position; ++i) {
            newCurrent = newCurrent->previous;
        }
        deleteNode(newCurrent);
    }
}

bool LinkedList::findAndRemove(int data) {
    if (size == 0){
        Throw("Can't delete from empty list.");
    }

    bool hasDone{false};

    Node *newCurrent{head};
    Node *backup{nullptr};
    for (int i = 0; i < size; ++i) {
        backup = newCurrent;
        if(newCurrent->data == data){
            deleteNode(newCurrent);
            if (!hasDone)   hasDone = true;
        }
        newCurrent = backup->next;
    }

    newCurrent = nullptr;
    backup = nullptr;
    delete newCurrent;
    delete backup;

    return hasDone;
}

void LinkedList::popFront() {
    remove(1);
}

void LinkedList::popBack() {
    remove(size);
}

int LinkedList::popAndGetFront() {
    if (size == 0){
        Throw("List is empty.");
    }

    int data{head->data};
    remove(1);
    return data;
}

int LinkedList::popAndGetBack() {
    if (size == 0){
        Throw("List is empty.");
    }

    int data{tail->data};
    remove(size);
    return data;
}

int LinkedList::getFront() {
    if (size == 0){
        Throw("List is empty.");
    }

    return head->data;
}

int LinkedList::getBack() {
    if (size == 0){
        Throw("List is empty.");
    }

    return tail->data;
}

int LinkedList::getSize() const {
    return size;
}

Node *LinkedList::getCurrentPointer() {
    return current;
}

int LinkedList::max() {
    if (size == 0){
        Throw("List is empty.");
    }

    int currentMax{head->data};
    Node *newCurrent{head};
    for (int i = 0; i < size; ++i) {
        if(newCurrent->data > currentMax)
            currentMax = newCurrent->data;
        newCurrent = newCurrent->next;
    }
    newCurrent = nullptr;
    delete newCurrent;

    return currentMax;
}

int LinkedList::min() {

    if (size == 0){
        Throw("List is empty.");
    }

    int currentMin{head->data};
    Node *newCurrent{head};
    for (int i = 0; i < size; ++i) {
        if(newCurrent->data < currentMin)
            currentMin = newCurrent->data;
        newCurrent = newCurrent->next;
    }
    newCurrent = nullptr;
    delete newCurrent;

    return currentMin;
}

unsigned int LinkedList::count(int data) {
    unsigned int recurrence{0};

    Node *newCurrent{head};
    for (int i = 0; i < size; ++i) {
        if(newCurrent->data == data){
            recurrence++;
        }
        newCurrent = newCurrent->next;
    }

    newCurrent = nullptr;
    delete newCurrent;

    return recurrence;
}

void LinkedList::sort() {

}

void LinkedList::display() {

    if(getSize() == 0){
        std::cout<<"The List is empty"<<std::endl;
        return;
    }

    Node *newCurrent{head};
    std::cout<<"------------The List------------"<<std::endl;
    std::cout << newCurrent->data << "\n";
    while (newCurrent != tail){
        newCurrent = newCurrent->next;
        std::cout << newCurrent->data << "\n";
    }
    std::cout<<"------------The end!------------"<<std::endl;

    newCurrent = nullptr;
    delete newCurrent;
}


LinkedList::~LinkedList() {
    if(size == 0){
        delete head;
        delete tail;
        delete current;
        return;
    }

    Node *removingNode{head};

    while (removingNode) {
        auto newCurrent = removingNode;
        removingNode = removingNode->next;
        deleteNode(newCurrent);
    }

    head = nullptr;
    tail = nullptr;
    current = nullptr;

    delete head;
    delete tail;
    delete current;
}

void LinkedList::deleteNode(Node *node) {
    if (size == 0){
        Throw("Can't delete from empty list.");
    }
    if (!node){
        Throw("Can't delete null pointer.");
    }

    if (node == head && node == tail) {
        head = tail = nullptr;
        delete node;
    } else if (node == head) {
        head = node->next;
        node->next->previous = nullptr;
        delete node;
    } else if (node == tail) {
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




