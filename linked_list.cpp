#include <iostream>

template <class T>
struct Node{

  // Member variables
  T data;
  Node<T> *next = NULL;
};

template <class T>
class LinkedList{
private:
  Node<T> *head;
  bool reversed;
  unsigned int the_length;

public:
  LinkedList(); // Constructor
  LinkedList(T theHead); // Overloaded Constructor
  LinkedList(const LinkedList<T> &other); // Copy Constructor
  LinkedList<T>& operator= (const LinkedList<T> &other); // Assignment Operator
  ~LinkedList(); // Destructor

  // Overloaded operators
  template <class U>
  friend std::ostream& operator<<(std::ostream& out, const LinkedList<U> &f1);
  T operator[](const unsigned int &i);

  // Functions for functionality
  bool insert(T data);
  bool remove(T data);
  bool remove(const unsigned int i);
  bool reverse();
  int length();
  bool clear();
};

template <class T>
LinkedList<T>::LinkedList(){
  head = NULL;
  reversed = false;
  the_length = 0;
} // Constructor

template <class T>
LinkedList<T>::LinkedList(T theHead){

  head = new Node<T>;
  head->data = theHead;

  reversed = false;
  the_length = 1;

} // Overloaded Constructor

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &other){

  // If the linked list to copy is empty
  if(other.the_length == 0){
    head = NULL;
    reversed = false;
    the_length = 0;

  }else{

    reversed = other.reversed;
    the_length = other.the_length;
    head = new Node<T>;
    head->data = other.head->data;

    Node<T> *current = head;
    Node<T> *next = other.head->next;
    Node<T> *copy = NULL;

    // Read in all of the information and store a copy
    while (next){

      // Copy the info`
      copy = new Node<T>;
      copy->data = next->data;
      current->next = copy;

      // Move on to the next one
      current = current->next;
      next = next->next;
      copy = NULL;
    }
  }

} // Copy Constructor

template <class T>
LinkedList<T>& LinkedList<T>::operator= (const LinkedList<T> &other){

  // Clear myself pretty much regardless
  clear();

  if(other.the_length == 0){
    head = NULL;
    reversed = false;
    the_length = 0;

  }else{

    reversed = other.reversed;
    the_length = other.the_length;
    head = new Node<T>;
    head->data = other.head->data;

    Node<T> *current = head;
    Node<T> *next = other.head->next;
    Node<T> *copy = NULL;

    // Read in all of the information and store a copy
    while (next){

      // Copy the info`
      copy = new Node<T>;
      copy->data = next->data;
      current->next = copy;

      // Move on to the next one
      current = current->next;
      next = next->next;
      copy = NULL;
    }
  }
  return *this;
} // Assignment Operator

template <class T>
LinkedList<T>::~LinkedList(){

  // Go through the list and delete each
  while(head){
    Node<T> *temp = head->next;
    head->next = NULL;
    delete head;
    head = temp;
    temp = NULL;
  }

} // Destructor

// Overloaded operators
template <class U>
std::ostream& operator<<(std::ostream& out, const LinkedList<U> &f1){

  out << "STUFF IN LINKED LIST" << std::endl;

  if(!f1.head) out << "Nothing" << std::endl;

  Node<U> *theData = f1.head;
  while(theData){
    out << theData->data << std::endl;
    theData = theData->next;
  }

  return out;
}

template <class T>
T LinkedList<T>::operator[](const unsigned int &i){

  T var;
  Node<T> *node = head;

  // Make sure that the index is valid
  if(node) var = node->data;
  if(!node) throw "Empty List";
  if(i<0 || i>=the_length) throw "Invalid Index";

  for(unsigned int j=0;j<i;j++){
    node = node->next;
    var = node->data;
  }
  return var;
}

