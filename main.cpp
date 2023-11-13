#include "NumberList.cpp"

int main(){
    NumberList list;

    list.appendNode(0);
    list.appendNode(1);
    list.appendNode(2);
    list.appendNode(3);
    list.appendNode(4);

    NumberList list2 = list; // Test copy constructor

    list2.appendNode(7);  // Append to copied list

    std::cout << "Contents of list: " << std::endl;
    list.displayList(); // Test if list and list2 are different
    std::cout << "Contents of list2(should be different from list): " << std::endl;
    list2.displayList();

    std::cout << "\nSearch list: " << list.searchList(2) << std::endl; // Should print '2'
    
    std::cout << "\nReversed list2:\n";
    list2.reverseList();
    list2.displayList();

    list.positionInsert(3, 15); // Within range, should be 3rd in list
    list.positionInsert(100, 100); // Outside of range, should be at end
    std::cout << "\nlist with inserted nodes:\n";
    list.displayList();

    list.positionRemove(2);  // Remove 2nd position
    std::cout << "\nlist after removing 2nd node\n";
    list.displayList();

    return 0;
}