#include <iostream>
#include "LinkedList.h"
#include <iterator>

int main() {

    int n{10},proxy{0};
    int array[] = {10,200,3,40,590,12,8,3,1,65};

//    LinkedList myList;
    LinkedList myList(array,array+n);
//    LinkedList otherList(myList);
//    otherList.display();

//    myList.insert(69,4);
//    myList.atNext() += 50;
//    std::cout << myList.atNext() << std::endl;
//    myList.atPrevious() += 50;
//    std::cout << myList.atPrevious() << std::endl;
//    myList.pointAt(3);
//    std::cout << myList.atNext() << std::endl;
//
//    myList.getCurrentPointer()->data = 1000;
//    std::cout << myList.getCurrentPointer()->data << std::endl;

    if (myList.isSorted()){
        std::cout << "List is sorted" << std::endl;
    } else{
        std::cout << "List is NOT sorted" << std::endl;
    }

    myList.sort();

    if (myList.isSorted()){
        std::cout << "List is sorted" << std::endl;
    } else{
        std::cout << "List is NOT sorted" << std::endl;
    }

//    myList.display();
//
//    myList.remove(4);
//    myList.display();
//
//    std::cout << myList.findAndRemove(35) << std::endl;
//    std::cout << myList.count(50) << std::endl;
//
//    std::cout << myList.min() << std::endl;
//    std::cout << myList.max() << std::endl;
//
//    std::cout << myList.getFront() << std::endl;
//    std::cout << myList.getBack() << std::endl;
//    std::cout << myList.popAndGetFront() << std::endl;
//    std::cout << myList.popAndGetBack() << std::endl;
//
//    myList.display();
//    myList.popFront();
//    myList.popBack();
//    myList.popBack();
//
//    std::cout << myList.getSize() << std::endl;


//    myList.at(4) += 2;
//    std::cout<<myList.at(4)<<std::endl;

//    for(int i = 0; i < n; i++){
//        std::cin >> proxy;
//        myList.pushFront(proxy);
//    }

    myList.display();

    return 0;
}
