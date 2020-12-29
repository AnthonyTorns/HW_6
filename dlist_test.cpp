#include "dlist.h"
#include <iostream>

int main(){
  Dlist<int>* list1 = new Dlist<int>;
  list1->InsertFront(0);
  list1->InsertFront(1);
  list1->InsertFront(3);

  list1->operator=(*list1);
  list1->RemoveBack();
 
  list1->RemoveFront();
  list1->~Dlist();
  delete list1;

  
  
  
  
}

