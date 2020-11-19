# Linked-List
This is a basic implementation of a templated linked list.

The Linked List assumes that the "<<", "<", and ">" operators are already defined for the data being stored in the list.

The Linked List provides the following functionality:
  1.) Insertion - The syntax for insertion is list_name.insert(data), where list_name is the name of the linked list being stored, and data is the data element to be put into the list. This is a sorted insert. The data element will be put into its proper placement according to the predefined "<" and ">" operators. This function will return true if the insertion was successful, and false if there was a problem encountered. By default, insertion is done in increasing order.

  2.) Removal - The options for removal are as follows:
    a.) list_name.remove(data), where list_name is the name of the linked list being used, and data is the value of the data element to be removed. The function will then search through the list for the given data element in order to remove it. This function will return true if the data element was found and removed, or false if the data element was not found, or otherwise unable to be removed.
    b.) list_name.remove(index), where list_name is the name of the linked list being used, and index is an unsigned integer for the specific index of the element to be removed. The function will then return false if the removal could not be done, or true if the removal of the index was successful.

  3.) Reversal - The syntax for reversal is list_name.reverse(), where list_name is the name of the linked list being used. The function will then return true if the list has been changed to increasing order, and false if the list has been changed to decreasing order. This result specifies what the future insertion order for the list will be.

  4.) Indexed Element Accessing - The syntax for accessing a specific element is list_name[index], where list_name is the name of the linked list being used, and index is an unsigned integer for the specific index to be accessed. This function will throw an error if the index that the user is attempting to access is out of range. If the index is in range, this function will return the data element at the index specified.

  5.) Clearing - The syntax for clearing the linked list is list_name.clear(), where list_name is the name of the linked list being used. This will free all of the memory being stored in the linked list, resulting in a now empty list.

  6.) Length - The syntax for getting the length of the linked list is list_name.length(), where list_name is the name of the linked list being used. This function will return the current length of the list.

  7.) Printing - This implementation of a linked list contains an overloaded "<<" operator that provides output with the use of the standard library iostream. If the list contains items, the first line of output will be "STUFF IN LINKED LIST", followed by each of the data elements on their own line. If there are no items in the list, the only line of output will be "Nothing".

  8.) Assignment - This implementation of a linked list includes an overloaded assignment operator, and a copy constructor. There is also an overloaded constructor that allows initializing a linked list with a single item at the start of the list.
