/***********************************************************************
* Program:
*    Assignment 11, Output          (e.g. Assignment 01, Hello World)  
*    Brother Falin, CS124
* Author:
*    Donovan Gregory
* Summary: 
*    The program will output my monthly budget. Including all of my
*    expenses.
*
*    Estimated:  1.0 hrs   
*    Actual:     1.5 hrs
*      I would say the most difficult part was learning fully how to
*      move to the next line. For some reason I kept having errors.
*      Mostly small stuff. I also have trouble with the amount of time
*      it takes to load the editing. 
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
  * The function is displaying the budget for the month. It is doing this
  * in a set position using both tabs and set width. 
 ***********************************************************************/
int main()
{
   //Configuring the output to display in terms of money
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   
   cout << "\tItem" << setw(21)  << "Projected\n";
   cout << "\t=============" << setw(13) << "==========\n";
   cout << "\tIncome"  << setw(10) <<  "$" << setw(9) << 1000.00 << "\n"; 
   cout << "\tTaxes" << setw (11)  << "$" << setw(9) << 100.00 << "\n";
   cout << "\tTithing"  << setw(9)  << "$" << setw(9) << 100.00 << "\n";
   cout << "\tLiving"  << setw(10)  << "$" << setw(9) << 650.00 << "\n";
   cout << "\tOther"   << setw(11)  << "$" << setw(9) << 90.00 << "\n"; 
   cout << "\t=============" << setw (13) << "==========\n";
   cout << "\tDelta"  << setw (11)       << "$" << setw(9) << 60.00 << "\n";
   return 0;
}
