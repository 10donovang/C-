/***********************************************************************
* Program:
*    Test 1            
*    Brother Falin, CS124
* Author:
*    Donovan Gregory
* Summary: 
*   Create a program that rations how many video games hours can be played.
*    
*    Estimated:  0.5 hrs   
*    Actual:     0.5 hrs
*      Nothing.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Declare the variables. Call the function prompt, then display.
 **********************************************************************/
void prompt(int &today, int &lastWeek)
{
   cout << "How many hours have you played today: ";
   cin >> today;
   cout << "How many hours did you play last week: ";
   cin >> lastWeek;
}

void display(int today, int lastWeek)
{
   if (today > 2 || lastWeek > 8)
      cout << "\tYou have played enough today.\n";
   else
      cout << "\tYou can play for one hour!\n";
}

int main()
{
   int today = 0;
   int lastWeek = 0;
   prompt(today, lastWeek);
   display(today, lastWeek);
   return 0;
}
