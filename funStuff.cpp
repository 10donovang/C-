/***********************************************************************
* Program:
*    Assignment ##, ????          (e.g. Assignment 01, Hello World)  
*    Brother {Ellsworth, Comeau, Unsicker, Helfrich}, CS124
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
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int prompt()
{
   int exp;
   cout << "Enter your experience: ";
   cin >> exp;
   return exp;
}

int level(int exp)
{
   int level = 0;
   if(exp >= 0 && exp < 1000)
      level = 1;
   else
      level = 2;
   return level;
   
}

int main()
{
   int exp = prompt();
   int LV = level(exp);
   cout << "Your level is " << LV << endl;
   return 0;
}
