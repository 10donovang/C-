/***********************************************************************
* Program:
*    Assignment 34, Strings            
*    Brother Falin, CS124
* Author:
*    Donovan Gregory
* Summary: 
*      The program will ask the user for a letter and phrase and then will
*      search the phrase for the letter are return the number of times the
*      letter appears.
*   
* Estimated:  0.5 hrs   
* Actual:     0.5 hrs
*      Remembering how to do a prototype. 
************************************************************************/

#include <iostream>
using namespace std;
int countLetter(char[], char[]);
/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   char letter[2];
   char text [256];
   cout << "Enter a letter: ";
   cin.getline(letter, 2);
   cout << "Enter text: ";
   cin.getline(text, 256);
   int count = countLetter(letter, text);
   cout << "Number of '" << letter << "'s: " << count << endl;
   return 0;
}

int countLetter(char letter[], char text[])
{
   int count = 0;
   for (char *p = text; *p; p++)
   {
      if (letter[0] == *p)
         count ++;
   }
   return count;
}
