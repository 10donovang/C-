/***********************************************************************
 * Program:
 *    Lesson 01, Set
 *    Brother JonesL, CS 235
 * Author:
 *    Donovan Gregory
 * Summary:
 *    header file containing the node class
 ************************************************************************/

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cassert>

template <class T>
class Node
{
  public:
    T data;
    Node<T> * pNext;
    Node() {pNext = NULL;}
    Node(T dataIn) {data = dataIn; pNext = NULL;}        
};

template <class T>
Node <T> * copy(Node <T> *nodeIn)
{
   //to hold current value for node
   Node<T>* current = nodeIn;
   //to creat copy of existing node
   Node<T>* copy = new Node<T>;

   //fills node with data from nodeIn
   copy->data = current->data;
   copy->pNext = NULL;

   //creates first element of copy 
   Node<T>* const head = copy;

   //increment to current->pNext
   current = current->pNext;

   //loop through remaining nodes and copy them while not NULL
   while(current != NULL)
   {
      //creates new node to store data
      copy = copy->pNext = new Node<T>;

      //copies data from current to new node
      copy->data = current->data;

      //sets pointer to next node to NULL because there isn't one yet
      copy->pNext = NULL;

      //increments to next node
      current = current->pNext;
   }

   //returns pointer to first node of copied list
   return head;
}

template <class T>
Node <T> * insert(const T &dataIn, Node <T> *&nodeIn, bool hed = false)
{
    Node <T> *newNode = new Node <T> (dataIn);

    if(nodeIn == NULL)
    {
        newNode->pNext = nodeIn;
        nodeIn = newNode;

        return(newNode);
    }
    else if(hed == true)
    {
        newNode->pNext = nodeIn->pNext;
        nodeIn->pNext = newNode;

        T tmp = nodeIn->data;
        nodeIn->data = newNode->data;
        newNode->data = tmp;

        return(newNode);
    }
    else
    {
        newNode->pNext = nodeIn->pNext;
        nodeIn->pNext = newNode;

        return(newNode);
    }
}

template <class T>
Node <T> * find(Node <T> *nodeIn, T dataIn)
{
    Node <T> *tmpNode;

    tmpNode = nodeIn;

    while(tmpNode != NULL)
    {
        if(tmpNode->data == dataIn)
            return(tmpNode);
        else
            tmpNode = tmpNode->pNext;
    }
}

template <class T>
std::ostream &operator<<(std::ostream& os, const Node <T> *nodeIn)
{
    while(nodeIn != NULL)
    {
        os << nodeIn->data ;

        if(nodeIn->pNext != NULL)
            os << ", ";

        nodeIn = nodeIn->pNext;
    }
    return os;
}

template <class T>
void freeData(Node <T> *&nodeIn)
{
    Node <T> *tmpNode;

    tmpNode = nodeIn;

    while(nodeIn != NULL)
    {
        tmpNode = tmpNode->pNext;
        delete nodeIn;

        nodeIn = tmpNode;
    }
}
#endif //NODE_H
