/***********************************************************************
 * Header:
 *    INSERTION SORT
 * Summary:
 *    This will contain just the prototype for insertionSortTest(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Donovan Gregory
 ************************************************************************/

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "node.h"

template <class T>
void sortedInsert ( Node<T> ** list,  Node<T> * newNode)
{
    Node<T> * current;

    if (*list == NULL || (*list)->data >= newNode->data)
    {
        newNode->pNext=*list;
        *list=newNode;
    }
    else
    {
        current = *list;
        while (current->pNext!=NULL && current->pNext->data < newNode->data)
        {
            current = current->pNext;
        }

        newNode->pNext = current->pNext;
        current->pNext = newNode;
    }
}

/***********************************************
 * INSERTION SORT
 * Sort the items in the array
 **********************************************/
template <class T>
void sortInsertion(T array[], int num)
{
    Node<T>* unsorted = NULL;
    Node<T>* sorted = NULL;

    for(int i = 0; i < num; i++)
        insert(array[i], unsorted);

    Node<T>* current = unsorted;

    while(current != NULL)
    {
        Node<T>* next = current->pNext;
        sortedInsert(&sorted, current);
        current = next;
    }

    int i=0;

    while (sorted!=NULL)
    {
        array[i]=sorted->data;
        sorted=sorted->pNext;
        i++;
    }

    // free data
    freeData(sorted);
    freeData(unsorted);
}


#endif // INSERTION_SORT_H

