/***********************************************************************
* Program:
*    Assignment 14, Matthew 18:21-22
*    Brother Falin, CS124
* Author:
*    Donovan Gregory
* Summary: 
*    This program will address Peter's question to the Lord in 
*    Matthew 18:21-22
*
*    Estimated:  0.75 hrs   
*    Actual:     1.0 hrs
*      Nothing
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
* You are not allowed to change MAIN in any way; just implement the two
* functions: questionPeter() and responseLord()
***********************************************************************/
int responseLord()
{
   int response = 7 * 70;
   return response;
}


int questionPeter()
{
   cout << "Lord, how oft shall my brother sin against me, and I forgive ";
   cout << "him?\n";
   cout << "Till seven times?\n";
   return 0;
}

int main()
{
   // ask Peter's question
   questionPeter();

   // the first part of the Lord's response
   cout << "Jesus saith unto him, I say not unto thee, Until seven\n";
   cout << "times: but, Until " << responseLord() << ".\n";
   
   return 0;
}


