/***********************************************************************
* Program:
*    Team Project 03, Missle Defense          (e.g. Assignment 10, Hello World)
*    Brother Falin, CS124
* Author:
*    your name
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
float getMissleDistance()
{
   float km;
   cout << "\tEnter the distance of the missile: ";
   cin >> km;
   return km;
}

float convertKilometersToMiles(float km)
{
   float miles = km * .62137;
   return miles;
}

bool shouldFireMissle(float miles)
{
   if (miles <= 30)
      return true;
   else
      return false;
}

int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout << "Super Secret Missile Defense Program\n" << endl;
   float km = getMissleDistance();
   float miles = convertKilometersToMiles(km);
   if (shouldFireMissle(miles) == true)
   {
      if (miles <=30 && miles > 10)
         cout << "\tDistance is " << miles
              << " miles, fire standard missile!\n";
      else if (miles <= 10 && miles >3)
         cout << "\tDistance is " << miles
              << " miles, fire ultra missile!\n";
      else if (miles <=3)
         cout << "\tDistance is " << miles
              << " miles, take cover!\n";
   }
   else
      cout << "\tDistance is " << miles << " miles, hold your fire.\n";
   return 0;
}
