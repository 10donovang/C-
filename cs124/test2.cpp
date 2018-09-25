/***********************************************************************
* Program:
*    Test 2,         
*    Brother Falin, CS124
* Author:
*    Donovan Gregory
* Summary: 
*    Asks the user for the number of boxes sold at each house until the user
*    inputs 0. The program will keep a runing total and then multiple it by
*    the cost per box to get the total amount of money.
*
*    Estimated:  1.0 hrs   
*    Actual:     0.1 hrs
*      Nothing was difficult.
************************************************************************/

#include <iostream>
using namespace std;
/**********************************************************************
 * Function: totalBoxesSold
 * Purpose: calculate the total number of boxes sold at each house.
 * Output: totalBoxes
 ***********************************************************************/
int totalBoxesSold()
{
   int totalBoxes = 0;
   int boxes = 0;
   do
   {
      totalBoxes += boxes;
      cout << "Number of boxes sold: ";
      cin >> boxes;
   }
   while(boxes != 0);
   return totalBoxes;
}

/*************************************************************************
 * Function: display
 * Purpose: finds total price and displays it to the screen
 *************************************************************************/

void display(int totalBoxes)
{
   float totalMoney = totalBoxes * 3.75;
   cout << "Total amount: $" << totalMoney << endl;
   return;
}

/*************************************************************************
 * Function: Main
 * Purpose: Calls totalBoxesSold and then calls Display. Initilizing
 * total boxes to totalBoxesSold function and passing the variable into
 * display.
 *************************************************************************/

int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   int totalBoxes = totalBoxesSold();
   display(totalBoxes);
   return 0;
}
