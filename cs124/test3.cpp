/***********************************************************************
* Program:
*    Test 03,           (e.g. Assignment 10, Hello World)
*    Brother Falin, CS124
* Author:
*    Donovan Gregorye
* Summary: 
*    The program reads in a file and then computes the average grade from all
*    of the file.
*
*    Estimated:  0.5 hrs   
*    Actual:     0.0 hrs
*      Please describe brief
************************************************************************/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

string getFile();
bool readFile(float fileName, float file[], int wordCount);
float getAverage(float file[], int wordCount);
void display(float total);
/**********************************************************************
 * Main will call read file and then saves the file to an array. Then it
 * call find average to figure out the total average of the grades. Finally
 * it will call display.
 ***********************************************************************/
int main()
{
   string fileName = getFile();
   float file[100];
   
   int wordCount = 0;
   bool error = readFile(fileName, file, wordCount);
   if(!error)
   {
      return 0;
   }
   else
   {
     float total =  getAverage(file, wordCount);
     display(total);
     return 0;
   }
}

string getFile()
{
   string fileName;
   cout << "Please specify the file name: ";
   getline(cin, fileName);
   return fileName;
}
      
bool readFile(string fileName, float file[], int &wordCount)
{  
   ifstream fin;
      fin.open(fileName);

   if(fin.fail())
   {
      cout << "Unable to opem or read file " << fileName << endl;
      return false;
   }

   while(fin >> file[wordCount])
   {
      wordCount++;
   }

   fin.close();
   return true;
}

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

void display(float total)
{
   total = total * 100 / wordCount;
   cout << "The average grade on the midterm is " << total << "%\n";
   return;
}
