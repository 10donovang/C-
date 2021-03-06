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

struct Scripture
{
   char book[32];
   int chapter;
   int verse;
};

struct Insight
{
   Scripture scripture;
   char insight[1024];
};

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
void displayScripture(Scripture scripture)
{
   cout << scripture.book << " "
        << scripture.chapter << ":"
        << scripture.verse << endl;
}

void displayInsight(Insight insight)
{
   displayScripture(insight.scripture);

   cout << "An insight is: "
        << insight.insight
        << endl;
}

Insight promptInsight(Scripture scripture)
{
   Insight insight;
   insight.scripture = scripture;

   cout << "Please provide an insight for the verse: ";
   cin.getline(insight.insight, 1024);

   return insight;
}

Scripture promptScripture()
{
   Scripture scripture;
   cout << "Enter a book: ";
   cin.getline(scripture.book, 32);
   cout << "Enter a chapter: ";
   cin >> scripture.chapter;
   cout << "Enter a verse: ";
   cin >> scripture.verse;
   cin.ignore();

   return scripture;
}

int main()
{
   Scripture scriptures[3];
   Insight insights[3];
   for(int arg = 0; arg < 3; arg++)
   {
      scriptures[arg] = promptScripture();
      insights[arg] = promptInsight(scriptures[arg]);
   }
   for(int arg = 0; arg < 3; arg++)
      displayInsight(insights[arg]);
   return 0;
}
