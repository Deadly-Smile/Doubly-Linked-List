//
// Created by Anik on 11/25/2020.
//

#ifndef DOUBLY_LINKED_LIST_LINKEDLIST_H
#define DOUBLY_LINKED_LIST_LINKEDLIST_H


class Node{
public:
    Node *previous;
    Node *next;
    int data;
    bool operator < (Node *node) const{
        return this->data < node->data;
    }
};


class LinkedList {
private:
    Node *head;
    Node *tail;
    Node *current;
    int size;
public:
    LinkedList();
    LinkedList(LinkedList &obj);
    LinkedList(int *start,const int *end);

    virtual ~LinkedList();

    int &at(unsigned int index);
    int &atNext();
    int &atPrevious();
    void pointAt(unsigned int position);
    void pointAtHead();
    void pointAtTail();

    void pushBack(int data);
    void pushFront(int data);
    void insert(int data, unsigned int position);

    void remove(unsigned int position);
    bool findAndRemove(int data);
    void popFront();
    void popBack();
    int popAndGetFront();
    int popAndGetBack();
    int getFront();
    int getBack();

    [[nodiscard]] int getSize() const;
    Node *getCurrentPointer();

    int max();
    int min();

    unsigned int count(int data);
    void sort();
    bool isSorted();

    void display();

private:
    void deleteNode(Node *node);
    Node *getHead();
    Node *getTail();
};


#endif //DOUBLY_LINKED_LIST_LINKEDLIST_H
