#ifndef __DLIST_H__
#define __DLIST_H__
#include <iostream>
#include <cmath>

/******************************************
 * Do not modify the class declarations!
 ***************************************/
class emptyList {
  // OVERVIEW: an exception class
};

template <typename T>
class Dlist {
  // OVERVIEW: contains a double-ended list of Objects

 public:

  // Operational methods

  bool IsEmpty() const;
  // EFFECTS: returns true if list is empty, false otherwise

  void InsertFront(const T &o);
  // MODIFIES this
  // EFFECTS inserts o at the front of the list
    
  void InsertBack(const T &o);
  // MODIFIES this
  // EFFECTS inserts o at the back of the list

  T RemoveFront();
  // MODIFIES this
  // EFFECTS removes and returns first object from non-empty list
  //         throws an instance of emptyList if empty

  T RemoveBack();
  // MODIFIES this
  // EFFECTS removes and returns last object from non-empty list
  //         throws an instance of emptyList if empty

  // Maintenance methods
  Dlist();                                   // ctor
  Dlist(const Dlist &l);                     // copy ctor
  Dlist &operator=(const Dlist &l);          // assignment
  ~Dlist();                                  // dtor

 private:
  // A private type
  struct node {
    node   *next;
    node   *prev;
    T      o;
  };

  node   *first; // The pointer to the first node (0 if none)
  node   *last;  // The pointer to the last node (0 if none)
  //How us this different than the doubly linked list in class?

  // Utility methods

  void MakeEmpty();
  // EFFECT: called by constructors to establish empty
  // list invariant
    
  void RemoveAll();
  // EFFECT: called by destructor and operator= to remove and destroy
  // all list nodes

  void CopyAll(const Dlist &l);
  // EFFECT: called by copy constructor/operator= to copy nodes
  // from a source instance l to this instance
};

/**** DO NOT MODIFY ABOVE THIS LINE *****/

/***************************************
 *ADD  Member function implementations here
 ***************************************/


/* this must be at the end of the file */
/*
Constructor: calls MakeEmpty

IsEmpty: const function returns bool,
if first == last{
   if both are NULL{
   return true
   }
}
return false

Insert Front, void takes in const element of typename T
if IsEmpty
create node store value and point first and last to the same node
else
temp node holds address of first
first = new node
first->next = temp
first->prev = nullptr
intiazlize first 
temp->prev = first

Insert Back, void takes in const element of typename T 
if IsEmpty
create node store value and point first and last to the same node
else
temp node holds address of last
last = new node
last->next = nullptr
last->prev = temp
intiazlize last
temp->next = last


Remove Front returns typename T takes in no arguments 
if empty throw emptylist instnance 
else
      temp node = nullptr
      if first == last
        element = first->o
        temp = first
        first = first->next
        last = first\
        delete temp
      
      else
        temp = first;
        first = first->next
        first->prev = nullptr
        temp->next = nullptr
        element = temp->o
        delete temp
      return element

Remove Back return Typename T takes in no arguments 
if empty throw epty list instance 
else
      temp node = nullptr
      if first == last
        element = last->o
        temp = last
        last = last->prev
        first = last
        delete temp
      
      else
        temp = last
        last = last->prev
        last->next= nullptr
        temp->prev = nullptr
        element = temp->o
        delete temp

      return element

Make Empty void no arguments 
first = NULL
last = NULL

RemoveAll void no arguemnts
if not Empty
    while(first)
      if(first == last)
        delete first
        first = nullptr
        last = nullptr
      
      else
        node *oldnode = first
        first = first->next
        first->prev = nullptr
        oldnode->next = nullptr
        delete oldnode
  else
    try
      if is empty
      emptyList empty
      throw empty
    catch(emptyList list
  
  Dlist Deconstructor 
  calls Remove All

  Copy Constructor 
  calls MakeEmpty 
  callsCopy All

  Operator function returns Dlist takes in a const reference of a list
  create temp list 
  copy into tlist
  remove al of current list 
  copies all into the this pointer
  return this pointer 
  
  Copy All void tAKES in a const reference of a list
  node pointer created to store l.last
  while(temp exist)
  this calls insert front(temp)
  temp = temp->next
*/

template<typename T>
Dlist<T>::Dlist() {
  MakeEmpty();
};

template <typename T>
bool Dlist<T>::IsEmpty() const {
  if (first == last) {
    if (!first&& !last) {
      return true;
    }
  }
  return false;
}

template <typename T>
void Dlist<T>::InsertFront(const T &o) {
  
  if (IsEmpty()) {
    node* new_node = new node; 
    new_node->o = o;
    new_node->next = nullptr;
    new_node->prev = nullptr;
    first = new_node;
    last = new_node; 
  }
  else { 
    node* temp = first; 
    first = new node;
    first->o = o;
    first->next = temp;
    temp->prev = first;
    first->prev = nullptr;
  }
}

template <typename T>
void Dlist<T>::InsertBack( const T &o) {
  if (IsEmpty()) {
    node* new_node = new node;
    new_node->o = o;
    new_node->next = nullptr;
    new_node->prev = nullptr;
    first = last = new_node;
  }
  else {
    node *temp = last;
    last = new node;
    last->o = o;
    last->next = nullptr;
    last->prev = temp;
    temp->next = last;
  }
}

template <typename T>
T Dlist<T>::RemoveFront() {
  if (IsEmpty()) {
    emptyList empty;
    throw empty;
  }
  else {
      T element;
      node* temp = nullptr;
      if(first == last){
        element = first->o;
        temp = first;
        first = first->next;
        last = first;
        delete temp;
      }
      else {
        temp = first;
        first = first->next;
        first->prev = nullptr;
        temp->next = nullptr;
        element = temp->o;
        delete temp;
      }
      return element;
  }

}

template <typename T> 
T Dlist<T>::RemoveBack() {
  T element;
  if (IsEmpty()) {
      emptyList empty;
      throw empty;
  }
  else {
    node* temp = nullptr;
    if(first == last){
      temp = last;
      element = temp->o;
      last = last->next;
      first = last;
      delete temp;
    }
    else {
      temp = last;
      last = last->prev;
      last->next = nullptr;
      temp->prev = nullptr;
      element  = temp->o;
      delete temp;
    }
    return element;
  }
}
  

template <typename T>
void Dlist<T>::MakeEmpty() {
  first = NULL;
  last = NULL;
}

template<typename T>
void Dlist<T>::RemoveAll() {
  if (!IsEmpty()) {
    while(first) {
      if(first == last) {
        delete first;
        first = nullptr;
        last = nullptr;
      }
      else {
        node *oldnode = first;
        first = first->next;
        first->prev = nullptr;
        oldnode->next = nullptr;
        delete oldnode;
      }
    }
  }
  else {
    try{
      if (IsEmpty()) {
      emptyList empty;
      throw empty;
      }
    }
    catch (emptyList list) {}
  }
}

template <typename T>
Dlist<T>::~Dlist() {
  RemoveAll();
}
template <typename T>
Dlist<T>::Dlist(const Dlist &list) {
  MakeEmpty();
  CopyAll(list);
};

template <typename T>
Dlist<T>& Dlist<T>::operator=(const Dlist<T> &l) {
  Dlist<T> temp_list;
  temp_list.CopyAll(l);
  RemoveAll();
  this->CopyAll(temp_list);
  
  return *this;
  
  
}

template <typename T>
void Dlist<T>::CopyAll(const Dlist<T> &l) {
  node* temp = l.last;
  while (temp) {
    this->InsertFront(temp->o);
    temp = temp->prev;
  }
}
  

#endif /* __DLIST_H__ */
