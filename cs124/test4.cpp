/***********************************************************************
* Program:
*    Test 4, ????          (e.g. Assignment 10, Hello World)
*    Brother Falin, CS124
* Author:
*    Donovan Gregory
* Summary: 
*    Reads a filename either form a command line or from within the
*    program. Reads the file counting each word within the file, dispaying
*    the results. 
*
*    Estimated:  0.5 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string getFileName();
int readFile(string fileName);
void display(string fileName, int count);

/**********************************************************************
 * Main will either assign something from the command line to fileName
 * or it will call getFilename to retrieve it. It will then call readFIle
 * counting each word it reads in. Finally it will call display. 
 ***********************************************************************/
int main(int argc, char **argv)
{
   string fileName;
   if(argc > 1)
      fileName = argv[1];
   else
      fileName = getFileName();
   int count = readFile(fileName);
   display(fileName, count);
   return 0;
}

/**************************************************************
 * gets and returnsa file name if it is not in the command line
 **************************************************************/

string getFileName()
{
   string fileName;
   cout << "Please enter the filename: ";
   cin >> fileName;
   return fileName;
}
/**************************************************************
 * Reads a file from filename and will count the number of words
 * in the file.
 **************************************************************/

int readFile(string fileName)
{
   string temp;
   int count = 0;
   ifstream fin;
   fin.open(fileName.c_str());
   if (fin.fail())
      return 0;
   while(fin >> temp)
      count++;
   return count;
}
/**************************************************************
 * Display will take filename and count and display the results
 * based on the number of words.
 **************************************************************/
void display(string fileName, int count)
{
   if(count == 0)
      cout << "The file " << fileName << " has no words.\n";
   else if(count == 1)
      cout << "There is " << count << " word in " << fileName
           << ".\n";
   else if(count > 1)
      cout << "There are " << count << " words in " << fileName
           << ".\n";
}
