/***********************************************************************
* Program:
*    Checkpoint 04a,          (e.g. Checkpoint 01a, review)  
*    Brother Ercanbrack, CS165
* Author:
*    Donovan Gregory
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include<string>
using namespace std;

class Book
{
private:
   string title;
   string author;
public:
   void prompt();
   void display();
};

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
void Book::prompt()
{
   cout << "Title: ";
   getline(cin, title);
   cout << "Author: ";
   getline(cin, author);
}

void Book::display()
{
   cout << "\"" << title << "\" by " << author << endl;
}

int main()
{
   Book book;
   book.prompt();
   book.display();
   return 0;
}
