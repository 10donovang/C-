/***********************************************************************
* Program:
*    Assignment 12, Input & Variables      (e.g. Assignment 01, Hello World)  
*    Brother Honeycutt, CS124
* Author:
*    Donovan Gregory
* Summary: 
*    The program will ask the user for their budget and then it will display
*    their budget.
*
*    Estimated:  1.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Asks the user for their budget and then creates a table based on what the
 * user inputs. 
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   float income;
   float living;
   float aliving;
   float ataxes;
   float atithe;
   float aother;
      
   // prompt the user for their income
   cout << "This program keeps track of your monthly budget\n";
   cout << "Please enter the following:\n";
   cout << "\tYour monthly income: ";
   cin >> income;
   cout << "\tYour budgeted living expenses: ";
   cin >> living;
   cout << "\tYour actual living expenses: ";
   cin >> aliving;
   cout << "\tYour actual taxes withheld: ";
   cin >> ataxes;
   cout << "\tYour actual tithe offerings: ";
   cin >> atithe;
   cout << "\tYour actual other expenses: ";
   cin >> aother;

   cout << "\n";

   // Display results
   cout << "The following is a report on your monthly expenses\n";
   cout <<"\tItem" << setw(24) << "Budget" << setw(17) << "Actual\n";
   cout <<"\t=============== =============== ===============\n";
   cout << "\tIncome" << setw(11) << "$" << setw(11) << income << setw(5)
        << "$" << setw(11) << income << endl;
   cout << "\tTaxes" << setw(12) << "$" << setw(11) << "0.00" << setw(5) << "$"
        << setw(11) << ataxes << endl;
   cout << "\tTithing" << setw(10) << "$" << setw(11) << "0.00" << setw(5)
        << "$" << setw(11) << atithe << endl;
   cout << "\tLiving" << setw(11) << "$" << setw(11) << living << setw(5)
        << "$" << setw(11) << aliving << endl;
   cout << "\tOther" << setw(12) << "$" << setw(11) << "0.00" << setw(5) << "$"
       << setw(11) << aother << endl;
   cout <<"\t=============== =============== ===============\n";   
   cout << "\tDifference" << setw(7) << "$" << setw(11) << "0.00" << setw(5)
         << "$" << setw(11) << "0.00" << endl; 
            return 0;
}
