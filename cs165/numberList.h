/*******************
 * NumberList class
 *******************/
#ifndef NUMBER_LIST_H
#define NUMBER_LIST_H

#include <iostream>
using namespace std;

class NumberList
{
private:
   int size;
   int *array;

public:
   NumberList()
   {
      size = 0;
      array = NULL;
   }


   // TODO: Add your constructor and destructor
   NumberList(int reSize)
   {
      array = new int[reSize];
      size = reSize;
      for(int i = 0; i < reSize; i++)
         array[i] = 0;
   }

   ~NumberList()
   {
      delete array;
      array = NULL;
      cout << "Freeing memory\n";
   }
      


   int getNumber(int index) const;
   void setNumber(int index, int value);
   
   void displayList() const;

};

#endif
