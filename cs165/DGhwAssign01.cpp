/***********************************************************************
* Program:
*    Assignment 01, Genetic Genealogy            
*    Brother Ercanbrack, CS165
* Author:
*    Donovan Gregory
* Summary: 
*    This program will ask the user for their DNA sequence. Then ask for the
*    number of family members and their DNA sequence. The program will then
*    compare the DNA and tell the percentage that they are similar. 
*
*    Estimated:  1.5 hrs   
*    Actual:     3.0 hrs
*      The tutor taking my computer and destroying my code. I had to
*      rebuild the code from scratch. Besides that I just had to remember
*      to have the extra space in an array so that there can be a 0.
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/**********************************************************************
 * Main will call dnaUser to get the users DNA sequence. Then call the
 * function numRelatives to ask for the number of potential realtives.
 * Then it will call nameRealatives to save the names to an array. Then
 * dnaRelatives will save the DNA of the relatives to the array. Finally
 * main will call displayPercentage to display the relative and percentage
 * they are similar. 
 ***********************************************************************/
void dnaUser(char selfDNA[11]) //Prompts user for their DNA //
{
   
   
   cout << "Enter your DNA sequence: ";
   cin >> selfDNA;
  
}

void numRelatives(int &numRel) //Prompts user for number of relatives
{
 cout << "Enter the number of potential relatives: ";
 cin >> numRel;
}

void nameRelatives(int numRel, char relName[][256])       
{
 for (int i = 0; i < numRel; i++)
 {
    cout << "Please enter the name of relative #" << i+1 << ": ";
    cin >> relName[i];
 }
}

void dnaRelatives(int numRel, char dnaArray[][11], char relName[][256])
/* Prompts user for relatives DNA and saves it to another array */                                                                  
{
     for (int i = 0; i < numRel; i++)
    {
     cout << "Please enter the DNA sequence for " << relName[i] << ": ";
     cin >> dnaArray [i];
    }
}

void displayPercent(int numRel, char dnaArray[][11], char relName[][256],
                    char selfDNA[11])
// Compares DNA and generates the percent it is similar. 
{
   
    for (int i = 0; i < numRel; i++) // cycles through relatives
       {
          int percent = 0;
          for (int s = 0; s < 10; s++) // cycles through DNA
          {
             
             if (dnaArray [i][s] == selfDNA[s])
             {
                percent+=10;
             }
          }
         cout << "Percent match for " << relName[i] << ": "
              << percent <<"\%\n";
       }
}
            
      
int main()
{
   char selfDNA[11];
   char dnaArray[50][11] = {0};
   char relName[50][256] = {0};
   int numRel= 0;
   dnaUser(selfDNA);
   numRelatives(numRel);
   cout << endl;
   nameRelatives(numRel, relName);
   cout << endl;
   dnaRelatives(numRel, dnaArray, relName);
   cout << endl;
   displayPercent(numRel,  dnaArray, relName, selfDNA);
   return 0;
}
