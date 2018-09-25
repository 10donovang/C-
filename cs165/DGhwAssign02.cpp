/***********************************************************************
* Program:
*    Assignment 02, Digital Forensics            
*    Brother Ercanbrack, CS165
* Author:
*    Donovan Gregory
* Summary: 
*    
*
*    Estimated:  2.0 hrs   
*    Actual:     3.5 hrs
*    The program will read a file and save the information to a struct.
*    Finally it will display the information from the file on the screen
*    within the parameters we have requested.
************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct File
{
   char userName[256];
   char fileName[256];
   long timeStamp;
};
/**********************************************************************
 * Main will declare the File record, endtime, starttime, and filename.
 * It will then call the function fName to retrieve the file name. From
 * there it will pass the array to records to retrieve the file information
 * and save it to the File record. From there main will call the function
 * times to get the start and end time. Main will then call display to
 * finish the program. 
 ***********************************************************************/
// Prompts the user for the name of a file.
void fName(char fileName[256])
{
   cout << "Enter the access record file: ";
   cin >> fileName;
   cout << endl;
}

//Reads in a list of records from the file and stores it in a struct.
void records(char fileName[256], File record[501])
{
   ifstream fin;

   fin.open(fileName);

   if(fin.fail())
   {
      cout << "File read error.";
   }

   for (int i = 0; i < 500; i++)
   {
      fin >> record[i].fileName;
      fin >> record[i].userName;
      fin >> record[i].timeStamp;
   }

   fin.close();
}
   
// Prompts user for start time and end time.
void times(long &startTime, long &endTime)
{
   cout << "Enter the start time: ";
   cin >> startTime;
   cout << "Enter the end time: ";
   cin >> endTime;
   cout << endl;
}

//Displays a list of files accessed during that time period.
void display(File record[501], long startTime, long endTime)
{
   cout << "The following records match your criteria:\n"
        << endl
        << setw(15) << "Timestamp"
        << setw(20) << "File"
        << setw(21) << "User\n"
        << "--------------- ------------------- -------------------\n";
   
   for (int j = 0; j < 500; j++)
   {
      if (startTime < record[j].timeStamp && record[j].timeStamp < endTime
          && record[j].timeStamp != 0)
      {
         cout << setw(15) << record[j].timeStamp
              << setw(20) << record[j].fileName
              << setw(20) << record[j].userName
              <<endl;
      }
   }
   cout << "End of records\n";
}

int main()
{
   char fileName[256] = {0};
   File record[501];
   long startTime;
   long endTime;
   fName(fileName);
   records(fileName, record);
   times(startTime, endTime);
   display(record, startTime, endTime);
   return 0;
}
