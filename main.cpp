#include <iostream>
#include "LinkedList.h"
#include <iterator>

int main() {

    int n{10};
    double proxy{0};
    double array[] = {1.0050,20.350,3.302,40.254,5.90,1.2,0.08,.3,0.000001,6.5};

//    LinkedList<double> myList;
    LinkedList<double> myList(array,array+n);
//    LinkedList otherList(myList);
//    otherList.display();
//
//    myList.insert(69,4);
//    myList.atNext() += 50;
//    std::cout << myList.atNext() << std::endl;
//    myList.atPrevious() += 50;
//    std::cout << myList.atPrevious() << std::endl;
//    myList.pointAt(3);
//    std::cout << myList.atNext() << std::endl;
//
//    myList.getCurrentData() = 1000;
//    std::cout << myList.getCurrentData() << std::endl;
//
//    if (myList.isSorted()){
//        std::cout << "List is sorted" << std::endl;
//    } else{
//        std::cout << "List is NOT sorted" << std::endl;
//    }
//
//    myList.sort();
//
//    if (myList.isSorted()){
//        std::cout << "List is sorted" << std::endl;
//    } else{
//        std::cout << "List is NOT sorted" << std::endl;
//    }
//
//    myList.display();
//
//    myList.remove(4);
//    myList.display();
//
//    std::cout << myList.findAndRemove(.08) << std::endl;
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
//
//
//    myList.at(4) += 2;
//    std::cout<<myList.at(4)<<std::endl;
//
//    for(int i = 0; i < n; i++){
//        std::cin >> proxy;
//        myList.pushFront(proxy);
//    }

    myList.display();

    return 0;
}
