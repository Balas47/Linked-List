#include <iostream>

template <typename T>
struct Node{

  // Member variables
  T data;
  Node<T> *next;

  // Helper function for linked list
  Node<T>* getNext();
};

template <typename U>
class LinkedList{
private:
  Node<U> head;
  bool reversed;
  int length;

public:
  LinkedList(); // Constructor
  LinkedList(Node<U> theHead); // Overloaded Constructor
  LinkedList(const LinkedList<U> &other); // Copy Constructor
  LinkedList& operator= (const LinkedList<U> &other); // Assignment Operator
  ~LinkedList(); // Destructor

  // Overloaded operators
  friend std::ostream& operator<<(std::ostream& out, const LinkedList<U> &f1);
  Node& operator[](const unsigned int &i);

  // Functions for functionality
  bool insert(U data);
  bool remove();
  bool reverse();
  bool length();
}
