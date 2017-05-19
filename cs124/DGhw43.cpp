/***********************************************************************
* Program:
*    Assignment 43, Command Line        
*    Brother Falin, CS124
* Author:
*    Donovan Gregory
* Summary: 
*    Converts feets  to meters.
*
*    Estimated:  0.5 hrs   
*    Actual:     0.5 hrs
*      Learning what argc and argv is. 
************************************************************************/
#include <cstdlib>
#include <iostream>
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main(int argc, char ** argv)
{
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(1);
  float feet = 0;
  float meters = 0;
  for(int i = 1; i < argc; i++) 
    {
      feet = atof(argv[i]);
      meters = .3048 * feet;
      cout << feet << " feet is " << meters << " meters\n";
    }
      
   return 0;
}
