/***********************************************************************
* Program:
*    Assignment ##, ????          (e.g. Assignment 10, Hello World)
*    Brother {Cook, Comeau, Falin, Lilya, Honeycutt, Unsicker, Peterson, Phair, Ellsworth}, CS124
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
#include <string>
#include <fstream>
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int readFile(string fileName);
string getFileName();
void display(int lines, string fileName);

int main(int argc, char **argv)
{
   string fileName;
   if(argc > 1)
      fileName = argv[1];
   else
      fileName = getFileName();
   int lines = readFile(fileName);
   display(lines, fileName);
   return 0;
}

string getFileName()
{
   string fileName;
   cout << "Please enter the file name: ";
   cin >> fileName;
   return fileName;
}

int readFile(string fileName)
{
   ifstream fin;
   string temp;
   int count = 0;
   fin.open(fileName.c_str());
   if (fin.fail())
      return 0;
   while(getline(fin, temp))
   {
      count++;
   }
   fin.close();
   return count;
}

void display(int count, string fileName)
{
   if (count == 0)
      cout << fileName << " is empty.";
   else if (count == 1)
      cout << fileName << " has " << 1 << " line.";
   else if (count > 2)
      cout << fileName << " has " << count << " lines.";
   return;
}
   
