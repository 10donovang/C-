/***********************************************************************
* Program:
*    Assignment 25, Loop Design            
*    Brother Falin, CS124
* Author:
*    Donovan Gregory
* Summary: 
*    Create a loop that will display a calnder based on the number of days
*    and the offset. 
*
*    Estimated:  0.75 hrs   
*    Actual:     1.0 hrs
*      Figuring out the proper set widths. I struggled with that for some
*      reason.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;
int getDays(int days);
int getOffset(int offset);
void display(int days, int offset);

/**********************************************************************
 * Runs the functions to get the days and offsets. Then displays the calander
 * based on the days and offsets. 
 ***********************************************************************/
int main()
{
   int days;
   int offset;
   days = getDays(days);
   
   offset = getOffset(offset);

   display(days, offset);
   
   return 0;
}

int getDays(int days)
{
   cout << "Number of days: ";
   cin >> days;
   return days;
}

int getOffset(int offset)
{
   cout << "Offset: ";
   cin >> offset;
   return offset;
}

void display(int days, int offset)
{
   int day;
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

   for (int numDay = 1; numDay <= days; numDay++)
   {
      cout << " " << setw(3) <<  numDay;
      ++day;
      if(day == 8)
      {
         cout << endl;
         day = 1;
      }
   }
   if (day >= 2 && day <= 7)
      cout << endl;

   return;
}
         
