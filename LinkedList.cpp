//
// Created by Anik on 11/25/2020.
//

#include <climits>
#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {

}

LinkedList::LinkedList(LinkedList &object) {

    int objectSize{object.size()};
    for(int i = 0; i <= objectSize; i++){
        pushBack(object.atNext());
    }
}

LinkedList::LinkedList(const int array[]) {

    int arraySize = sizeof(array)/sizeof(array[0]);
    for(int i = 0; i <= arraySize; i++){
        pushBack(array[i]);
    }

}

int &LinkedList::at(int index) {
    int length{size()};
    if(length <= index){
        int data{INT_MIN};
        return data;
    }else if (length/2 >= index){
        Node *newCurrent{tail};
        for(int i = length - 1; i >= index; i--){
            newCurrent = newCurrent->previous;
        }
        int data{newCurrent->data};

        newCurrent = nullptr;
        delete newCurrent;

        return data;
    }else{
        Node *newCurrent{head};
        for(int i = 0; i < index; i++){
            newCurrent = newCurrent->next;
        }
        int data{newCurrent->data};

        newCurrent = nullptr;
        delete newCurrent;

        return data;
    }


}

int &LinkedList::atNext() {

    if (current->next == nullptr){
        int data{INT_MIN};
        return data;
    }
    Node *newCurrent{current->next};
    current = current->next;

    int data{newCurrent->data};

    newCurrent = nullptr;
    delete newCurrent;

    return data;
}

int &LinkedList::atPrevious() {

    if (current->previous == nullptr){
        int data{INT_MIN};
        return data;
    }

    Node *newCurrent{current->previous};
    current = current->previous;

    int data{newCurrent->data};

    newCurrent = nullptr;
    delete newCurrent;

    return data;
}

void LinkedList::pushBack(int data) {
    Node *newCurrent{nullptr};
    newCurrent->next = nullptr;
    newCurrent->data = data;

    if(size() == 0){
        newCurrent->previous = nullptr;

        head = newCurrent;
        tail = newCurrent;
    }else if(size() == 1){
        newCurrent->previous = head;
        tail = newCurrent;
    }else{
        newCurrent->previous = tail;
        tail = newCurrent;
    }

    newCurrent = nullptr;
    delete newCurrent;
}

void LinkedList::pushFront(int data) {
    Node *newCurrent{nullptr};
    newCurrent->previous = nullptr;
    newCurrent->data = data;

    if(size() == 0){
        newCurrent->next = nullptr;

        head = newCurrent;
        tail = newCurrent;
    }else if(size() == 1){
        newCurrent->next = tail;
        head = newCurrent;
    }else{
        newCurrent->next = head;
        head = newCurrent;
    }

    newCurrent = nullptr;
    delete newCurrent;
}

void LinkedList::insert(int data, unsigned int position) {

    int length{size()};

    if(length < position){
        std::cout<<"No such position, operation failed"<<std::endl;
        return;
    }

    if(position == 0){
        pushFront(data);
    }
    else if(length == position){
        pushBack(data);
    }
    else{
        Node *newCurrent{nullptr};
        newCurrent->data = data;

        if(position < length/2){
            Node *explorerOne{head};
            Node *explorerTwo{nullptr};
            for (int  i = 1; i < position; i++){
                explorerTwo = explorerOne;
                explorerOne = explorerOne->next;
            }
            newCurrent->next = explorerOne;
            newCurrent->previous = explorerTwo;

            newCurrent = nullptr;
            delete newCurrent;
        }
        else{
            Node *explorerOne{tail->previous};
            Node *explorerTwo{tail};
            for (int  i = length; i >= length - position; i--){
                explorerTwo = explorerOne;
                explorerOne = explorerOne->previous;
            }
            newCurrent->previous = explorerOne;
            newCurrent->next = explorerTwo;

            newCurrent = nullptr;
            delete newCurrent;
        }
    }
}

void LinkedList::remove(int position) {

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

int LinkedList::size() {

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

}

void LinkedList::build() {

}

LinkedList::~LinkedList() {

    int length{size()};

    if(length == 0){
        delete head;
        delete tail;
        return;
    }

    Node *explorer{head};
    Node *removingNode{nullptr};

    for (int i = 0; i < length-1; i++){
        removingNode = explorer;
        explorer = explorer->next;
        removingNode->next = nullptr;
        removingNode->previous = nullptr;
        free(removingNode);

        removingNode = nullptr;
    }

    explorer->next = nullptr;
    explorer->previous = nullptr;
    free(explorer);

    delete head;
    delete tail;
}





