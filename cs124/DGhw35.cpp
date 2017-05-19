/***********************************************************************
* Program:
*    Assignment 35, Advance Conditionals         
*    Brother Falin, CS124
* Author:
*    Donovan Gregory
* Summary: 
*    The program will turn a grade percentage into a letter grade.
*
*    Estimated:  0.5 hrs   
*    Actual:     0.5 hrs
*      Chosing if statement for the sign.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * The main function asks the user for their grade numerically, then calls
 * function cumpute sign and compute grade to determine the letter grade
 * and sign. Then it displays the results. 
 ***********************************************************************/
char computeLetterGrade(int percentage)
{
  char letter;
  switch (percentage/10)
  {
     case 10:
     case 9: 
       letter = 'A';
       break;
     case 8:
       letter = 'B';
       break;
     case 7:
       letter = 'C';
       break;
     case 6:
       letter = 'D';
       break;
     default:
       letter = 'F';
  }
  return letter;
}

char computeGradeSign(int percentage)
{
  char sign;
  if (percentage > 93)
     sign = '*';
  else if (percentage < 60)
     sign = '*';
  else if (percentage % 10 < 3)
    sign = '-';
  else if (percentage % 10 > 6)
    sign = '+';
  else
    sign = '*';
  return sign;
}
      
    

int main()
{
  int percentage = 0;
  cout << "Enter number grade: ";
  cin >> percentage;
  char letter = computeLetterGrade(percentage);
  char sign = computeGradeSign(percentage);
  if (sign == '*')
  {
     cout << percentage << "% is " << letter << endl;
  }

  else
  {
     cout << percentage << "% is " << letter << sign << endl;
  }

  return 0;
}
