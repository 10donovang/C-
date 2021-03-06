/*****************************************************
 * File: pair.h
 *
 * Purpose: Defines a Pair template class that can hold
 *   two items of arbitrary data types.
 ******************************************************/

#ifndef PAIR_H
#define PAIR_H
#include <iostream>

using namespace std;

template <class T, class T1>
class Pair
{
  public:
   T getFirst() const {return first;}
   void setFirst(T newFirst){this->first = newFirst;}
   T1 getSecond()const {return second;}
   void setSecond(T1 newSecond){this->second = newSecond;}
   void display()const {cout << getFirst() << " - " << getSecond();}
  private:
      T first;
      T1 second;
};
   
// TODO: Fill in this class
// Put all of your method bodies right in this file


#endif // PAIR_H
