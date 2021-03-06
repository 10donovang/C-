/***********************************************************************
* Program:
*    Checkpoint 02a, Struct       
*    Brother Ercanbrack, CS165
* Author:
*    Donovan Gregory
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

struct User
{
   char firstName[256];
   char lastName[256];
   int idNumber;
};

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
User input()
{
   User students;
   cout << "Please enter your first name: ";
   cin.getline(students.firstName, 256);
   cout << "Please enter your last name: ";
   cin.getline(students.lastName, 256);
   cout << "Please enter your id number: ";
   cin >> students.idNumber;
   cin.ignore();
   return students;
}

void display(User student)
{
   cout << "Your information:\n"
      << student.idNumber << " - "
        << student.firstName << " "
        << student.lastName << endl;
}

int main()
{
   User student;
   student = input();
   cout << endl;
   display(student);
   
   return 0;
}
