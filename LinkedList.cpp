//
// Created by Anik on 11/25/2020.
//

#include <climits>
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

}

void LinkedList::pushFront(int data) {

}

void LinkedList::insert(int data, int position) {

}

void LinkedList::remove(int position) {

}

void LinkedList::findAndRemove(int data) {

}

void LinkedList::popFront() {

}

void LinkedList::popBack() {

}

void LinkedList::popAndGetFront() {

}

void LinkedList::popAndGetBack() {

}

void LinkedList::getFront() {

}

void LinkedList::getBack() {

}

void LinkedList::size() {

}

void LinkedList::max() {

}

void LinkedList::min() {

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

}





