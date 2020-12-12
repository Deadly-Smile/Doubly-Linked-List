//
// Created by Anik on 11/25/2020.
//

#ifndef DOUBLY_LINKED_LIST_LINKEDLIST_H
#define DOUBLY_LINKED_LIST_LINKEDLIST_H

#include <iostream>
#include <algorithm>
#define Throw(exception)    throw std::out_of_range(exception)

template<typename T>
struct Node{
    Node *previous;
    Node *next;
    T data;
};

template<typename T>
class LinkedList {
private:
    Node<T> *head;
    Node<T> *tail;
    Node<T> *current;
    int size;
public:
    LinkedList(){
        size = 0;
        head = nullptr;
        tail = nullptr;
        current = head;
    }

    LinkedList(LinkedList &object){     // Deep copy
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

    LinkedList(T *start,const T *end) {

        size = 0;
        head = nullptr;
        tail = nullptr;

        T *newCurrent = start;
        while (newCurrent != end){
            pushBack(*newCurrent);
            newCurrent++;
        }
        newCurrent = nullptr;
        delete newCurrent;

        current = head;
    }

    T &at(unsigned int index) {
        if (size < index || index == 0){
            Throw("No such position.");
        }

        if (size/2 > index){
            Node<T> *newCurrent{head};
            for(int i = 1; i < index; i++){
                newCurrent = newCurrent->next;
            }
            T *data{&newCurrent->data};

            newCurrent = nullptr;
            delete newCurrent;

            return *data;
        }else{
            Node<T> *newCurrent{tail};
            for(int i = size; i > index; i--){
                newCurrent = newCurrent->previous;
            }
            T *data{&newCurrent->data};

            newCurrent = nullptr;
            delete newCurrent;

            return *data;
        }
    }

    T &atNext(){
        if(current == nullptr){
            Throw("List is empty");
        }
        if (current->next == nullptr){
            Throw("No such position.");
        }
        current = current->next;
        return current->data;
    }

    T &atPrevious(){
        if(current == nullptr){
            Throw("List is empty");
        }
        if (current->previous == nullptr){
            Throw("No such position.");
        }
        current = current->previous;
        return current->data;
    }

    void pointAt(unsigned int position){
        if (size < position || position == 0){
            Throw("No such position.");
        }
        if(position == 1)   pointAtHead();
        if (position == size)   pointAtTail();

        if(position < size/2){
            Node<T> *newCurrent{head};
            for (int i = 1; i < position; ++i) {
                newCurrent = newCurrent->next;
            }
            current = newCurrent;
            newCurrent = nullptr;
            delete newCurrent;
        }else{
            Node<T> *newCurrent{tail};
            for (int i = 0; i < size - position; ++i) {
                newCurrent = newCurrent->previous;
            }
            current = newCurrent;
            newCurrent = nullptr;
            delete newCurrent;
        }
    }

    void pointAtHead(){
        current = head;
    }

    void pointAtTail(){
        current = tail;
    }

    void pushBack(T data){
        auto *newCurrent = new Node<T>;
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

    void pushFront(T data){
        auto *newCurrent = new Node<T>;
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

    void insert(T data, unsigned int position){
        if(size < position + 1){
            Throw("No such position.");
        }

        if(position == 1){
            pushFront(data);
        } else if(size + 1 == position){
            pushBack(data);
        } else{
            auto *newCurrent = new Node<T>;
            newCurrent->previous = nullptr;
            newCurrent->next = nullptr;
            newCurrent->data = data;

            Node<T> *explorerOne{head};
            Node<T> *explorerTwo{nullptr};
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

    void remove(unsigned int position){
        if(position == 0 || position > size){
            Throw("No such position.");
        }

        if(position < size/2){
            Node<T> *newCurrent{head};
            for(int i = 1; i < position; i++){
                newCurrent = newCurrent->next;
            }
            deleteNode(newCurrent);
        }else{
            Node<T> *newCurrent{tail};
            for (int i = 0; i < size - position; ++i) {
                newCurrent = newCurrent->previous;
            }
            deleteNode(newCurrent);
        }
    }

    bool findAndRemove(T data){
        if (size == 0){
            Throw("Can't delete from empty list.");
        }

        bool hasDone{false};

        Node<T> *newCurrent{head};
        Node<T> *backup{nullptr};
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

    void popFront(){
        remove(1);
    }

    void popBack(){
        remove(size);
    }

    int popAndGetFront(){
        if (size == 0){
            Throw("List is empty.");
        }

        T data{head->data};
        remove(1);
        return data;
    }

    int popAndGetBack(){
        if (size == 0){
            Throw("List is empty.");
        }

        T data{tail->data};
        remove(size);
        return data;
    }

    int getFront(){
        if (size == 0){
            Throw("List is empty.");
        }

        return head->data;
    }

    int getBack(){
        if (size == 0){
            Throw("List is empty.");
        }

        return tail->data;
    }

    [[nodiscard]] int getSize() const{
        return size;
    }

    T &getCurrentData(){
        return current->data;
    }

    T max(){
        if (size == 0){
            Throw("List is empty.");
        }

        T currentMax{head->data};
        Node<T> *newCurrent{head};
        for (int i = 0; i < size; ++i) {
            if(newCurrent->data > currentMax)
                currentMax = newCurrent->data;
            newCurrent = newCurrent->next;
        }
        newCurrent = nullptr;
        delete newCurrent;

        return currentMax;
    }

    T min(){
        if (size == 0){
            Throw("List is empty.");
        }

        T currentMin{head->data};
        Node<T> *newCurrent{head};
        for (int i = 0; i < size; ++i) {
            if(newCurrent->data < currentMin)
                currentMin = newCurrent->data;
            newCurrent = newCurrent->next;
        }
        newCurrent = nullptr;
        delete newCurrent;

        return currentMin;
    }

    unsigned int count(T data){
        unsigned int recurrence{0};

        Node<T> *newCurrent{head};
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

    void sort(){
        if(size == 0 || size == 1){
            return;
        }

        T arr[size];
        Node<T> *newCurrent{head};

        for (int i = 0; i < size; ++i) {
            arr[i] = newCurrent->data;
            newCurrent = newCurrent->next;
        }

        std::sort(arr,arr+size);
        newCurrent = head;

        for (int i = 0; i < size; ++i) {
            newCurrent->data = arr[i];
            newCurrent = newCurrent->next;
        }

        newCurrent = nullptr;
        delete newCurrent;
    }       // Maybe the worst algorithm

    bool isSorted(){
        if(size == 0 || size == 1){
            return true;
        }
        Node<T> *newCurrent{head};
        bool isOk{true};
        for (int i = 1; i < size && isOk; ++i) {
            if (newCurrent->data > newCurrent->next->data){
                isOk = false;
            }
            newCurrent = newCurrent->next;
        }

        newCurrent = nullptr;
        delete newCurrent;
        return isOk;
    }

    void display(){
        if(getSize() == 0){
            std::cout<<"The List is empty"<<std::endl;
            return;
        }

        Node<T> *newCurrent{head};
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

    virtual ~LinkedList(){
        if(size == 0){
            delete head;
            delete tail;
            delete current;
            return;
        }

        Node<T> *removingNode{head};

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

private:
    void deleteNode(Node<T> *node){
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

    Node<T> *getHead(){
        return head;
    }

    Node<T> *getTail(){
        return tail;
    }

    Node<T> *getCurrentPointer(){
        return current;
    }
};






#endif //DOUBLY_LINKED_LIST_LINKEDLIST_H
