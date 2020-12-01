#include <iostream>
#include "LinkedList.h"
#include <vector>

int main() {

    int n{5},proxy{0};
    int array[5] = {10,20,30,40,50};
    LinkedList myList(array,n);
//    for(int i = 0; i < n; i++){
//        std::cin >> proxy;
//        myList.pushFront(proxy);
//    }

    myList.display();

    return 0;
}
