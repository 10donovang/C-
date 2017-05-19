/***********************************************************************
* Program:
*    Assignment 30, Array Syntax           
*    Brother Falin, CS124
* Author:
*    Donovan Gregory
* Summary: 
*    Calls function to prompt the user for 10 grades, passing it as an array.
*    Then it will call another function to average the numbers in the aray.
*    FInally it will display the results. 
*
*    Estimated:  0.75 hrs   
*    Actual:     0.5 hrs
*      Finding out the difference between creating a character array verus
*      a interger array. 
************************************************************************/

#include <iostream>
using namespace std;
void getGrades(int grades[]);
float averageGrades(int grades[]);
void display(float average);

/**********************************************************************
 * Requests input from the user and saves ten different grades into an array.
 * The it gives the average of the array. 
 ***********************************************************************/
int main()
{
   int grades[256];
   getGrades(grades);
   float average = averageGrades(grades);
   display(average);
   return 0;
}

//Sends a loop that asks the user for 10 grades and sets them in an array

void getGrades(int grades[])
{     
   for (int n = 0; n <= 9; n++)
   {
      cout << "Grade " << n + 1<< ": ";
      cin >> grades[n];
   }
}

//Adds all the numbers in the array and divides by 10 to find the average

float averageGrades(int grades[])
{
   float sum = 0;
   float average = 0;
   for (int i = 0; i <= 9; i++)
      sum += grades[i];
   average = sum / 10;
   return average;
}

void display(float average)
{
   cout << "Average Grade: " << average << "%\n";
   return;
}
      
      
   

