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
    for(int i = 1; i <= objectSize; i++){
        pushBack(object.at(i));
    }
}

LinkedList::LinkedList(int *start,const int *end) {

    int *newCurrent = start;
    while (newCurrent != end){
        pushBack(*newCurrent);
        newCurrent++;
    }
    newCurrent = nullptr;
    delete newCurrent;

}

int& LinkedList::at(int index) {

    int length{size()};

    if (length < index || index <= 0){
        std::cerr << "No such element, index rang is 1 - " << length << std::endl;
        int *nullPointer{nullptr};
        return *nullPointer;
    }

    Node *newCurrent{head};
    for(int i = 1; i < index; i++){
        newCurrent = newCurrent->next;
    }
    int *data{&newCurrent->data};

    newCurrent = nullptr;
    delete newCurrent;

    return *data;


}

void LinkedList::pushBack(int data) {
    Node *newCurrent = new Node;
    newCurrent->next = nullptr;
    newCurrent->data = data;

    if(size() == 0){
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

    if(size() == 0){
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
        Node *newCurrent = new Node;
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

    if(head == nullptr && tail == nullptr){
        return 0;
    }

    if (head == tail){
        return 1;
    }

    int count{1};
    Node *newCurrent{head};
    while (newCurrent != tail){
        count++;
        newCurrent = newCurrent->next;
    }

    newCurrent = nullptr;
    delete newCurrent;
    return count;
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
    }

    explorer->next = nullptr;
    explorer->previous = nullptr;
    free(explorer);

    delete head;
    delete tail;

    explorer = nullptr;
    delete explorer;
    delete removingNode;
}





