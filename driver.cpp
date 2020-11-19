#include <iostream>
#include <cstdlib>
#include <ctime>
#include "linked_list.cpp"

int main(){

  // Seed the random generator
  std::srand(std::time(nullptr));

  // Insertion tests
  LinkedList<int> myFriend;

  std::cout << "###############" << std::endl;
  std::cout << "Insertion Order" << std::endl;
  for(int i=0;i<50;i++){
    int num = std::rand() % 100;
    std::cout << num << std::endl;
     myFriend.insert(num);
   }
   std::cout << "##############\n" << std::endl;

  // Testing indexing
  try{
    std::cout << "#################" << std::endl;
    std::cout << "Linked List Order" << std::endl;
    for(unsigned int i=0;i<50;i++) std::cout << myFriend[i] << std::endl;
    std::cout << "#################\n" << std::endl;
  }catch(...){
    std::cerr << "An error occured!" << '\n';
  }

  //Testing removal
  std::cout << "##############" << std::endl;
  std::cout << "Before Removal" << std::endl;
  std::cout << myFriend[0] << "\n" << myFriend[1] << "\n" << myFriend[2] << std::endl;
  std::cout << "##############\n" << std::endl;

  std::cout << "###########################" << std::endl;
  std::cout << "After Removal of First Item" << std::endl;
  myFriend.remove(myFriend[0]);  // Remove the head
  std::cout << myFriend[0] << "\n" << myFriend[1] << std::endl;
  std::cout << "###########################\n" << std::endl;

  std::cout << "##############" << std::endl;
  std::cout << "Before Removal" << std::endl;
  std::cout << myFriend[0] << "\n" << myFriend[1] << "\n" << myFriend[2] << std::endl;
  std::cout << "##############\n" << std::endl;

  std::cout << "############################" << std::endl;
  std::cout << "After Removal of Second Item" << std::endl;
  myFriend.remove(myFriend[1]);  // Remove the head
  std::cout << myFriend[0] << "\n" << myFriend[1] << std::endl;
  std::cout << "############################\n" << std::endl;

  LinkedList<int> secondFriend;
  std::cout << "########" << std::endl;
  std::cout << "New List" << std::endl;
  secondFriend.insert(0);
  secondFriend.insert(1);
  secondFriend.insert(3);
  std::cout << secondFriend[0] << "\n" << secondFriend[1] << "\n" << secondFriend[2] << std::endl;
  std::cout << "########\n" << std::endl;

  std::cout << "#################################" << std::endl;
  std::cout << "After Removal of Nonexistent Item" << std::endl;
  secondFriend.remove(-1);
  std::cout << secondFriend[0] << "\n" << secondFriend[1] << "\n" << secondFriend[2] << std::endl;
  std::cout << "#################################\n" << std::endl;

  std::cout << "##########################" << std::endl;
  std::cout << "After Removal of Last Item" << std::endl;
  secondFriend.remove(3);
  try{
    std::cout << secondFriend[0] << "\n" << secondFriend[1] << "\n" << secondFriend[2] << std::endl;
  }catch(...){
    std::cerr << "This Should Happen" << '\n';
  }
  std::cout << "##########################\n" << std::endl;

  std::cout << "##############################" << std::endl;
  std::cout << "Testing Overloaded << Operator" << std::endl;
  LinkedList<int> newTest;
  for(int i=1;i<10;i++) newTest.insert(i);
  std::cout << newTest << std::endl;
  std::cout << "##############################\n" << std::endl;

  std::cout <<"##############################" << std::endl;
  std::cout << "Testing clear() Functionality" << std::endl;
  std::cout << "The length before clear() is: " << newTest.length() << std::endl;
  newTest.clear();
  std::cout << newTest << std::endl;
  try{
    int fail = newTest[0];
    std::cout << fail << std::endl;
  }catch(...){
    std::cerr << "This should happen" << std::endl;
  }
  std::cout << "The length after clear() is: " << newTest.length() << std::endl;
  std::cout <<"##############################" << std::endl;

  std::cout << "#####################" << std::endl;
  std::cout << "Copy Constructor Test" << std::endl;
  LinkedList<int> copy = myFriend;
  std::cout << "Original" << std::endl;
  std::cout << myFriend << std::endl;
  std::cout << "Copy" << std::endl;
  std::cout << copy << std::endl;
  std::cout << "#####################\n" << std::endl;

  std::cout << "########################" << std::endl;
  std::cout << "Assignmend Operator Test" << std::endl;
  myFriend = secondFriend;
  std::cout << "One to Copy" << std::endl;
  std::cout << secondFriend << std::endl;
  std::cout << "Length: " << secondFriend.length() << std::endl;
  std::cout << "Result (using list from last test)" << std::endl;
  std::cout << myFriend;
  std::cout << "Length: " << myFriend.length() << std::endl;
  std::cout << "########################\n" << std::endl;

  std::cout << "#####################" << std::endl;
  std::cout << "Testing Index Removal" << std::endl;
  std::cout << "Original: " << std::endl;
  LinkedList<int> indexRem;
  indexRem.insert(1);
  indexRem.insert(2);
  indexRem.insert(3);
  indexRem.insert(4);
  indexRem.insert(5);
  indexRem.insert(6);
  indexRem.insert(7);
  indexRem.insert(8);
  indexRem.insert(9);
  indexRem.insert(10);
  std::cout << indexRem;
  std::cout << "Length: " << indexRem.length() << std::endl;
  std::cout << "Removal of First Item" << std::endl;
  unsigned int del = 0;
  indexRem.remove(del);
  std::cout << indexRem;
  std::cout << "Length: " << indexRem.length() << std::endl;
  std::cout << "Removal of Last Item" << std::endl;
  del = 8;
  indexRem.remove(del);
  std::cout << indexRem;
  std::cout << "Length: " << indexRem.length() << std::endl;
  std::cout << "Removal Anywhere Else" << std::endl;
  del = std::rand() % del;
  std::cout << "Index to Remove: " << del << std::endl;
  std::cout << "Item to Remove: " << indexRem[del] << std::endl;
  indexRem.remove(del);
  std::cout << indexRem;
  std::cout << "Length: " << indexRem.length() << std::endl;
  std::cout << "#####################\n" << std::endl;

  return 0;
}
