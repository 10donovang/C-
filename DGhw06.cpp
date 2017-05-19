/***********************************************************************
* Program:
*    Project 06, Calender          
*    Brother Honeycutt, CS124
* Author:
*   Donovan Gregory
* Summary: 
*    Create a program that will display the month and year with all of the
*    days of the month, offset by the day of the week the first day falls on
*
*    Estimated:  2.0 hrs   
*    Actual:     2.5 hrs
*      The most difficult part was getting the offset right. I realized I
*      counting all the days from the year to begin with. So I cam up with
*      year count and month count to deal with that. 
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Main calls the functions to ask for the month and year. Then the function
 * to compute offset. Then displays offset. 
 ***********************************************************************/
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

bool isLeapYear(int aYear)
{
   return (aYear % 400 == 0) || (aYear % 100 != 0 && aYear % 4 == 0);
}

int daysInMonth(int months, int year)
{
   int days;
   if (months == 1)
       days = 31;
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
   else if (months == 2 && isLeapYear(year))
      days = 29;
   return days;
}


int calculateOffset(int year, int month)
{
   int daysInYear;
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

void display(int offset)
{
   cout << "Offset: " << offset << endl;
   return;
}

int main()
{
   int month = inputMonth();
   int year = inputYear();
   int offset = calculateOffset(year, month);
   display(offset);
   return 0;
}
