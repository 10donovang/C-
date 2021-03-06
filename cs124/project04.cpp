/***********************************************************************
* Program:
*    Project 04, Budget part 2        
*    Brother Falin, CS124
* Author:
*    Donovan Gregory
* Summary: 
*    The program will ask the user for their budget and then it will display
*    their budget.
*
*    Estimated:  1.0 hrs   
*    Actual:     1.0 hrs
*      Learning the difference between double and float.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;
/**********************************************************************
 *
 **********************************************************************/
double getIncome()
{
   double income;
   cout << "\tYour monthly income: ";
   cin >>  income;

return  income;

}
/**********************************************************************
 *
 **********************************************************************/
double getBudgetLiving()
{
   
   double living;
   cout << "\tYour budgeted living expenses: ";
   cin >>  living;

   return  living;
}
/**********************************************************************
 *
 **********************************************************************/
double getActualLiving()
{
   
   
   double aliving;
   cout << "\tYour actual living expenses: ";
   cin >>  aliving;

   return  aliving;
}
/**********************************************************************
 *
 **********************************************************************/
double getActualTax()
{
   
   
   double atax;
   cout << "\tYour actual taxes withheld: ";
   cin >>  atax;
   return  atax;
}
/**********************************************************************
 *
 **********************************************************************/
double getActualTithing()
{
   
   double atithe;
   cout << "\tYour actual tithe offerings: ";
   cin >>  atithe;
   return  atithe;
}
/**********************************************************************
 *
 **********************************************************************/
double getActualOther()
{
   
   
   double aother;
   cout << "\tYour actual other expenses: ";
   cin >>  aother;
   return  aother;
}
/**********************************************************************
 *
 **********************************************************************/
double computeTithing(double income)
{
   double tithe;
   tithe = income * .10;
   return tithe;
}
/**********************************************************************
 *
 **********************************************************************/

double computeTax(double income)
{
   double tax;
   double ytax;
   double yincome = income * 12;
    if (yincome > 0 && yincome <= 15100)
      ytax = yincome * .10;
   else if (yincome > 15100 && yincome <= 61300)
      ytax = 1510 + .15 * (yincome - 15100);
   else if (yincome > 61300 && yincome <= 123700)
      ytax = 8440 + .25 * (yincome - 61300);
   else if (yincome > 123700 && yincome <=188450)
      ytax = 24040 + .28 * (yincome - 123700);
   else if (yincome > 188450 && yincome <= 336550)
      ytax = 42170 + .33 * (yincome - 188450);
   else
      ytax = 91043 + .35 * (yincome - 336550);
    tax = ytax / 12;
    
   return tax;
  
}
/**********************************************************************
 *
 **********************************************************************/

void display(double income,double living,double atax,double aliving,
             double atithe, double aother)
{

   
   double tax = computeTax(income);
   
   double tithe = computeTithing(income);
   double other = income - tithe - living - tax;
   double adifference = income - atax - atithe - aliving - aother;
   double difference = 0;
   
   
    // Display results
   cout << "The following is a report on your monthly expenses\n";
   cout <<"\tItem" << setw(24) << "Budget" << setw(17) << "Actual\n";
   cout <<"\t=============== =============== ===============\n";
   cout << "\tIncome" << setw(11) << "$" << setw(11) << income << setw(5)
        << "$" << setw(11) << income << endl;
   cout << "\tTaxes" << setw(12) << "$" << setw(11) << tax << setw(5) << "$"
        << setw(11) << atax << endl;
   cout << "\tTithing" << setw(10) << "$" << setw(11) << tithe << setw(5)
        << "$" << setw(11) << atithe << endl;
   cout << "\tLiving" << setw(11) << "$" << setw(11) << living << setw(5)
        << "$" << setw(11) << aliving << endl;
   cout << "\tOther" << setw(12) << "$" << setw(11) << other << setw(5) << "$"
       << setw(11) << aother << endl;
   cout <<"\t=============== =============== ===============\n";   
   cout << "\tDifference" << setw(7) << "$" << setw(11) << difference << setw(5)
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

   double income = getIncome();
   double living =  getBudgetLiving();
   double aliving = getActualLiving();
   double atax =  getActualTax();
   double atithe = getActualTithing();
   double aother = getActualOther();
  
   cout << "\n";

   display( income, living,  atax,  aliving,  atithe,
            aother);

  
      
   return 0;
}


   











   
   
   
