/***********************************************************************
* Program:
*    Assignment 21, Debugging            
*    Brother Falin, CS124
* Author:
*    Donovan Gregory
* Summary: 
*    Creates stubs for a larger program. Make sure all programs are connected
*
*    Estimated:  0.5 hrs   
*    Actual:     0.5 hrs
*      No part of this was really difficult. 
************************************************************************/

#include <iostream>
using namespace std;

float periodicCost();
float  getUsageCost();
void display(float, float);
float promptDevalue();
float promptInsurance();
float promptParking();
float promptMileage();
float promptGas();
float promptRepairs();
float promptTires();



/**********************************************************************
 * Main calls on the other functions to do whatever they would do.
 ***********************************************************************/
int main()
{
   float costPeriodic;
   float costUsage;
   periodicCost();
   getUsageCost();
   display(costUsage, costPeriodic);
   return 0;
}


float periodicCost()
{
   float costPeriodic;
   float cost;
   promptDevalue();
   promptInsurance();
   promptParking();
   return costPeriodic;
}




float getUsageCost()
{
   float costUsage;
   float mileage;
   float cost;
   promptMileage();
   promptGas();
   promptRepairs();
   promptTires();
   return costUsage;
}

void display(float costUsage, float costPeriodic)
{
   cout << "Success\n";
}
   
float promptDevalue()
{
   float cost;
   return cost;
}

float promptInsurance()
{
   float cost;
   return cost;
}

float promptParking()
{
   float cost;
   return cost;
}

float promptMileage()
{
   float mileage;
   return mileage;
}

float promptGas()
{
   float cost;
   return cost;
}

float promptRepairs()
{
   float cost;
   return cost;
}

float promptTires()
{
   float cost;
   return cost;
}
