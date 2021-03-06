/***********************************************************************
* Program:
*    Checkpoint 02b, Complex Numbers
*    Brother Ercanbrack, CS165
* Author:
*    Donovan Gregory
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

// TODO: Define your Complex struct here
struct Complex
{
   double real;
   double imagine;
};

// TODO: Add your prompt function here
Complex prompt()
{
   Complex num;
   cout << "Real: ";
   cin >> num.real;
   cout << "Imaginary: ";
   cin >> num.imagine;

   return num;
}


// TODO: Add your display function here
void display(Complex sum)
{
   cout << sum.real << " + " << sum.imagine << "i";
}

/**********************************************************************
 * Function: addComplex
 * Purpose: Adds two complex numbers together and returns the sum.
 ***********************************************************************/
Complex addComplex(const Complex & x, const Complex & y)
{
   // TODO: Fill in the body of the add function
   Complex sum;
   sum.real = x.real + y.real;
   sum.imagine = x.imagine + y.imagine;
   return sum;

}


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // Declare two Complex objects, c1 and c2
   Complex x;
   Complex y;

   // Call your prompt function twice to fill in c1, and c2 
   x = prompt();
   y = prompt();

   // Declare another Complex for the sum
   Complex sum;

   // Call the addComplex function, putting the result in sum;
   sum = addComplex(x, y);
   
   cout << "\nThe sum is: ";
   display(sum);
   cout << endl;
 
   return 0;
}