// Functions for functionality
template <class T>
bool LinkedList<T>::insert(T data){

  Node<T> *theInfo = new Node<T>;
  theInfo->data = data;

  // If the list is empty
  if(!head){

    // Put it at the head
    head = theInfo;
    theInfo = NULL;
    the_length += 1;
    return true;

  }else if(head){

    Node<T> *prev = NULL;
    Node<T> *getThere = head;
    Node<T> *getNext = head->next;

    // Increasing order
    if(!reversed){
      while(getThere && getNext){

        if(getThere->data < theInfo->data){
          if(!prev) prev = getThere;
          else prev = prev->next;
          getThere = getThere->next;
          getNext = getNext->next;
        }else break;
      }

    // Decreading order
    }else{
      while(getThere && getNext){

        if(getThere->data > theInfo->data){
          if(!prev) prev = getThere;
          else prev = prev->next;
          getThere = getThere->next;
          getNext = getNext->next;
        }else break;
      }
    }

    // If we are at the end of the list
    if(!getNext && !prev){

      if(!reversed){
        if(getThere->data < theInfo->data) getThere->next = theInfo;
        else{
          head = theInfo;
          theInfo->next = getThere;
        }

      }else{
        if(getThere->data > theInfo->data) getThere->next = theInfo;
        else{
          head = theInfo;
         theInfo->next = getThere;
       }
      }

    // If we are still at the beginning of the list
    }else if(getThere == head){
      if(!reversed){
        if(getThere->data < theInfo->data){
           getThere->next = theInfo;
           theInfo->next = getNext;
        }else{
          theInfo->next = getThere;
          head = theInfo;
        }

      }else{
        if(getThere->data > theInfo->data){
           getThere->next = theInfo;
           theInfo->next = getNext;
        }else{
          theInfo->next = getThere;
          head = theInfo;
        }
      }

    }else{

      if(!reversed){
        if(getThere->data < theInfo->data){
          getThere->next = theInfo;
          theInfo->next = getNext;
        }else{
          prev->next = theInfo;
          theInfo->next = getThere;
        }

      }else{
        if(getThere->data > theInfo->data){
          getThere->next = theInfo;
          theInfo->next = getNext;
        }else{
          prev->next = theInfo;
          theInfo->next = getThere;
        }
      }
    }

    the_length += 1;
    return true;
  }

  return false;
}

template <class T>
bool LinkedList<T>::remove(T data){

  if(!head) return false;

  Node<T> *prev = NULL;
  Node<T> *curr = head;
  Node<T> *next = curr->next;

  // Keep searching until we either find the item, or reach the end of the list
  while(next && ((curr->data > data) || (curr->data < data))){
    if(!prev) prev = head;
    else prev = prev->next;
    curr = curr->next;
    next = next->next;
  }

  // If we are at the end and dont have the node
  if((curr->data > data) || (curr->data < data)) return false;

  // If the item to remove is the head
  else if(curr == head){
    head = next;
    delete curr;
    curr = NULL;

    the_length--;
    return true;

  // Otherwise, we can remove the desired node
  }else{
    prev->next = next;
    delete curr;

    the_length--;
    return true;
  }

  return false;
}

template <class T>
bool LinkedList<T>::remove(const unsigned int i){

  // Cases where I cannot remove
  if(!head) return false;
  if(i >= the_length) return false;

  // Navigate to the desired location
  Node<T> *prev = NULL;
  Node<T> *current = head;
  Node<T> *next = head->next;

  for(unsigned int j=0;j<i;j++){
    if(!prev) prev = head;
    else prev = prev->next;
    current = current->next;
    next = next->next;

    if(!next) break;
  }

  // At the head
  if(!prev) head = next;

  // At the end
  else if(!next) prev->next = NULL;

  // Anywhere else
  else prev->next = next;

  delete current;
  current = NULL;
  the_length--;

  return true;
}

template <class T>
bool LinkedList<T>::reverse(){
  return reversed;
}

template <class T>
int LinkedList<T>::length(){
  return the_length;
}

template<class T>
bool LinkedList<T>::clear(){

  while(head){
    Node<T> *temp = head->next;
    head->next = NULL;
    delete head;
    head = temp;
    temp = NULL;
    the_length--;
  }

  return true;
}
