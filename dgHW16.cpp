/***********************************************************************
* Program:
*    Assignment 16, If Statements            
*    Brother Falin, CS124
* Author:
*    Donovan Gregory
* Summary: 
*   Create a program that asks the user for their income and then assignes
*   them into a tax bracket based on their income. 
*
*    Estimated:  0.5 hrs   
*    Actual:     0.5 hrs
*    Remembering to put in new line.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Asks the user for their income, then runs the compute tax function in order
 * to find out the tax bracket. 
 ***********************************************************************/
float computeTax(float income)
{
   if (income > 0 && income <= 15100)
      cout << "Your tax bracket is 10%\n";
   else if (income > 15100 && income <= 61300)
      cout << "Your tax bracket is 15%\n";
   else if (income > 61300 && income <= 123700)
      cout << "Your tax bracket is 25%\n";
   else if (income > 123700 && income <=188450)
      cout << "Your tax bracket is 28%\n";
   else if (income > 188450 && income <= 336550)
      cout << "Your tax bracket is 33%\n";
   else
      cout << "Your tax bracket is 35%\n";
   return 0;
}





int main()
{
   float income;
      cout << "Income: ";
   cin >> income;
   computeTax(income);
      
   return 0;
}
