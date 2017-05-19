/***********************************************************************
 * Program:
 *    Week 01, Vector
 *    Brother JonesL, CS235
 * Author:
 *    Brian Robertson
 * Summary:
 *    stl stack re-implimentation.
 * Time:
 *      4 hours.
 ************************************************************************/
#ifndef STACK_H
#define STACK_H

using namespace std;
#include <iostream>
#include <cstdlib>

#include <cassert>

template <class T>
class Stack
{
   //private:
  public:

   T * elements;
   T myTop;                  // index of top of stack
   int sizeOfStack;
   int capacityOfStack;

   void doubleCapacity(int newCap)
   {
      //        std::cout << "doubleCapacity " << newCap << std::endl;

      T * newElements;

              try
              {
                 newElements = new T[newCap];
              }
              catch (std::bad_alloc)
              {
                 throw "ERROR: Unable to allocate buffer";
              }

              for (int i = 0; i < sizeOfStack; ++i)
              {
                 newElements[i] = elements[i];
              }

              capacityOfStack = newCap;

              delete[] elements;

                      try
                      {
                         elements = new T[newCap];
                      }
                      catch (std::bad_alloc)
                      {
                         throw "ERROR: Unable to allocate buffer";
                      }

                      for (int i = 0; i < newCap; i++)
                         elements[i] = newElements[i];

                      //data = newElements;

                      delete[] newElements;
   }

  public:

   Stack() {sizeOfStack = 0; capacityOfStack = 0; elements = NULL;}

   Stack(int cap) throw (const char *)
   {
      //                        std::cout << "non def constructor " << std::endl;

      assert(cap >= 0);

      if (cap == 0)
      {
         this->capacityOfStack = this->sizeOfStack = 0;
         this->elements = NULL;
         return;
      }

         try
         {
            elements = new T[cap];
         }
         catch (std::bad_alloc)
         {
            throw "ERROR: Unable to allocate buffer";
         }

         this->capacityOfStack = cap;
         this->sizeOfStack = 0;

         for (int i = 0; i < capacityOfStack; i++)
            elements[i] = T();

   }

   Stack<T>(const Stack<T> & rhs) throw (const char *)
   {
      //                                        std::cout << "cpy constructor " << std::endl;

      assert(rhs.capacityOfStack >= 0);

      if (rhs.capacityOfStack == 0)
      {
         capacityOfStack = sizeOfStack = 0;
         elements = NULL;
         return;
      }

         try
         {
            elements = new T[rhs.capacityOfStack];
         }
         catch (std::bad_alloc)
         {
            throw "ERROR: Unable to allocate buffer";
         }

         assert(rhs.sizeOfStack >= 0 && rhs.sizeOfStack <= rhs.capacityOfStack);
         capacityOfStack = rhs.capacityOfStack;
         sizeOfStack = rhs.sizeOfStack;

         for (int i = 0; i < sizeOfStack; i++)
            elements[i] = rhs.elements[i];

         for (int i = sizeOfStack; i < capacityOfStack; i++)
            elements[i] = T();

   }

   int capacity() const           {return capacityOfStack;}

   int size()               { return sizeOfStack; }

   T top()
   {
      //    std::cout << "top " << elements[sizeOfStack - 1] << std::endl;

      if (sizeOfStack == 0)
         throw "ERROR: Unable to reference the element from an empty Stack";
      ;

      return (elements[sizeOfStack - 1]);
   }

   void push(T newElement)
   {
      // std::cout << "push " << newElement << std::endl;

      if (sizeOfStack == 0)
         doubleCapacity(2);

      if (sizeOfStack >= capacityOfStack)
         doubleCapacity(2 * capacityOfStack);



      elements[sizeOfStack] = newElement;
      ++sizeOfStack;

      //std::cout << "sizeOfStack " << sizeOfStack << std::endl;
      //std::cout << "capacityOfStack " << capacityOfStack << std::endl;
      //std::cout << "newElement " << newElement << std::endl;

      for(int i = 0; i < sizeOfStack; i++)
      {
         //        std::cout << " - elements[" << i << "] " << elements[i]  << " ~ " << std::endl;
      }
   }


   void pop()
   {
      //std::cout << "pop " << std::endl;

      if (sizeOfStack > 0)
      {
         sizeOfStack--;

         for(int i = 0; i < sizeOfStack; i++)
         {
            //        elements[i] = elements[i+1];

            //        std::cout << " - elements[" << i << "] " << elements[i]  << " ~ " << std::endl;

         }
      }
      else
         throw "ERROR: Unable to pop from an empty Stack";
   }

   bool empty(void) {return (sizeOfStack == 0);}

   //    bool full(void) {return 0;}                       // is stack full


   Stack<T> & operator = (const Stack<T> & rhs)              // overloaded assignment operator
   {
      //        std::cout << "operator = " << std::endl;

      if (rhs.sizeOfStack > capacityOfStack)
         doubleCapacity(rhs.sizeOfStack * 2);
      else
         capacityOfStack = rhs.capacityOfStack;

      sizeOfStack = rhs.sizeOfStack;

      for (int i = 0; i < rhs.sizeOfStack; i++)
      {
         elements[i] = rhs.elements[i];

      }
      return *this;
   }

   ~Stack() { delete[] elements; }                     // default destructor

};
#endif
