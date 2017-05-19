/***********************************************************************
* Program:
*    Assignment 13, Expressions  
*    Brother Falin, CS124
* Author:
*    Donovan Gregory
* Summary: 
*    The computer will ask the user for the degrees in Fahrenheit. It will then
*    Do the math to change it to celcius. After this it will display the
*    degrees
*    in Celsius. 
*
*    Estimated:  1.0 hrs   
*    Actual:     0.5 hrs
*      Remembering the different uses for int and float. 
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Requests Fdegrees. Process it to turn it into Cdegrees. Then displays it to
 * the user
 * 
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.precision(0);
   cout << "Please enter Fahrenheit degrees: ";
   int fDegrees = 0;
   cin >> fDegrees;
   float cDegrees = (float) 5 / 9 * (fDegrees - 32);
   cout << "Celsius: " << cDegrees << endl;
   
   return 0;
}
