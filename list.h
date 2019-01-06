/*/////////////////////////////////////////////////////////////////////////////

Program Name:

Creator Name: Johnathan (Andy) Estes

Function: A linked list which will push an item to the front or back, insert
in order, remove a value from the front or back of the list, output the size, or
print the list.

/////////////////////////////////////////////////////////////////////////////*/
#ifndef list.h
#define list.h

#include "node.h"
#include <iostream>
using namespace std;



/*/////////////////////////////////////////////////////////////////////////////

Class: Linkedlist

This class sets up the head node pointer, the item of a templated type, sets up
the functions used for the class, and declares static integers for error checks.

/////////////////////////////////////////////////////////////////////////////*/
template <typename E>
class lists
{

private:

  Node<E>* headPtr; //Node that declares the start of the list.

  E item; //This holds an item of E type.

public:
  lists(); //Default Constructor for the Class
  void push_front (E item); //Pushes an item to the front of the list.
  void push_back (E item);  //Pushes an item to the back of the list.
  void insert_in_order(E value); //Inserts an item into its proper position.
  E pop_front(); //Removes the first item in the list.
  E pop_back();  //Removes the last item in the list.
  int size();    //Prints out the size of the list.
  void print_all();  //Prints out the contents of the list.

  static const int MemoryFull=8001 ; //Throws if there is no memory left
  static const int IndexOutofBounds = 8002 ;

} ;

template <typename E>
lists<E>::lists() //Default Constructor for the Class
{

  headPtr = NULL ;
  /* Sets the head pointer to NULL. This pointer should not move.*/

}

template<typename E>
void lists<E>::push_front(E item)
//Pushes an item to the front of the list.
{

  Node <E>* frontnode = new Node<E>(item, headPtr);
  //Declares a new node to the front of the lists

  if (frontnode == NULL) //Check to determine if there is enough memory.
  {
    throw MemoryFull; //throws an error if memory is full
  }

  headPtr=frontnode;

}

template <typename E>
void lists<E>::push_back (E item)
//Pushes an item to the back of the list.
{

  Node<E>* temp = new Node<E>(item); //Creates a new node for the item.

  if (temp == NULL) //checks to see if the new pointer has memory
  {
    throw MemoryFull;
  }

  if (headPtr == NULL) //checks to see if the head pointer is null.
  {
    headPtr = temp; //if so it will run as if it was a push_front.
    return;
  }

  if (headPtr->getnextPtr() == NULL) //Checks if the next pointer is null
    {
        headPtr->setnextPtr(temp); //Otherwise this pointer will be addressed.
       return;
    }


  Node<E>* current = headPtr; //Pointer to go through the list

  while (current->getnextPtr() != NULL)
  //Cycles through the list to reach the end of the list.
    {
       current = current->getnextPtr();
    }

    current->setnextPtr(temp); //sets the next pointer to insert the item.
}

template <typename E>
void lists<E>::insert_in_order(E next_item)
//Inserts an item into its proper position.
{

  Node<E>* item = new Node<E>(next_item);

  if (item == NULL) //checks to see if the new pointer has memory
  {
    throw MemoryFull;
  }

  Node<E>* current = headPtr ;
  Node<E>* prev = current ;

  if (headPtr == NULL) //Checks to see if the head pointer is null
  {
    push_front(next_item); //pushes the item to the front if list is empty.
    return;
  }


  if(next_item < current->getItem()) //checks if the item is smaller
    {
      push_front(next_item); //pushes to front if the item is smaller.
      return;
    }

//checks to see if the items are equal.
  else if (next_item == current->getItem())
    {

      if (current->getnextPtr() == NULL)
      {
        push_back(next_item);
        return;
      }

      //if there are duplicates, it will scroll through the list until they
      //are not equal and then insert the item into the list.
      while (next_item == current->getItem())
      {
        current = current->getnextPtr();
        if (current->getnextPtr() == NULL)
        {
          push_back(next_item);
          return;
        }
      }

    }
  if(next_item > current->getItem() ) //checks if the item is greater
    {

    //Cycles through the list until the desired position is reached.
    while (next_item > current->getItem())
    {
      prev = current;

    //If the list is at the end, it will put the item at the end of the list
    if (current->getnextPtr() == NULL)
      {
        push_back(next_item);
        return;
      }
        current = current->getnextPtr();

    }

      prev->setnextPtr(item) ;
      item->setnextPtr(current) ;
      return;
    }

  //If they are equal, it will set the item next to the item.
  else if(next_item == current->getItem())
  {
    prev->setnextPtr(item) ;
    item->setnextPtr(current) ;
    return;
  }

}

template <typename E>
E lists<E>::pop_front()
//Removes the first item in the list.
{

    if (headPtr == NULL) //checks to see if the list is empty
    {
      return ("No item. The list is empty"); //list is returned empty
    }

  Node<E>* current = headPtr ; //sets the current into a headPtr
  headPtr = headPtr->getnextPtr() ;
  E returnItem = current->getItem() ;

  //deletes the node and data within the node
  delete current ;
  current = NULL ;

  //returns the item deleted
  return (returnItem) ;
}


template <typename E>
E lists<E>::pop_back()  //Removes the last item in the list.
{

  //checks to see if the list is empty
  if (headPtr == NULL)
  {
    return ("No item. The list is empty");
  }

  Node<E>* current = headPtr ;
  Node<E>* prev = NULL ;

  //loops through the list until the end is reached
  while(current->getnextPtr() != NULL)
    {
       prev = current ;
       current = current->getnextPtr() ;
    }

  //grabs the item at the back of the list.
  E nextitem = current->getItem() ;

  //integer that checks the size
  int a = size();
  cout<<a<<endl;

  //if the size is 1, then it will only pop the front of the list.
  if (a == 1)
  {
    pop_front();
    return (nextitem);
  }

  //deletes the item at the back of the list
  delete current ;
  current = NULL ;
  prev->setnextPtr(NULL) ;

  //returns the item deleted
  return (nextitem) ;

}


template <typename E>
int lists<E>::size()    //Prints out the size of the list.
{

  //counter for item
  int count = 0;

  if (headPtr == NULL)
    {
      //returns 0 if list is empty.
      return count;
    }

  Node<E>* check = headPtr;


  while (check->getnextPtr() != NULL)
    {
      //cycles through list
      check = check->getnextPtr();
      count++;
    }

  return (count + 1);

}

template <typename E>
void lists<E>::print_all()  //Prints out the contents of the list.
{
  int position=0;

  if (headPtr == NULL)
  {
    cout<<"The list is currently empty.\n";
    return;
  }

  Node<E>* counter = headPtr;

  while (counter != NULL)
  {
    E item;
    item=counter->getItem();
    cout <<"Item #"<<position+1<<" is: "<<counter->getItem()<<endl;
    ++position;
    //line is used to call the string of an object
    counter = counter->getnextPtr() ;
    cout << endl ;
  }
}

#endif
