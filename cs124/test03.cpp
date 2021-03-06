/***********************************************************************
* Program:
*    Test 3,           (e.g. Assignment 10, Hello World)
*    Brother Falin, CS124
* Author:
*    Donovan Gregorye
* Summary:
*    The program reads in a file and then computes the average grade from all
*    of the file.
*
*    Estimated:  0.5 hrs
*    Actual:     1.0 hrs
*      Protypes for some reason ellude me. 
   ************************************************************************/
#include <fstream>
#include <iostream>
using namespace std;


/**********************************************************************
 * Main will call read file and then saves the file to an array. Then it
 * call find average to figure out the total average of the grades. Finally
 * it will call display.
 ***********************************************************************/

// Saves a fileName that is inputed.


void getFile(char fileName[])
{
   cout << "Please specify the file name: ";
   cin.getline(fileName, 256);
   return;
}

// reads file into an array of floats

bool readFile(char fileName[], float file[], int & wordCount)
{
   ifstream fin;
   fin.open(fileName);

   if(!fin || fin.fail() || !fin.is_open())
   {
      cout << "Unable to open or read file " << fileName << endl;
      return false;
   }

   else
   {

   while(fin >> file[wordCount])
   {
      wordCount++;
   }

   fin.close();
   return true;
   }
}

//cycles through array and then turns adds it together

float getAverage(float file [], int wordCount)
{
   float total = 0;
   for (int i = 0; i < wordCount; i++)
   {
      file[i] = file[i]/40;
      total += file[i];
   }
   return total;
}

// creates precentages and displays it on the screen

void display(float total, int wordCount)
{
   total = total * 100 / wordCount;
   cout << "The average grade on the midterm is " << total << "%\n";
   return;
}

int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(1);
   char fileName[256];
   getFile(fileName);
   float file[100];

   int wordCount = 0;
   bool error;
   error = readFile(fileName, file, wordCount);
   if(error = true)
   {
   float total =  getAverage(file, wordCount);
   display(total, wordCount);
   return 0;
   }
   else
      return 0;

}

