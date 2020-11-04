CXX = g++
CXXFLAGS = -Wall -O3

list.out: linked_list.cpp driver.cpp
		$(CXX) $(CXXFLAGS) linked_list.cpp driver.cpp -o list.out
