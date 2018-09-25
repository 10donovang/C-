/***********************************************************************
* Program:
*    Checkpoint 01a, prepare           
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
int main()
{
   char  name[256];
   int age;
   cout << "Hello CS 165 World!" << endl
        << "Please enter your first name: ";
   cin >> name;
   cout << "Please enter your age: ";
   cin >> age;
   cout << endl << "Hello " << name << ", you are " << age << " years old.\n";
  
   return 0;
}
