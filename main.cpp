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

    myList.remove(4);
    myList.display();

    std::cout << myList.findAndRemove(35) << std::endl;
    std::cout << myList.count(50) << std::endl;

    std::cout << myList.min() << std::endl;
    std::cout << myList.max() << std::endl;

    std::cout << myList.getFront() << std::endl;
    std::cout << myList.getBack() << std::endl;
    std::cout << myList.popAndGetFront() << std::endl;
    std::cout << myList.popAndGetBack() << std::endl;

    myList.display();
    myList.popFront();
    myList.popBack();

//    myList.at(4) += 2;
//    std::cout<<myList.at(4)<<std::endl;

//    for(int i = 0; i < n; i++){
//        std::cin >> proxy;
//        myList.pushFront(proxy);
//    }

    myList.display();

    return 0;
}
