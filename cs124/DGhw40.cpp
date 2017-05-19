/***********************************************************************
* Program:
*    Assignment 40, Multi Demensional Arrays          
*    Brother Falin, CS124
* Author:
*    Donovan Gregory
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  1.0 hrs   
*    Actual:     1.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
void getFileName(char fileName[])
{
   cout << "Enter source filename: ";
   cin.getline(fileName, 256);
}

void readFile(char fileName[], char file[][256], int &wordCount)
{
   ifstream fin;
   fin.open(fileName);
   for(int i = 0; !fin.eof(); i++)
   {
      for(int j = 0; j < 3; j++)
      {
         fin >> file[i][j];
         wordCount++;
      }
   }
   fin.close();
}

void changeFile(char file[][256], int wordCount, char newFile[][256])
{
   char tic;
   for (int i = 0; i < wordCount; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         if(file[i][j] == 'X' || file[i][j] == 'O')
            tic = file[i][j];
         else
            tic = ' ';

         if(j == 0)
         {
            newFile[i][j] = ' ';
            newFile[i][j+1] = tic;
            newFile[i][j+2] = ' ';
            newFile[i][j+3] = '|';
         }

         if(j == 1)
         {
            newFile[i][j+3] = ' ';
            newFile[i][j+4] = tic;
            newFile[i][j+5] = ' ';
            newFile[i][j+6] = '|';
         }
         
         if(j == 2)
         {
            newFile[i][j+6] = ' ';
            newFile[i][j+7] = tic;
            newFile[i][j+8] = ' ';
         }
         
         }
         
         }
   for(int m = 0; m < 11; m++)
   {
      newFile[4][m] = newFile[2][m];
      newFile[2][m] = newFile[1][m];
      newFile[1][m] = '-';
      newFile[3][m] = '-';
   }

   newFile[1][3] = '+';
   newFile[1][7] = '+';
   newFile[3][3] = '+';
   newFile[3][7] = '+';
}

void display(char newFile[][256])
{
   for(int v = 0; v < 5; v++)
   {
      cout << newFile[v] << endl;
   }
}

void saveFile(char newFile[][256])
{
   char saveFile[256];
   char newFileName[256];
   cout << "Enter destination filename: ";
   cin.getline(newFileName, 256);

   saveFile[0] = newFile[0][1];
   saveFile[1] = newFile[0][5];
   saveFile[2] = newFile[0][9];
   saveFile[3] = newFile[2][1];
   saveFile[4] = newFile[2][5];
   saveFile[5] = newFile[2][9];
   saveFile[6] = newFile[4][1];
   saveFile[7] = newFile[4][5];
   saveFile[8] = newFile[4][9];

   
   ofstream fout;
   fout.open(newFileName);

   for(int p = 0; p < 9; p++)
   {
      if(saveFile[p] == ' ')
      {
         saveFile[p] = '.';
      }
      fout << saveFile[p] << endl;
   }
   fout.close();
   return;
}
   
   
int main()
{
   char newFile[256][256];
   char fileName[256];
   char file[256][256];
   int wordCount = 0;
   getFileName(fileName);
   readFile(fileName, file, wordCount);
   changeFile(file, wordCount, newFile);
   display(newFile);
   saveFile(newFile);
   cout << "File written\n"; 
   return 0;
}
