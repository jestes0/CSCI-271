/*/////////////////////////////////////////////////////////////////////////////

Program Name: node.h

Creator Name: Johnathan (Andy) Estes

Function: A Node class that sets up pointers.

/////////////////////////////////////////////////////////////////////////////*/

#ifndef node_h
#define node_h

#include <stddef.h>


/*/////////////////////////////////////////////////////////////////////////////

Class: Node

This class sets up the pointers and the functions

/////////////////////////////////////////////////////////////////////////////*/
template <typename T>
class Node
{

private:
  T item;
  Node<T>* nextPtr;

public:
  Node(T arg_item, Node<T>* arg_nextPtr);
  Node(T arg_item);
  //getters and setters
  T getItem();
  void setItem(T arg_item);
  Node<T>* getnextPtr();
  void setnextPtr(Node<T>* arg_nextPtr);

};


/****************************************************************
/*  FUNCTION NAME: Node<T>::Node(T arg_item, Node<T>* arg_nextPtr)
/*  Description: Sets the parameters for the pointer and item
/*
/*  PARAMETERS: item and nextPtr
/*
/*  RETURN VALUES: None
/*
/****************************************************************/

template <typename T>
Node<T>::Node(T arg_item, Node<T>* arg_nextPtr)
{

item = arg_item;
nextPtr = arg_nextPtr;

}


/****************************************************************
/*  FUNCTION NAME: Node<T>::Node(T arg_item)
/*  Description: Sets the parameters item and a null character for ptr
/*
/*  PARAMETERS: item
/*
/*  RETURN VALUES: None
/*
/****************************************************************/

template <typename T>
Node<T>::Node(T arg_item)
{

item = arg_item;
nextPtr=NULL;

}

/****************************************************************
/*  FUNCTION NAME: void Node<T>::setItem(T arg_item)
/*  Description: Sets the next item to point at
/*
/*  PARAMETERS: item
/*
/*  RETURN VALUES: None
/*
/****************************************************************/

template <typename T>
void Node<T>::setItem(T arg_item)
{

  item = arg_item;

}

/****************************************************************
/*  FUNCTION NAME: void Node<T>::setnextPtr(Node<T>* arg_nextPtr)
/*  Description: Sets where the pointer points at
/*
/*  PARAMETERS: nextPTr
/*
/*  RETURN VALUES: None
/*
/****************************************************************/

template <typename T>
void Node<T>::setnextPtr(Node<T>* arg_nextPtr)
{

nextPtr = arg_nextPtr;

}

/****************************************************************
/*  FUNCTION NAME: T Node<T>::getItem()
/*  Description: Gets and returns the item pointed at
/*
/*  PARAMETERS: item
/*
/*  RETURN VALUES: item
/*
/****************************************************************/

template <typename T>
T Node<T>::getItem()
{

  return (item);

}

/****************************************************************
/*  FUNCTION NAME: Node<T>* Node<T>::getnextPtr()
/*  Description: Gets and returns the next pointer
/*
/*  PARAMETERS: nextPtr
/*
/*  RETURN VALUES: nextPTr
/*
/****************************************************************/

template <typename T>
Node<T>* Node<T>::getnextPtr()
{

  return nextPtr;

}

#endif
