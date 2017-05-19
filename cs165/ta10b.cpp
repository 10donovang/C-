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
#include <vector>
#include <string>
#include <list>
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
void promptNumbers(list<int> & numbers)
{
   int num;
   do 
   {
      cout << "Please enter int: ";
      cin >> num;
      cin.ignore();
      numbers.push_back(num);
   }
   while(num != 0);
   return;
}

void displayNumbers(const list<int>numbers)
{
   list <int> :: iterator it = numbers.begin();
  
   for (it = numbers.begin(); it != numbers.end(); it++)
   {
      cout << *it << endl;
   }
   return;
}

void removeOdds(list<int>&numbers)
{
   for(list <int> :: iterator it = numbers.begin(); it != numbers.end();
   it++)
   {
      if(*it % 2 != 0)
      {
         it = numbers.erase(it);
         it--;
      }
   }
   return;
}

int main()
{
   list <int> numbers;
   promptNumbers(numbers);
   cout << "Here are your numbers: \n";
   displayNumbers(numbers);
   removeOdds(numbers);
   cout << "Here are your odd numbers: \n";
   displayNumbers(numbers);
   numbers.clear();
   return 0;
}
