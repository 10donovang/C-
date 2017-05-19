/***********************************************************************
* Program:
*    Assignment 33, Pointers          (e.g. Assignment 01, Hello World)  
*    Brother Falin, CS124
* Author:
*   Donovan Gregory
* Summary:
*   A program that has the user input data for their bank accounts
*   and create a pointer that points to their bank account of the higher
*   one. Subtract the date items from the pointer. 
*
*    Estimated:  0.5 hrs   
*    Actual:     0.5 hrs
*      The hardest thing was remembering pass by reference. 
************************************************************************/

#include <iostream>
using namespace std;


/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
void balance(float &samBalance, float &sueBalance)
{
  cout << "What is Sam's balance? ";
  cin >> samBalance;
  cout << "What is Sue's balance? ";
  cin >> sueBalance;
  return;
}

void dateCost(float *pAccount)
{
  float dinner;
  float movie;
  float iceCream;
  cout << "Cost of the date:\n"
       << "\tDinner:    ";
  cin >> dinner;
  cout << "\tMovie:     ";
  cin >> movie;
  cout << "\tIce cream: ";
  cin >> iceCream;
  *pAccount = *pAccount - dinner - movie - iceCream;
}

void display(float samBalance, float sueBalance)
{
  cout << "Sam's balance: $" << samBalance << endl
       << "Sue's balance: $" << sueBalance << endl;
  return;
}

int main()
{
  float *pAccount;
  float samBalance;
  float sueBalance;
  balance(samBalance, sueBalance);
  if (samBalance > sueBalance)
    pAccount = &samBalance;
  else
    pAccount = &sueBalance;
  dateCost(pAccount);
  display(samBalance, sueBalance);
   return 0;
}


  
  
