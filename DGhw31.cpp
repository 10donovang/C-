/***********************************************************************
* Program:
*    Assignment 31, Array Design           
*    Brother Falin, CS124
* Author:
*    Donovan Gregory
* Summary: 
*    Calls function to prompt the user for 10 grades, passing it as an array.
*    Then it will call another function to average the numbers in the aray.
*    FInally it will display the results. 
*
*    Estimated:  0.75 hrs   
*    Actual:     0.25 hrs
*      Reversing my logic so that I completed my function if it did not =-1. 
************************************************************************/

#include <iostream>
using namespace std;
void getGrades(int grades[]);
int averageGrades(int grades[]);
void display(int average);

/**********************************************************************
 * Requests input from the user and saves ten different grades into an array.
 * The it gives the average of the array. 
 ***********************************************************************/
int main()
{
   int grades[256];
   getGrades(grades);
   int average = averageGrades(grades);
  
   display(average);
   return 0;
}

void getGrades(int grades[])
{     
   for (int n = 0; n <= 9; n++)
   {
      cout << "Grade " << n + 1<< ": ";
      cin >> grades[n];
   }
}

int averageGrades(int grades[])
{
   int sum = 0;
   int average = 0;
   int num = 0;
   for (int i = 0; i <= 9; i++)
      if(grades[i] != -1)
         sum += grades[i];
   for (int i =0; i <= 9; i++)
      if(grades[i] != -1)
         num++;
   if (num == 0 && sum == 0)
      return 0;
   average = sum / num;
   return average;
}

void display(int average)
{
    if (average == 0)
        cout << "Average Grade: " << "---%\n";
    else
       cout << "Average Grade: " << average << "%\n";
   return;
}
      
      
   
