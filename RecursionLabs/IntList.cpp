#include <iostream>
#include "IntList.h"
   
   
   IntList::IntList() {
       head = 0;
   }

   /* Inserts a data value to the front of the list.
   */
   void IntList::push_front(int value) {
        IntNode * temp = new IntNode(value);
        temp -> next = this -> head;
        this -> head = temp;
         
   }

   /* Outputs to a single line all of the int values stored in the list, each separated by a space. 
      This function does NOT output a newline or space at the end.
   */
   ostream & operator<<(ostream &out, const IntList &rhs) {
        if (rhs.head == 0) {
            return out;
        }
        operator<<(out, rhs.head);
        return out;
   }

   /* Returns true if the integer passed in is contained within the IntList, 
      otherwise returns false.
   */
   bool IntList::exists(int value) const {
       
        if (head == 0) {
            return false;
        }
        if (head -> data == value) {
            return true;
        }
        return exists(head -> next, value);
        
   }
   
   bool IntList::exists(IntNode *temp, int value) const {
       
        if (temp == 0) {
            return false;
        }
        if (temp -> data == value){
            return true;
        }
        
        return exists(temp ->next, value);
        
   }
   
   
ostream & operator<<(ostream &out, IntNode * rhs) {
    if (rhs == 0) {
            return out;
    }
    out << rhs -> data;
    if (rhs -> next != 0) {
            out << " ";
    }
    operator<<(out, rhs -> next);
    return out;
}