/***********************************************************************
* Program:
*    Assignment 12, Input & Variables      (e.g. Assignment 01, Hello World)  
*    Brother Falin, CS124
* Author:
*    Donovan Gregory
* Summary: 
*    The program will ask the user for their income and then it will display
*    their income.
*
*    Estimated:  1.0 hrs   
*    Actual:     .05 hrs
*      Nothing was challenging. 
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Main will prompt the user for their income, living, actua living, actual
 * taxes, actual tithing, and actual other expenses. It will then create a
 * budget display based on the information. 
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   float income = 0;
      
   cout << "\tYour monthly income: ";
   cin >> income;
   
   cout << "Your income is: $" << setw(9) << income << endl;
      
   return 0;
}
