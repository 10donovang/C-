/***********************************************************************
* Header:
*    Vector
* Summary:
*    This class contains the makeup of a vector. 
*
*    This will contain the class definition of:
*        Vector         : A class that creates an array of any type
*        VectorIterator : An interator through Vector
* Author
*    Donovan Gregory
************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

#include <cassert>
#include <iostream>

// forward declaration for ContainerIterator
template <class T>
class VectorIterator;

template <class T>
class VectorConstIterator;

/************************************************
 * CONTAINER
 * A class that holds stuff
 ***********************************************/
template <class T>
class Vector
{
public:
   // default constructor : empty and kinda useless
   Vector() : numItems(0), iCapacity(0), data(NULL) {}

   // copy constructor : copy it
   Vector(const Vector & rhs) throw (const char *);
   
   // non-default constructor : pre-allocate
   Vector(int capacity) throw (const char *);
   
   // destructor : free everything
   ~Vector()        { if (iCapacity) {delete [] data;}}

   T & operator [] (int index) throw(bool);

   const T & operator [] (int index) const throw(bool);
   
   // copy using assignment opperator
   Vector & operator = (const Vector & rhs) throw (const char *);
   
   // is the container currently empty
   bool empty() const  { return numItems == 0;         }

   // remove all the items from the container
   void clear()        { numItems = 0;                 }

   // how many items are currently in the container?
   int size() const    { return numItems;              }

   //how big is the container
   int capacity() const { return iCapacity;             }

   // add an item to the container
   void push_back(const T & t) throw (const char *);
   
   // return an iterator to the beginning of the list
   VectorIterator <T> begin() { return VectorIterator<T>(data); }

   // return an iterator to the end of the list
   VectorIterator <T> end() { return VectorIterator<T>(data + numItems);}

   // return an iterator to the beginning of the list
   VectorIterator <T> cbegin() const { return VectorConstIterator<T>(data); }

   // return an iterator to the end of the list
   VectorIterator <T> cend() const { return VectorConstIterator<T>(data + numItems);}
   
private:
   T * data;          // dynamically allocated array of T
   int numItems;      // how many items are currently in the Container?
   int iCapacity;     // how many items can I put on the Container before full?
};

/**************************************************
 * VECTOR ITERATOR
 * An iterator through Vector
 *************************************************/
template <class T>
class VectorIterator
{
  public:
   // default constructor
  VectorIterator() : p(NULL) {}

   // initialize to direct p to some item
  VectorIterator(T * p) : p(p) {}

   // copy constructor
   VectorIterator(const VectorIterator & rhs) { *this = rhs; }

   // assignment operator
   VectorIterator & operator = (const VectorIterator & rhs)
   {
      this->p = rhs.p;
      return *this;
   }

   bool operator == (const VectorIterator & rhs) const
   {
      return rhs.p == this->p;
   }
   
   // not equals operator
   bool operator != (const VectorIterator & rhs) const
   {
      return rhs.p != this->p;
   }

   // dereference operator
   T & operator * ()
   {
      return *p;
   }

   // prefix increment
   VectorIterator <T> & operator ++ ()
   {
      p++;
      return *this;
   }

   // postfix increment
   VectorIterator <T> operator++(int postfix)
   {
      VectorIterator tmp(*this);
      operator ++ ();
      return tmp;
   }

   VectorIterator <T> & operator -- ()
   {
      p--;
      return *this;
   }

   VectorIterator <T> & operator -- (int decrement)
   {
      VectorIterator tmp(*this);
      operator -- ();
      return tmp;
   }
   
  private:
   T * p;
};
/*******************************************
 *
 *******************************************/
template <class T>
class VectorConstIterator
{
  public:
   // default constructor
  VectorConstIterator() : p(NULL) {}

   // initialize to direct p to some item
  VectorConstIterator(T * p) : p(p) {}

   // copy constructor
   VectorConstIterator(const VectorConstIterator & rhs) { *this = rhs; }

   // assignment operator
   VectorConstIterator & operator = (const VectorConstIterator & rhs)
   {
      this->p = rhs.p;
      return *this;
   }

