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
  int the_length;

public:
  LinkedList(); // Constructor
  LinkedList(T theHead); // Overloaded Constructor
  LinkedList(const LinkedList<T> &other); // Copy Constructor
  LinkedList<T>& operator= (const LinkedList<T> &other); // Assignment Operator
  ~LinkedList(); // Destructor

  // Overloaded operators
  template <class U>
  friend std::ostream& operator<<(std::ostream& out, const LinkedList<U> &f1);
  T& operator[](const unsigned int &i);

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
} // Copy Constructor

template <class T>
LinkedList<T>& LinkedList<T>::operator= (const LinkedList<T> &other){
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
  return out;
}

template <class T>
T& LinkedList<T>::operator[](const unsigned int &i){
  T var;
  return var;
}

// Functions for functionality
template <class T>
bool LinkedList<T>::insert(T data){
  return false;
}

template <class T>
bool LinkedList<T>::remove(T data){
  return false;
}

template <class T>
bool LinkedList<T>::remove(const unsigned int i){
  return false;
}

template <class T>
bool LinkedList<T>::reverse(){
  return false;
}

template <class T>
int LinkedList<T>::length(){
  return 0;
}

template<class T>
bool LinkedList<T>::clear(){
  return false;
}
