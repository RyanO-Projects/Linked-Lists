#include <iostream>
#include "ListTemplate.h"

int main() {
    ListTemplate<int> listerine;

    listerine.appendNode(0);
    listerine.appendNode(1);
    listerine.appendNode(2);

    listerine.reverseList();
    std::cout << "Testing listerine after appending and reversing:\n";
    listerine.displayList();

    ListTemplate<int> colgate = listerine;
    colgate.positionInsert(2, 100);
    colgate.positionRemove(0);
    std::cout << "Testing searchList(0), should display '2':\n";
    std::cout << colgate.searchList(0) << "\n";
    std::cout << "Testing colgate after copying, inserting and removing:\n";
    colgate.displayList();
    return 0;
}