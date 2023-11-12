#include <iostream>
#include "NumberList.h"
using namespace std;

/*
* #2: List Print |              done <>
* #3: Copy Constructor |        done <>
* #4: Reverse List |            done <>
* #5: List Search |             done <>
* #6: Positional Insertion |    not done
* #7: Positional Removal |      not done
*/

// Copy Constructor
NumberList::NumberList(const NumberList &obj){
    ListNode *current = nullptr;
    ListNode *nextNtbC = nullptr; // NtbC = "Node to be Copied"

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
    // To travel list
    ListNode *nodePtr = nullptr;

    // To point to haed of list
    nodePtr = head;
    while(nodePtr){     // While there is a node, display value
        cout << nodePtr->value << endl;
        nodePtr = nodePtr->next;
    }
}

// List Reverse
void NumberList::reverseList(){
    ListNode *current = head;
    ListNode *previous = nullptr;
    ListNode *nextNtbR = nullptr;   // NtbR = "Node to be Reversed"

    if(!head){  // If empty list
        return;
    }

    while(current){
        nextNtbR = current->next;   // Make nextNtbr point to next node in list
        current->next = previous;   // Make next node in list point to previous
        previous = current;         // Make previous point to current, next node now points to current node.
        current = nextNtbR;         // Move to next node in list
    }

    // Previous now holds the end/head node so assign previous to head
    head = previous;
}

// Search List
int NumberList::searchList(double val) const{
    ListNode *search;
    int position = 0;

    if(!head){    // If empty list
        return -1;
    }
    search = head;

    // Traverse list, compare node value to val, return position if/when found
    while(search && search->value != val){
        if(search->value == val){
            return position;
        }
        search = search->next;
        position += 1;
    }

    // Value wasn't found
    return -1;
}

// Positional insert
void NumberList::positionInsert(int pos, double val){
    ListNode *current;
    ListNode *newNode = new ListNode;
    newNode->value = val;
    ListNode *previousNode = nullptr;

    if(!current){   // List is empty
        head = newNode;
        head->next = nullptr;
    }
    else{           // List is not empty
        current = head;
        int count = 0;
        while(current && count <= pos){   // Traverse list until position/end are found
            previousNode = current;
            if(count == pos){             // Position found, insert new node
                previousNode->next = newNode;
                newNode->next = current;
                return;
            }
            if(current->next == nullptr){ // Requested position is out of range, insert at end
                current->next = newNode;
                newNode->next = nullptr;
                return;
            }
            current = current->next;
            count++;
        }
    }
}

// Destructor
NumberList::~NumberList()
{
   ListNode *current = head;   // To traverse the list
   ListNode *nextNtbD;  // 

   while (current)
   {
      // Save a pointer to the next node.
      nextNtbD = current->next;

      // Delete the current node.
      delete current;

      // Position nodePtr at the next node.
      current = nextNtbD;
   }
}  