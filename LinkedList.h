//
// Created by Anik on 11/25/2020.
//

#ifndef DOUBLY_LINKED_LIST_LINKEDLIST_H
#define DOUBLY_LINKED_LIST_LINKEDLIST_H


struct Node{
    Node *previous;
    Node *Next;
    int data;
};


class LinkedList {
private:
    Node *head;
    Node *tail;
public:
    LinkedList();
    LinkedList(const LinkedList &obj);
    LinkedList(int array[]);

    int &at(int index);

    void pushBack(int data);
    void pushFront(int data);
    void insert(int data, int position);

    void remove(int position);
    void findAndRemove(int data);
    void popFront();
    void popBack();

    void size();
    void max();
    void min();

    void search(int data);
    void sort();

    void display();

private:
    void build();
};


#endif //DOUBLY_LINKED_LIST_LINKEDLIST_H
