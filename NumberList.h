#ifndef NUMBERLIST_H
#define NUMBERLIST_H

class NumberList
{
private:
struct ListNode 
{
    double value;  //data value
    struct ListNode *next;  // points to the next node
};

ListNode* head;  

public:
   NumberList(){ 
     head = nullptr; 
   }

   NumberList(const NumberList &obj);

   // Destructor  --WIP--
   ~NumberList();

   void appendNode(double);
   void displayList() const;

};

#endif