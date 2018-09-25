/***********************************************************************
* Program:
*    Checkpoint 01b, review           
*    Brother Ercanbrack, CS165
* Author:
*    Donovan Gregory
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;



/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
void getSize(int &size) //Function asks user for size of list.
{
   cout << "Enter the size of the list: ";
   cin >> size;
}

void getList(int size, int list[]) // Asks user for each number in list.
{
   
   for (int count = 0; count < size; count++)
   {
      cout << "Enter number for index " << count << ": ";
      cin >> list[count];
   }
   cout << endl;
}

void displayMultiples(int size, int list[]) /* Finds if each of the numbers are
multiples of three */
{
   cout << "The following are divisible by 3:" << endl;
   for (int count = 0; count < size; count++)
      if (list[count]%3 == 0)
      {
         cout << list[count] << endl;
      }
}
      

int main()
{
   int list[20] = {0};
   int size = 0;
   getSize(size);
   getList(size, list);
   displayMultiples(size, list);
   return 0;
}
