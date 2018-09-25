/***********************************************************************
* Program:
*    Checkpoint 03a, Exceptions            
*    Brother Ercanbrack, CS165
* Author:
*    Donovan Gregory
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
void prompt(int &num)throw(string)
{
   cout << "Enter a number: ";
   cin >> num;
   if (num < 0)
   {
      throw string("The number cannot be negative.");
   }
   else if (num > 100)
   {
      throw string("The number cannot be greater than 100.");
   }
   else if (num % 2 != 0)
   {
      throw string ("The number cannot be odd.");
   }
   
     
   
}
   
int main()
{
   int num;
   try
   {
      prompt(num);
   }
      catch (string message)
      {
         cout << "Error: " << message << endl;
      }
      
      cout << "The number is: " << num << ".\n";
   
   return 0;
}
