/***********************************************************************
* Program:
*    Project 09, MadLib          (e.g. Assignment 10, Hello World)
*    Brother Falin, CS124
* Author:
*    Donovan Gregory
* Summary: 
*    The program reads a mad lib file and then saves it into an array. It
*    then finds all of the prompts in the aray and makes them presentable
*    presenting them as questions saving the answers to a seperate array.
*
*    Estimated:  2.0 hrs   
*    Actual:     3.0 hrs
*    The hardest part was getting it to switch to upper case. For
*    some reason it was really giving me problems.
************************************************************************/


/**********************************************************************
 * Main will declare an array for the file name, the file, and the prompt
 * answers. From there it will call get file to fill file name array, then
 * read file to save everything. Finally prompt to get the prompt answers. 
 ***********************************************************************/
#include <iostream>
#include <fstream>
#include <locale>
#include <ctype.h>
using namespace std;

//Asks for a filename
void getFile(char fileName[])
{
   cout << "Please enter the filename of the Mad Lib: ";
   cin >> fileName;
   cin.ignore();
   return;
}


//reads file into a multi array
void readFile(char fileName[], char file[][32], int &wordCount)
{

   
   ifstream fin;
   fin.open(fileName);

   if(fin.fail())
   {
      return;
   }
   
   while(fin >> file[wordCount])
   {
         wordCount++;
   }

   fin.close();
   return;

}


/***********************************************************
 * Function: promptUser
 * Purpose: Search for and save prompts, put them in an array.
 *          Pretty them up. Asks the user the questions. Save
 *          answers to another array.
 ***********************************************************/

void promptUser(char file[][32], int wordCount, char promptsAnswers[],
                int& promptCount)
{
   //create a prompt arrary to save the prompts to
   char prompt[256][32];

   /*search for the signal while saving the prompt count then putting the info
   into the prompt array */
   for(int i = 0; i < wordCount; i++)
   {
      if (file[i][0] == '<')
      {
         for(int k = 0; file[i][k]; k++)
         {
            prompt[promptCount][k] = file[i][k];
         }
         promptCount++;
      }
   }

   
   /* switches making the prompt correct */
   for(int v = 0, f = 0; v < promptCount; f++)
   {
    
         if (prompt[v][f] == '<')
         prompt[v][f] = '\t';
         
         else if (prompt[v][f] == '>')
         {
            prompt[v][f] = ':';
            prompt[v][f+1] = ' ';
            v++;
            f = -1;
         }
         
         else if (prompt[v][f] == '_')
            prompt[v][f] = ' ';
   }
   
   for(int q = 0; q < promptCount; q++)
   {
      if(islower(prompt[q][1]))
         prompt[q][1] = toupper(prompt[q][1]);
 
      if(prompt[q][1] != '#' && prompt[q][1] != '{' && prompt[q][1] != '}'
         && prompt[q][1] != '[' && prompt[q][1] != ']')
      {
         cout << prompt[q];
      cin.getline(promptsAnswers, 256);
      }
   }
      
   
   return;
}

void display(char file[][32], int wordCount, char promptsAnswers[],
             int promptCount)
{
   
}

int main()
{
   char promptsAnswers[256];
   int wordCount = 0;
   int promptCount = 0;
   char fileName[256];
   char file[256][32];
   getFile(fileName);
   readFile(fileName, file, wordCount);
   promptUser(file, wordCount, promptsAnswers, promptCount);
   display(file, wordCount, promptAnswers, promptCount);
   cout << "Thank you for playing.\n";
}
