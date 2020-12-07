#include <iostream>
#include "LinkedList.h"

int main() {

    int n{5},proxy{0};
    int array[5] = {10,20,30,40,50};

//    LinkedList myList;
    LinkedList myList(array,array+n);
//    LinkedList otherList(myList);
//    otherList.display();

    myList.insert(69,4);
    myList.display();

    myList.remove(2);


//    myList.at(4) += 2;
//    std::cout<<myList.at(4)<<std::endl;

//    for(int i = 0; i < n; i++){
//        std::cin >> proxy;
//        myList.pushFront(proxy);
//    }

    myList.display();

    return 0;
}
