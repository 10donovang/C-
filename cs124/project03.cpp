/***********************************************************************
* Program:
*    Project 03, Budget part 2        
*    Brother Falin, CS124
* Author:
*    Donovan Gregory
* Summary: 
*    The program will ask the user for their budget and then it will display
*    their budget.
*
*    Estimated:  1.0 hrs   
*    Actual:     1.0 hrs
*      Remembering that I always need to declare the variable as whatever
*       it is when it's being called in a function. 
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;
/**********************************************************************
 *Prompt the user for their monthly income. 
 **********************************************************************/
float getIncome()
{
   float income;
   cout << "\tYour monthly income: ";
   cin >>  income;

   return  income;

}
/**********************************************************************
 *Ask for the living expenses.
 **********************************************************************/
float getBudgetLiving()
{
   
   float living;
   cout << "\tYour budgeted living expenses: ";
   cin >>  living;

   return  living;
}
/**********************************************************************
 *Prompts user for actual living expense.
 **********************************************************************/
float getActualLiving()
{
   
   
   float aliving;
   cout << "\tYour actual living expenses: ";
   cin >>  aliving;

   return  aliving;
}
/**********************************************************************
 *Prompts users for actual taxes.
 **********************************************************************/
float getActualTax()
{
   
   
   float atax;
   cout << "\tYour actual taxes withheld: ";
   cin >>  atax;
   return  atax;
}
/**********************************************************************
 *Prompts users for actual tithing. 
 **********************************************************************/
float getActualTithing()
{
   
   float atithe;
   cout << "\tYour actual tithe offerings: ";
   cin >>  atithe;
   return  atithe;
}
/**********************************************************************
 *Prompts user for actual other money spent. 
 **********************************************************************/
float getActualOther()
{
   
   
   float aother;
   cout << "\tYour actual other expenses: ";
   cin >>  aother;
   return  aother;
}
/**********************************************************************
 *Figures out real tithing
 **********************************************************************/
float computeTithing(float income)
{
   float tithe;
   tithe = income * .10;
   return tithe;
}

/**********************************************************************
 *Display Budget. 
 **********************************************************************/

void display(float income,float living,float atax,float aliving,float atithe,
             float aother)
{

   
   float tax = 0;
   
   float tithe = computeTithing(income);
   float other = income - tithe - living;
   float adifference = income - atax - atithe - aliving - aother;
   float difference = 0;
   
   
    // Display results
   cout << "The following is a report on your monthly expenses\n";
   cout <<"\tItem" << setw(24) << "Budget" << setw(17) << "Actual\n";
   cout <<"\t=============== =============== ===============\n";
   cout << "\tIncome" << setw(11) << "$" << setw(11) << income << setw(5)
        << "$" << setw(11) << income << endl;
   cout << "\tTaxes" << setw(12) << "$" << setw(11) << tax << setw(5)
        << "$" << setw(11) << atax << endl;
   cout << "\tTithing" << setw(10) << "$" << setw(11) << tithe << setw(5)
        << "$" << setw(11) << atithe << endl;
   cout << "\tLiving" << setw(11) << "$" << setw(11) << living << setw(5)
        << "$" << setw(11) << aliving << endl;
   cout << "\tOther" << setw(12) << "$" << setw(11) << other << setw(5) << "$"
       << setw(11) << aother << endl;
   cout <<"\t=============== =============== ===============\n";   
   cout << "\tDifference" << setw(7) << "$" << setw(11)
        << difference << setw(5)
        << "$" << setw(11) << adifference << endl;
   return; 
}
/**********************************************************************
 * Asks the user for their budget and then creates a table based on what the
 * user inputs. It will work on several programs computing what is going on. 
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
  
       
   // prompt the user for their income
   cout << "This program keeps track of your monthly budget\n";
   cout << "Please enter the following:\n";

   float income = getIncome();
   float living =  getBudgetLiving();
   float aliving = getActualLiving();
   float atax =  getActualTax();
   float atithe = getActualTithing();
   float aother = getActualOther();
  
   cout << "\n";

   display( income, living,  atax,  aliving,  atithe,
            aother);

  
      
   return 0;
}


   











   
   
   
