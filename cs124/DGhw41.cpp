/***********************************************************************
* Program:
*    Assignment 41, Allocating Memory         
*    Brother Falin, CS124
* Author:
*    Donovan Gregory
* Summary: 
*    Prompts the user for a number of characters in a string. Then creates
*    a string that is that big. Then asks for the string, then display the
*    strings, finally deletes it. 
*
*    Estimated:  0.5 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   int num = 0;
   cout << "Number of characters: ";
   cin >> num;
   cin.ignore();
   char * pstring = NULL;
   pstring = new (nothrow)char[num + 1];
   if(pstring == NULL)
   {
      cout << "Allocation failure!\n";
      return 0;
   }
   cout << "Enter Text: ";
   cin.getline(pstring , num+1);
   cout << "Text: ";
      for(int i = 0; i < num; i ++)
         cout << pstring[i];
   cout << endl;
   delete [] pstring;
   return 0;
}
