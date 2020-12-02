//
// Created by Anik on 11/25/2020.
//

#ifndef DOUBLY_LINKED_LIST_LINKEDLIST_H
#define DOUBLY_LINKED_LIST_LINKEDLIST_H


struct Node{
    Node *previous;
    Node *next;
    int data;
};


class LinkedList {
private:
    Node *head = nullptr;
    Node *tail = nullptr;
public:
    LinkedList();
    LinkedList(LinkedList &obj);
    LinkedList(int *start,const int *end);

    virtual ~LinkedList();

    int &at(int index);
    void pushBack(int data);
    void pushFront(int data);
    void insert(int data, unsigned int position);

    void remove(int position);
    void findAndRemove(int data);
    void popFront();
    void popBack();
    int popAndGetFront();
    int popAndGetBack();
    int getFront();
    int getBack();

    int size();
    int max();
    int min();

    void search(int data);
    void sort();

    void display();

private:
    void build();
};


#endif //DOUBLY_LINKED_LIST_LINKEDLIST_H
