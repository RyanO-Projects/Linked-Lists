#include <iostream>
#include "NumberList.h"
using namespace std;

// Copy Constructor
NumberList::NumberList(const NumberList &obj){
    ListNode *current;
    ListNode *nextNtbC; // nextLtbC == "next Node to be Copied"

    if(obj.head == nullptr)
        head = nullptr;
    
    else{
        head = new ListNode;
        head->next = nullptr;
        head->value = obj.head->value;
        current = head;
        nextNtbC = obj.head->next;
    }

    while(nextNtbC){
        current->next = new ListNode;       // Create new node for next pointer
        current = current->next;            // Move current pointer to newly created ListNode
        current->next = nullptr;            // Initialize next pointer
        current->value = nextNtbC->value;   // Copy next value to current value
        nextNtbC = nextNtbC->next;          // Make next point to nextLtbC's next pointer.
    }
}

// Append node
void NumberList::appendNode(double num){
    ListNode* newNode = new ListNode;

    newNode->value = num;
    newNode->next = nullptr; 

    if (!head)  // head == nullptr | List is empty
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
    // To travel list
    ListNode *nodePtr;

    // To point to haed of list
    nodePtr = head;
    while(nodePtr){     // While there is a node, display value
        cout << nodePtr->value << endl;
        nodePtr = nodePtr->next;
    }
}

// List Reverse
void NumberList::reverseList(){
}

// Destructor
NumberList::~NumberList()
{
   ListNode *current;   // To traverse the list
   ListNode *nextNtbD;  // To point to the next node

   current = head;

   while (current != nullptr)
   {
      // Save a pointer to the next node.
      nextNtbD = current->next;

      // Delete the current node.
      delete current;

      // Position nodePtr at the next node.
      current = nextNtbD;
   }
}  