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

  return 0;
}
