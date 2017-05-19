/***********************************************************************
 * Program:
 *    Week 02, Stack
 *    Brother JonesL, CS235
 * Author:
 *    Brian Robertson
 * Summary:
 *    stl stack re-implimentation.
 * Time:
 *      4 hours.
 ************************************************************************/

#include <iostream>    // for ISTREAM and COUT
#include <string>      // for STRING
#include <cassert>     // for ASSERT
#include "stack.h"     // for STACK
using namespace std;

int opOrder(char op1, char op2)
{
   int op1Weight = 0;

   if (op1 == '+' || op1 == '-')
      op1Weight == 1;

   if (op1 == '*' || op1 == '/' || op1 == '\\')
      op1Weight == 2;

   if (op1 == '^')
      op1Weight == 3;



   int op2Weight = 0;

   if (op2 == '+' || op2 == '-')
      op1Weight = 1;

   if (op2 == '*' || op2 == '/' || op2 == '\\')
      op2Weight = 2;

   if (op2 == '^')
      op2Weight == 3;


   return op1Weight > op2Weight ?  true: false;
}

/*****************************************************
 * CONVERT INFIX TO POSTFIX
 * Convert infix equation "5 + 2" into postifx "5 2 +"
 *****************************************************/
string convertInfixToPostfix(const string & infix)
{

   Stack<char> oper;
   string postfix = "";
   postfix += ' ';

   for(int i = 0; i< infix.length(); i++)
   {

      if(infix[i] == '+' ||
         infix[i] == '-' ||
         infix[i] == '*' ||
         infix[i] == '/' ||
         infix[i] == '\\' ||
         infix[i] == '^')
      {
         while(!oper.empty() && oper.top() != '(' && opOrder(oper.top(),infix[i]))
         {
            postfix += ' ';
            postfix += oper.top();
            oper.pop();
         }
         postfix += ' ';
         oper.push(infix[i]);
      }
      else if(((infix[i] >= '0' && infix[i] <= '9') ||
               (infix[i] >= 'a' && infix[i] <= 'z') ||
               (infix[i] >= 'A' && infix[i] <= 'Z') ||
               infix[i] == '.' || infix[i] <= ',') &&
              infix[i] != ' ')
      {
         postfix += infix[i];
      }
      else if(infix[i] == '(')
      {
         int count = 0;
         for(int j = 0; infix[i+j] != ')'; j++)
         {
            while(infix[i] != ')')
            {
               if(infix[i] == '+' ||
                     infix[i] == '-' ||
                     infix[i] == '*' ||
                     infix[i] == '/' ||
                     infix[i] == '\\' ||
                  infix[i] == '^')
               {
                  while(!oper.empty() && oper.top() != '(' && opOrder(oper.top(),infix[i]))
                  {
                     postfix += ' ';
                     postfix += oper.top();
                     oper.pop();
                  }
                  postfix += ' ';
                  oper.push(infix[i]);
               }



               else if(((infix[i] >= '0' && infix[i] <= '9') ||
                        (infix[i] >= 'a' && infix[i] <= 'z') ||
                        (infix[i] >= 'A' && infix[i] <= 'Z') ||
                        infix[i] == '.' || infix[i] <= ',') &&
                       infix[i] != ' ')
               {
                  postfix += infix[i];
               }
               count++;
            }
         }
         i += count;
         //oper.pop();
      }
   }

   while(!oper.empty()) {

      if(oper.top() == '+' ||
         oper.top() == '-' ||
         oper.top() == '*' ||
         oper.top() == '/' ||
         oper.top() == '\\'||
         oper.top() == '^')
      {
         postfix += ' ';
         postfix += oper.top();
      }

      else
         postfix += oper.top();

      oper.pop();
   }

   return postfix;

}



/*****************************************************
 * TEST INFIX TO POSTFIX
 * Prompt the user for infix text and display the
 * equivalent postfix expression
 *****************************************************/
void testInfixToPostfix()
{
   string input;
   cout << "Enter an infix equation.  Type \"quit\" when done.\n";

      do
      {
         // handle errors
         if (cin.fail())
         {
            cin.clear();
            cin.ignore(256, '\n');
         }

         // prompt for infix
         cout << "infix > ";
         getline(cin, input);

         // generate postfix
         if (input != "quit")
         {
            string postfix = convertInfixToPostfix(input);
            cout << "\tpostfix: " << postfix << endl << endl;
         }
      }
      while (input != "quit");
}

/**********************************************
 * CONVERT POSTFIX TO ASSEMBLY
 * Convert postfix "5 2 +" to assembly:
 *     LOAD 5
 *     ADD 2
 *     STORE VALUE1
 **********************************************/
string convertPostfixToAssembly(const string & postfix)
{
   std::cout << "postfix " << postfix << std::endl;

   string assembly;

   std::cout << " ------ " << std::endl;

   std::cout << " ------ " << std::endl;

   std::cout << " ------ " << std::endl;

   std::cout << " ------ " << std::endl;

   return assembly;
}

/*****************************************************
 * TEST INFIX TO ASSEMBLY
 * Prompt the user for infix text and display the
 * resulting assembly instructions
 *****************************************************/
void testInfixToAssembly()
{
   string input;
   cout << "Enter an infix equation.  Type \"quit\" when done.\n";

      do
      {
         // handle errors
         if (cin.fail())
         {
            cin.clear();
            cin.ignore(256, '\n');
         }

         // prompt for infix
         cout << "infix > ";
         getline(cin, input);

         // generate postfix
         if (input != "quit")
         {
            string postfix = convertInfixToPostfix(input);
            cout << convertPostfixToAssembly(postfix);
         }
      }
      while (input != "quit");

}
