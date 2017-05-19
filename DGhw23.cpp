/***********************************************************************
* Program:
*    Assignment 23, Loop Syntax          
*    Brother Falin, CS124
* Author:
*    Donovan Gregory
* Summary: 
*    Create a loop that counts all of the multiples of user inputed number
*    and adds them all together. 
*
*    Estimated:  0.5 hrs   
*    Actual:     0.25 hrs
*      Nothing
************************************************************************/

#include <iostream>
using namespace std;


/**********************************************************************
 * The main function will run the three functions that will ask the user
 * for a number, calculate all the multiples under 100 and add them all
 * together and then the last function will display the results. 
 ***********************************************************************/
/***************************************
 * Asks the user for the number we are adding
 ***************************************/
int input()
{
   int number;
   cout << "What multiples are we adding? ";
   cin >>  number;
   return number;
}

int calculations(int number)
{
   int sum = 0;
   int multiples = number;

   for(int count = 1; multiples < 100; count++, multiples = number * count)
   {
      
      sum += multiples;
   }
   return sum;
}

void display(int sum, int number)
{
   cout << "The sum of multiples of " << number << " less than 100 are: "
        << sum << endl;
   return;
}
      

int main()
{
   int number;
   int multiples;
   int sum;
   number = input();
   sum = calculations(number);
   display(sum, number);
   return 0;
}
