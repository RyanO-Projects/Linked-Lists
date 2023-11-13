#include <iostream>
#include "NumberList.h"
using namespace std;

// Copy Constructor
NumberList::NumberList(const NumberList &obj){
    ListNode *currentNode = nullptr;
    ListNode *nextNode = nullptr;

    if(obj.head == nullptr)
        head = nullptr;
    
    else {
        head = new ListNode;
        head->next = nullptr;
        head->value = obj.head->value;
        currentNode = head;
        nextNode = obj.head->next;
    }

    while(nextNode) {
        currentNode->next = new ListNode;       // Create new node for next pointer
        currentNode = currentNode->next;            // Move currentNode pointer to newly created ListNode
        currentNode->next = nullptr;            // Initialize next pointer
        currentNode->value = nextNode->value;   // Copy next value to currentNode value
        nextNode = nextNode->next;          // Make next point to nextLtbC's next pointer.
    }
}

// Append node
void NumberList::appendNode(double num) {
    ListNode* newNode = new ListNode;

    newNode->value = num;
    newNode->next = nullptr; 

    if (!head)  // If empty list
        head = newNode;

    else {  // list is not empty, 
        ListNode* nodePtr = head;  
        while (nodePtr->next)
            nodePtr = nodePtr->next;

        nodePtr->next = newNode;
    }
}

// Display contents of linked list | List Print
void NumberList::displayList() const {
    ListNode *nodePtr = nullptr;

    // To point to haed of list
    nodePtr = head;
    while(nodePtr) {     // While there is a node, display value
        cout << nodePtr->value << endl;
        nodePtr = nodePtr->next;
    }
}

// List Reverse
void NumberList::reverseList() {
    ListNode *currentNode = head;
    ListNode *previousNode = nullptr;
    ListNode *nextNode = nullptr;

    if(!head)   // If empty list, nothing to reverse
        return;

    while(currentNode) {
        nextNode = currentNode->next;   // Make nextNode point to next node in list
        currentNode->next = previousNode;   // Make next node in list point to previous
        previousNode = currentNode;         // Make previous point to currentNode, next node now points to currentNode node.
        currentNode = nextNode;         // Move to next node in list
    }

    // Previous now holds the end/head node so assign previous to head
    head = previousNode;
}

// Search List
int NumberList::searchList(double val) const {
    ListNode *search;
    int position = 0;

    if(!head)     // If empty list
        return -1;

    search = head;

    // Traverse list, compare node value to val, return position if/when found
    while(search && search->value != val) {
        if(search->value == val)
            return position;
        
        search = search->next;
        position += 1;
    }

    // Value wasn't found
    return -1;
}

// Positional insert
void NumberList::positionInsert(int pos, double val) {
    ListNode *currentNode;
    ListNode *newNode = new ListNode;
    newNode->value = val;
    ListNode *previousNode = nullptr;

    if(!head) {   // List is empty
        head = newNode;
        head->next = nullptr;
    }
    else {       // List is not empty
        currentNode = head;
        for(int count = 0; currentNode && count < pos; count++) {  // Traverse list until position/end are found
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        if(pos == 0) {
            head = newNode;
            newNode->next = currentNode;
        }
        else if(previousNode) {   // Position was found, add to position
            previousNode->next = newNode;
            newNode->next = currentNode;
        }
        else {             // Position was not found, add to end of list
            previousNode->next = newNode;
            std::cout << "END" << std::endl;
            newNode->next = nullptr;
        }
    }
}

// Positional Remove
void NumberList::positionRemove(int pos) {
    ListNode *currentNode;
    ListNode *previousNode;
    ListNode *nextNode;

    if(!head)  // List is empty, nothing to remove
        return;
    else {
        currentNode = head;
        for(int count = 0; currentNode && count < pos; count++) {
            previousNode = currentNode;
            currentNode = currentNode->next;
            nextNode = currentNode->next;
        }
        if(currentNode) {   // Remove node if it was found
            if(pos == 0) {
                head = currentNode->next;
            }
            else {
                previousNode->next = nextNode;
            }
            delete currentNode;
        }
    }
}

// Destructor
NumberList::~NumberList() {
   ListNode *currentNode = head;
   ListNode *nextNode;

   while (currentNode)
   {
      nextNode = currentNode->next;
      delete currentNode;
      currentNode = nextNode;
   }
}  