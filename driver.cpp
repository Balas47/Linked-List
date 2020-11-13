#include <iostream>
#include <cstdlib>
#include <ctime>
#include "linked_list.cpp"

int main(){

  // Seed the random generator
  std::srand(std::time(nullptr));

  // Insertion tests
  LinkedList<int> myFriend;

  std::cout << "Insertion Order" << std::endl;
  for(int i=0;i<50;i++){
    int num = std::rand() % 100;
    std::cout << num << std::endl;
     myFriend.insert(num);
   }

  // Testing indexing
  try{
    std::cout << "Linked List Order" << std::endl;
    for(unsigned int i=0;i<50;i++) std::cout << myFriend[i] << std::endl;
  }catch(...){
    std::cerr << "An error occured!" << '\n';
  }

  //Testing removal
  std::cout << "Before Removal" << std::endl;
  std::cout << myFriend[0] << "\n" << myFriend[1] << "\n" << myFriend[2] << std::endl;

  std::cout << "After Removal of First Item" << std::endl;
  myFriend.remove(myFriend[0]);  // Remove the head
  std::cout << myFriend[0] << "\n" << myFriend[1] << std::endl;

  std::cout << "Before Removal" << std::endl;
  std::cout << myFriend[0] << "\n" << myFriend[1] << "\n" << myFriend[2] << std::endl;

  std::cout << "After Removal of Second Item" << std::endl;
  myFriend.remove(myFriend[1]);  // Remove the head
  std::cout << myFriend[0] << "\n" << myFriend[1] << std::endl;

  LinkedList<int> secondFriend;
  std::cout << "New List" << std::endl;
  secondFriend.insert(0);
  secondFriend.insert(1);
  secondFriend.insert(3);
  std::cout << secondFriend[0] << "\n" << secondFriend[1] << "\n" << secondFriend[2] << std::endl;
  std::cout << "After Removal of Nonexistent Item" << std::endl;
  secondFriend.remove(-1);
  std::cout << secondFriend[0] << "\n" << secondFriend[1] << "\n" << secondFriend[2] << std::endl;

  std::cout << "After Removal of Last Item" << std::endl;
  secondFriend.remove(3);
  try{
    std::cout << secondFriend[0] << "\n" << secondFriend[1] << "\n" << secondFriend[2] << std::endl;
  }catch(...){
    std::cerr << "This Should Happen" << '\n';
  }

  return 0;
}
