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
        throw std::out_of_range("No such position.");
    }

    if(position < size/2){
        Node *current{head};
        for(int i = 1; i < position; i++){
            current = current->next;
        }
        deleteNode(current);
    }else{
        Node *current{tail};
        for (int i = 0; i < size - position; ++i) {
            current = current->previous;
        }
        deleteNode(current);
    }
}

bool LinkedList::findAndRemove(int data) {
    if (size == 0){
        throw std::out_of_range("Can't delete from empty list.");
    }

    bool hasDone{false};

    Node *current{head};
    Node *backup{nullptr};
    for (int i = 0; i < size; ++i) {
        backup = current;
        if(current->data == data){
            deleteNode(current);
            if (!hasDone)   hasDone = true;
        }
        current = backup->next;
    }

    current = nullptr;
    backup = nullptr;
    delete current;
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
        throw std::out_of_range("List is empty.");
    }

    int data{head->data};
    remove(1);
    return data;
}

int LinkedList::popAndGetBack() {
    if (size == 0){
        throw std::out_of_range("List is empty.");
    }

    int data{tail->data};
    remove(size);
    return data;
}

int LinkedList::getFront() {
    if (size == 0){
        throw std::out_of_range("List is empty.");
    }

    return head->data;
}

int LinkedList::getBack() {
    if (size == 0){
        throw std::out_of_range("List is empty.");
    }

    return tail->data;
}

int LinkedList::getSize() const {
    return size;
}

int LinkedList::max() {
    if (size == 0){
        throw std::out_of_range("List is empty.");
    }

    int currentMax{head->data};
    Node *current{head};
    for (int i = 0; i < size; ++i) {
        if(current->data > currentMax)
            currentMax = current->data;
        current = current->next;
    }
    current = nullptr;
    delete current;

    return currentMax;
}

int LinkedList::min() {

    if (size == 0){
        throw std::out_of_range("List is empty.");
    }

    int currentMin{head->data};
    Node *current{head};
    for (int i = 0; i < size; ++i) {
        if(current->data < currentMin)
            currentMin = current->data;
        current = current->next;
    }
    current = nullptr;
    delete current;

    return currentMin;
}

unsigned int LinkedList::count(int data) {
    unsigned int recurrence{0};

    Node *current{head};
    for (int i = 0; i < size; ++i) {
        if(current->data == data){
            recurrence++;
        }
        current = current->next;
    }

    current = nullptr;
    delete current;

    return recurrence;
}

void LinkedList::sort() {

}

void LinkedList::display() {

    if(head == nullptr && tail == nullptr){
        std::cout<<"The List is empty"<<std::endl;
        return;
    }

    Node *current{head};
    std::cout<<"------------The List------------"<<std::endl;
    std::cout << current->data << "\n";
    while (current != tail){
        current = current->next;
        std::cout << current->data << "\n";
    }
    std::cout<<"------------The end!------------"<<std::endl;

    current = nullptr;
    delete current;
}


LinkedList::~LinkedList() {
    if(size == 0){
        delete head;
        delete tail;
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

    delete head;
    delete tail;
}

void LinkedList::deleteNode(Node *node) {
    if (size == 0){
        throw std::out_of_range("Can't delete from empty list.");
    }
    if (!node){
        throw std::invalid_argument("Can't delete null pointer.");
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