   bool operator == (const VectorConstIterator & rhs) const
   {
      return rhs.p == this->p;
   }

   // not equals operator
   bool operator != (const VectorConstIterator & rhs) const
   {
      return rhs.p != this->p;
   }

   // dereference operator
   T & operator * ()
   {
      return *p;
   }

   // prefix increment
   VectorConstIterator <T> & operator ++ ()
   {
      p++;
      return *this;
   }

   // postfix increment
   VectorConstIterator <T> operator++(int postfix)
   {
      VectorConstIterator tmp(*this);
      operator ++ ();
      return tmp;
   }

   VectorConstIterator <T> & operator -- ()
   {
      p--;
      return *this;
   }

   VectorConstIterator <T> & operator -- (int decrement)
   {
      VectorConstIterator tmp(*this);
      operator -- ();
      return tmp;
   }

  private:
   T * p;
};

/*******************************************
 * Vector :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
Vector <T> :: Vector(const Vector <T> & rhs) throw (const char *)
{
   assert(rhs.iCapacity >= 0);
      
   // do nothing if there is nothing to do
   if (rhs.iCapacity == 0)
   {
      iCapacity = numItems = 0;
      data = NULL;
      return;
   }

   // attempt to allocate
   try
   {
      data = new T[rhs.iCapacity];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a new buffer for Vector";
   }
   
   // copy over the capacity and size
   assert(rhs.numItems >= 0 && rhs.numItems <= rhs.iCapacity);
   iCapacity = rhs.iCapacity;
   numItems = rhs.numItems;

   // copy the items over one at a time using the assignment operator
   for (int i = 0; i < numItems; i++)
      data[i] = rhs.data[i];

   // the rest needs to be filled with the default value for T
   for (int i = numItems; i < iCapacity; i++)
      data[i] = T();
}

/**********************************************
 * Vector : NON-DEFAULT CONSTRUCTOR
 * Preallocate the container to "capacity"
 **********************************************/
template <class T>
Vector <T> :: Vector(int iCapacity) throw (const char *)
{
   assert(iCapacity >= 0);
   
   // do nothing if there is nothing to do
   if (iCapacity == 0)
   {
      this->iCapacity = this->numItems = 0;
      this->data = NULL;
      return;
   }

   // attempt to allocate
   try
   {
      data = new T[iCapacity];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a new buffer for Vector";
   }

      
   // copy over the stuff
   this->iCapacity = iCapacity;
   this->numItems = 0;

   // initialize the container by calling the default constructor
   for (int i = 0; i < iCapacity; i++)
      data[i] = T();
}

/***************************************************
 * Vector :: PUSH_BACK
 * Insert an item on the end of the vector
 **************************************************/
template <class T>
void Vector <T> :: push_back(const T & t) throw (const char *)
{
   T * temp;
   // do we have space?
   if(numItems >= iCapacity)
   {
      if (iCapacity == 0)
         iCapacity = 1;
      else 
         iCapacity *= 2;
   
      try
      {
         temp = new T[iCapacity];
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a new buffer for Vector";
      }
      for(int i = 0; i < numItems; ++i)
      {
         temp[i] = data[i];
      }
      delete[] data;
      data = temp;
   }
   
   // add an item to the end
   data[numItems++] = t;
}

template <class T>

T & Vector <T>:: operator [] (int index) throw(bool)
{
   if(index < 0 || index >= numItems)
      throw "ERROR: INVALID index";
   return data[index];
}

template <class T>
const T & Vector <T>:: operator [] (int index) const throw(bool)
{
   if(index < 0 || index >= numItems)
      throw "ERROR: INVALID index";
   return data[index];
}
template <class T>

Vector <T> & Vector <T>:: operator = (const Vector & rhs) throw (const char *)
{
   delete [] data;
   this->numItems = rhs.numItems;
   this->iCapacity = rhs.iCapacity;
   try
   {
      data = new T [iCapacity];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a new buffer for Vector";
   }
   
   for(int i = 0; i < numItems; i++)
      data[i] = rhs.data[i];
   for (int i = numItems; i < iCapacity; i++)
      data[i] = T();
   return *this;
}



#endif // Vector_H

