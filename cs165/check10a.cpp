/***********************************************************************
* Program:
*    Checkpoint 10a, Vectors
*    Brother Ercanbrack, CS165
* Author:
*    Donovan Gregory
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   vector <int> data;
   vector <string> words;
   int tempData;
   string tempWords;
   do
   {
      cout << "Enter int: ";
      cin >> tempData;
      cin.ignore();
      data.push_back(tempData);
   }
   while(tempData != 0);

   cout << "Your list is:" <<endl;
   for(int i = 0; i < data.size() - 1; i++)
      cout << data[i] << endl;

   data.clear();

   cout << endl;

   do
   {
      cout << "Enter string: ";
      getline(cin, tempWords);
      words.push_back(tempWords);
   }
   while(tempWords != "quit");

   cout << "Your list is:" << endl;
   for (int j = 0; j < words.size() - 1; j++)
      cout << words[j] << endl;

   words.clear();


   return 0;
}


