/***********************************************************************
* Program:
*    Project 07, Calender          
*    Brother Falin, CS124
* Author:
*   Donovan Gregory
* Summary: 
*    Create a program that will display the month and year with all of the
*    days of the month, offset by the day of the week the first day falls on
*
*    Estimated:  3.0 hrs   
*    Actual:     2.5 hrs
*      The most difficult part was getting the offset right. I realized I
*      counting all the days from the year to begin with. So I cam up with
*      year count and month count to deal with that. 
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Main calls the functions to ask for the month and year. Then the function
 * to compute offset. Then displays offset. 
 ***********************************************************************/
// ask the user for the month with errors if outside 1 to 12
int inputMonth()
{
   int month = 0;
   cout << "Enter a month number: ";
   cin >> month;
   while ( month < 1 || month > 12)
   {
      cout << "Month must be between 1 and 12.\n"
           << "Enter a month number: ";
      cin >> month;
   }
   return month;
}

//ask the user for input for the year with error if it is before 1753
int inputYear()
{
   int year = 0;
   cout << "Enter year: ";
   cin >> year;
   while (year < 1753)
   {
      cout << "Year must be 1753 or later.\n"
           << "Enter year: ";
      cin >> year;
   }
   return year;
}

// checks to see if the year is a leap year
bool isLeapYear(int aYear)
{
   return (aYear % 400 == 0) || (aYear % 100 != 0 && aYear % 4 == 0);
}

// counts the number of days in the month
int daysInMonth(int months, int year)
{
   int days;
   if (months == 1)
      days = 31;
   else if (months == 2 && isLeapYear(year))
      days = 29;
   else if (months == 2)
      days = 28;
   else if (months == 3)
      days = 31;
   else if (months == 4)
      days = 30;
   else if (months == 5)
      days = 31;
   else if (months == 6)
      days = 30;
   else if (months == 7)
      days = 31;
   else if (months == 8)
      days = 31;
   else if (months == 9)
      days = 30;
   else if (months == 10)
      days = 31;
   else if (months == 11)
      days = 30;
   else if (months == 12)
      days = 31;
  
   return days;
}

// calculates the offset for the calander display and the start days

int calculateOffset(int year, int month)
{
   int daysInYear = 0;
   int yearCount = 0;
   int monthCount = 0;
   int months = 1;
   
   for (int aYear = 1753; aYear < year; aYear++)
   {
      daysInYear = daysInYear + 365;
      if (isLeapYear(aYear))
         yearCount++;
   }

   for (int aMonth = 1; aMonth < month; aMonth++)
   {
      monthCount = monthCount + daysInMonth(months, year);
      months++;
   }
   
   int offset = (daysInYear + yearCount + monthCount) % 7;
   return offset;
}

//displays the calander

void display(int offset, int month, int year)
{
   int day = 0;
   

   cout << endl;
   if (month == 1)
      cout << "January";
   else if (month == 2)
      cout << "February";
   else if (month == 3)
      cout << "March";
   else if (month == 4)
      cout << "April";
   else if (month == 5)
      cout << "May";
   else if (month == 6)
      cout << "June";
   else if (month == 7)
      cout << "July";
   else if (month == 8)
      cout << "August";
   else if (month == 9)
      cout << "September";
   else if (month == 10)
      cout << "October";
   else if (month == 11)
      cout << "November";
   else if (month == 12)
      cout << "December";

   cout << ", " << year << endl;
   
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";
   if (offset == 0)
   {
      day = 2;
      cout << setw(5);
   }
   else if (offset == 1)
   {
      day = 3;
      cout << setw(9);
   }
   else if (offset ==2)
   {
      day = 4;
      cout << setw(13);
   }
   else if (offset == 3)
   {
      day = 5;
      cout << setw(17);
   }
   else if (offset == 4)
   {
      day = 6;
      cout << setw(21);
   }
   else if (offset == 5)
   {
      day = 7;
      cout << setw(25);
   }
   else if (offset == 6)
   {
      day = 1;
      cout << setw(1);
   }
  
  
   for (int numDay = 1; numDay <= daysInMonth(month, year); numDay++)
   {
      cout << " " << setw(3) <<  numDay;
      ++day;
      if (day == 8)
      {
         cout << endl;
         day = 1;
      }
   }
   if (day >= 2 && day <= 7)
      cout << endl;

   return;
}

//Calls the different functions to display the calander

int main()
{
   int month = inputMonth();
   int year = inputYear();
   int offset = calculateOffset(year, month);
   display(offset, month, year);
   return 0;
}