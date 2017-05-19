/***********************************************************************
* Program:
*    Checkpoint 08a, Inheritance
*    Brother Ercanbrack, CS165
* Author:
*    Donovan Gregory
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

// For this assignment, for simplicity, you may put all of your classes
// in this file.

// TODO: Define your Book class here
class Book
{
private:
   std::string title;
   std::string author;
   int publicationYear;
public:
   void setTitle(){string newTitle; cout << "Title: ";
      getline(cin, newTitle); this->title = newTitle;}

   string getTitle()const {return title;}

   void setAuthor()
   {string newAuthor; cout << "Author: ";
      getline(cin, newAuthor); this->author = newAuthor;}

   string getAuthor()const {return author;}

   void setYear()
   {int newYear; cout << "Publication Year: ";
      cin >> newYear; cin.ignore(); this->publicationYear = newYear;}

   int getYear()const {return publicationYear;}
};

// TODO: Define your TextBook class here

class TextBook : public Book
{
private:

   std::string subject;

public:

   void setSubject()
   {string newSubject; cout<< "Subject: ";
      getline(cin, newSubject); this->subject = newSubject;}

   string getSubject()const {return subject;}
};

// TODO: Add your PictureBook class here

class PictureBook : public Book

{
private:

   std::string illustrator;

public:

   void setIllustrator()
   {string newIllustrator; cout << "Illustrator: ";
      getline(cin, newIllustrator); this->illustrator = newIllustrator;}

   string getIllustrator()const {return illustrator;}
};


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // Declare a Book object here and call its methods
   Book book1;
   book1.setTitle();
   book1.setAuthor();
   book1.setYear();

   cout << endl << book1.getTitle() << " (" << book1.getYear() << ")" << " by "
        << book1.getAuthor() << endl << endl;


   // Declare a TextBook object here and call its methods
   TextBook text1;
   text1.setTitle();
   text1.setAuthor();
   text1.setYear();
   text1.setSubject();
   cout << endl << text1.getTitle() << " (" << text1.getYear() << ")" << " by "
        << text1.getAuthor() << endl << "Subject: " << text1.getSubject()
        << endl << endl;

   // Declare a PictureBook object here and call its methods
   PictureBook picture1;
   picture1.setTitle();
   picture1.setAuthor();
   picture1.setYear();
   picture1.setIllustrator();

   cout << endl << picture1.getTitle() << " (" << picture1.getYear()
        << ")" << " by " << picture1.getAuthor() << endl << "Illustrated by "
        << picture1.getIllustrator() <<endl;
   return 0;
}

