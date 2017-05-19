/***********************************************************************
* Program:
*    Assignment 26, Files          (e.g. Assignment 01, Hello World)  
*    Brother Files, CS124
* Author:
*   Donovan Gregory
* Summary: 
*   Write the program to read 10 grades from a file and display the average. 
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;
void getFilename(char fileName[11]);
float readFile(char fileName[11]);
void display(float average);

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   cout.precision(0);
   cout.setf(ios::fixed);
   char fileName[256];
   getFilename(fileName);
   float average = readFile(fileName);
   if(false)
      return 0;
    display(average);
   return 0;
}

void getFilename(char fileName[])
{
   cout << "Please enter the filename: ";
   cin >> fileName;
}

float readFile(char fileName[])
{
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Error reading file \"" << fileName << "\"" << endl;
      return false;
   }
    
   
   float data;
   float sum = 0;
   while(fin >> data)
      sum += data;
   fin.close();   
   
   float average = sum/10;
  
   
   return average;
}

void display(float average)
{
   cout << "Average Grade: " << average << "%\n";
   return;
}
      
