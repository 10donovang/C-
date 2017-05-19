/***********************************************************************
* Program:
*    Project 10, MadLib          (e.g. Assignment 10, Hello World)
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
int readFile(char fileName[], char file[][32], int wordCount)
{

   
   ifstream fin;
   fin.open(fileName);

   if(fin.fail())
   {
      return -1;
   }
   
   while(fin >> file[wordCount])
   {
         wordCount++;
   }

   fin.close();
   return wordCount;

}


/***********************************************************
 * Function: promptUser
 * Purpose: Search for and save prompts, put them in an array.
 *          Pretty them up. Asks the user the questions. Save
 *          answers to another array.
 ***********************************************************/

void promptUser(char file[][32], int wordCount, char promptsAnswers[][100],
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
   for(int v = 0; v < promptCount; v++)
   {
      for(int f =0; f < 32; f++)
    
         if (prompt[v][f] == '<')
         prompt[v][f] = '\t';
         
         else if (prompt[v][f] == '>')
         {
            prompt[v][f] = ':';
            prompt[v][f+1] = '\0';
         }
         
         else if (prompt[v][f] == '_')
            prompt[v][f] = ' ';
   }
   
   for(int q = 0; q < promptCount; q++)
   {
      if(islower(prompt[q][1]))
         prompt[q][1] = toupper(prompt[q][1]);
      int h = 0;
      
      if(prompt[q][1] != '#' && prompt[q][1] != '{' && prompt[q][1] != '}'
         && prompt[q][1] != '[' && prompt[q][1] != ']')
      {
         cout << prompt[q] << " ";
         cin.getline(promptsAnswers[q], 256);
         
      }
   }
      
   
   return;
}
/***************************************************************
 * Function: display
 * Purpose: Changes to display format and displays it to the screen
 ***************************************************************/
void display(char file[][32], char promptsAnswers[][100], int wordCount)
{
   int prompts = 0;
   file[0][0] = toupper(file[0][0]);
   cout << file[0];
   for (int dj = 1; dj < wordCount; dj++)
   {  
      if( file[dj][0] == '<')
      {
         if(file[dj][1] == '#')
         {
            file[dj][0] = '\n';
            file[dj][1] = '\0';
            file[dj][2] = '\0';
         }
      
         else if(file[dj][1] == '{')
         {
            if(file[dj-1][0] != '\"' && file[dj-1][0] != '\'' &&
               file[dj-1][0] != '\n')
            {
               file[dj][0] = ' ';
               file[dj][1] = '\"';
               file[dj][2] = '\0';
            }
            else
            {
               file[dj][0] = '\"';
               file [dj][1] = '\0';
               file[dj][2] = '\0';
            }
         }

         else if(file[dj][1] == '}')
         {
            if(file[dj+1][1] != '#')
            {
               file[dj][0] = '\"';
               file[dj][1] = ' ';
               file[dj][2] = '\0';
            }
            else
            {
               file[dj][0] = '\"';
               file[dj][1] = '\0';
               file[dj][2] = '\0';
            }
         }

         else if (file[dj][1] == '[')
         {
            if(file[dj-1][0] !='\'' && file[dj-1][0] != '\"' &&
               file[dj-1][0] != '\n')
            {
               file[dj][0] = ' ';
               file[dj][1] = '\'';
               file[dj][2] = '\0';
            }
            else
            {
               file[dj][0] = '\'';
               file[dj][1] = '\0';
               file[dj][2] = '\0';
            }
         }
         
         else if (file[dj][1] == ']')
         {
            if(file[dj+1][1] != '#')
            {
               file[dj][0] = '\'';
               file[dj][1] = ' ';
               file[dj][2] = '\0';
            }
            else
            {
               file[dj][0] = '\'';
               file[dj][1] = '\0';
               file[dj][2] = '\0';
            }
         }

         if(isalpha(file[dj][1]) && file[dj][0] != '.' && file[dj][0] != ',' &&
                 file[dj][0] != '!' &&
                 file[dj][0] != '\n'&& file[dj][1] != '\'' &&
                 file[dj][1] != '\"' &&
                 file[dj-1][0] != '\'' && file[dj-1][0] != '\"' &&
                 file[dj-1][0] != '\n' && file[dj-1][1] != '\"' &&
                 file[dj-1][1] != '\'' && file[dj][0] != '\"' &&
                 file[dj][0] != '\'' && file[dj][0] !='?')
         {
            cout << " " << promptsAnswers[prompts];
            prompts++;
         }
         else
         {
            cout << promptsAnswers[prompts];
            prompts++;
         }
         
      }
      
      if(file[dj][0] != '<' && file[dj][0] != '.' &&
         file[dj][0] != ',' && file[dj][0] != '!' && file[dj][0] != '\n'&&
         file[dj][1] != '\'' && file[dj][1] != '\"' &&
         file[dj-1][0] != '\'' && file[dj-1][0] != '\"' &&
         file[dj-1][0] != '\n' && file[dj-1][1] != '\"' &&
         file[dj-1][1] != '\'' && file[dj][0] != '\"' &&
         file[dj][0] != '\'' && file[dj][0] != '?')
         {
               cout << " " << file[dj];  
         }
      
      else if(file[dj][0] != '<')
            cout << file[dj];
         
     
    }
   
}
                               
   
/*************************************************************************
  * Runs through promptsanswers and inilizes it to null. Then runs through
  * geting the file, saving the file, prompting for answers and then
  * displaying everything. It then asks if they want to play again and as
  * long as they don't press n it will cycle through.
  ************************************************************************/
   int main()
{
   char replay;
   do
   {
      char promptsAnswers[256][100];
      for(int i = 0; i < 256; i++)
         for(int j = 0; j < 100; j++)
            promptsAnswers[i][j] = '\0';
      int wordCount = 0;
      int promptCount = 0;
      char fileName[256];
      char file[256][32];
      bool fail = false;
      do
      {
      getFile(fileName);
      wordCount = readFile(fileName, file, wordCount);
      if(wordCount < 0)
      {
         cout << "There has been an error. Please try again.";
         fail = true;
      }
      }
      while(fail);
      promptUser(file, wordCount, promptsAnswers, promptCount);
      cout << endl;
      display(file, promptsAnswers, wordCount);
      cout << endl << "Do you want to play again (y/n)? ";
      cin >> replay;
      if(replay != 'n' && replay != 'y')
         cout << "Please enter a valid answers.";
   }
   while (replay != 'n'); 
   cout << "Thank you for playing.\n";
}
