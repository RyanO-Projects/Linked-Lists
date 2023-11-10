#include <iostream>
#include "NumberList.h"
using namespace std;

// Copy Constructor
NumberList::NumberList(const NumberList &obj){
    ListNode *current;
    ListNode *nextLtbC; // nextLtbC == "next Link to be Copied"

    if(obj.head == nullptr)
        head = nullptr;
    
    else{
        head = new ListNode;
        head->next = nullptr;
        head->value = obj.head->value;
        current = head;
        nextLtbC = obj.head->next;
    }

    while(nextLtbC){
        current->next = new ListNode;       // Create new node for next pointer
        current = current->next;            // Move current pointer to newly created ListNode
        current->next = nullptr;            // Initialize next pointer
        current->value = nextLtbC->value;   // Copy next value to current value
        nextLtbC = nextLtbC->next;          // Make next point to nextLtbC's next pointer.
    }
}

void NumberList::appendNode(double num){
    // make a new node
    ListNode* newNode = new ListNode;
    // set fields
    newNode->value = num;
    newNode->next = nullptr; 

    if (!head)  // head is the nullpointer, empty list
        head = newNode;
    else {  // list is not empty, 
        ListNode* nodePtr = head;  
        while (nodePtr->next)
            nodePtr = nodePtr->next;
        nodePtr->next = newNode;    
    }
  }

  void NumberList::displayList() const {

  }
  