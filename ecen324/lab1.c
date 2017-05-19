/***********************************************************************
* Program:
*    Lab C_lab, ECEN 324 Learning C Lab
*    Brother Jones, ECEN 324
* Author:
*    Donovan Gregory
* Summary:
*    Converting a premade c++ program into c. 
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926

/***********************************************************************
* Tests out defined Pi and outputs several different characters. Meant
* to see the basics of printf.
***********************************************************************/
int main (void)
{
   // Printing various items
   //save a char. Then testing printing a char, a hard number, and a defined.
   const char LETTER = 'A';
   printf("24\n");
   printf("%.5f\n", PI);
   printf("%c\n", LETTER);
   //create a float and int. Then print it out in various ways.
   float payRate = 10.50;
   int hours = 40;
   // Creates two variables and then multiples them. 
   printf( "Users pay rate: $%.1f\n", payRate); 
   printf(" Hours worked: %d\n", hours);
   float grossPay = hours * payRate;
   printf("    Gross Pay: $%.0f\n", grossPay);
   //save an int then play with the int. 
   int number = 0;
   scanf("%d", &number);
   printf("Twice %d is %d\n", number, number * 2);
 
   /*********************************************************************/
   /*********************** Output an Integer ***************************/
   /*********************************************************************/
   int anInt = 99;
   float aFloat = 43.2;
 
   // Output the integer with the default formatting.
   //Fun with Ints. 
   printf("\n");                      // output a blank line
   printf("Integer: %d ###\n", anInt);
 
   // Output the integer in a fixed field width of 10.
   // The object will be right justified in the field.
   // I left in the code that accuratly describes what I am doing. 
   printf("Integer: %10d ###\n", anInt);
 
   // Output the integer in a fixed field width of 10
   // and left justified in the field.
   //
   printf("Integer: %-10d ###\n\n", anInt);
 
   
   /*********************************************************************/
   /************************* Output a Float ****************************/
   /*********************************************************************/
 
   // Output the float with the default formatting.
   // Not actually "default".
   printf("  Float: %.1f ###\n", aFloat);
 
   // Output the float in a fixed field width of 10.
   // Combinations of float with other things I have done. 
   printf("  Float: %-10.1f ###\n", aFloat);
 
   // Output the float right justified in a field width of 10 with  
   // a precision of 2 places after the decimal point for the float. 
   //
   printf("  Float: %10.2f ###\n", aFloat);
 
   // Output the float with 3 places of precision after the decimal point but
   // not giving a field width.
   //
   printf("  Float: %.3f ###\n",aFloat);
 
   // Output the float with 3 places of precision after the decimal point with
   // a field width of 10.  
   //
   printf( "  Float: %10.3f ###\n", aFloat);
  
   // Output the float with 4 places of precision after the decimal point with 
   // a field width of 10 and left justify the number.
   //
   printf("  Float: %-10.4f ###\n\n", aFloat);
 
   /*********************************************************************
    *************** Create some code to output a table ******************
    *********************************************************************/
 
   // The following table has a leading tab. Ugly looking table in code. 
 
   printf("\tOct   Dec   Hex   Char\n\t----------------------\n\t141   97    61    a\n\t142   98    62    b\n\t143   99    63    c\n\t144   100   64    d\n\t145   101   65    e\n\t146   102   66    f\n\t147   103   67    g\n\t150   104   68    h\n\t151   105   69    i\n\t152   106   6a    j\n\t153   107   6b    k\n\t154   108   6c    l\n\t155   109   6d    m\n\t156   110   6e    n\n\t157   111   6f    o\n\t160   112   70    p\n\t161   113   71    q\n\t162   114   72    r\n\t163   115   73    s\n\t164   116   74    t\n\t165   117   75    u\n\t166   118   76    v\n\t167   119   77    w\n\t170   120   78    x\n\t171   121   79    y\n\t172   122   7a    z\n\n");
 
   /*********************************************************************/
 
   /*********************************************************************
    *************** Now play with pointers to finish up *****************
    *********************************************************************/
   //Fun with pointers, which is very similar to c++. 
   int *p1;
   int *p2;
 
   p1 = (int*) calloc(25, sizeof(int));
   *p1 = 42;
   p2 = p1;
printf("*p1 == %d\n", *p1);
printf("*p2 == %d\n", *p2);
 
   *p2 = 53;
printf("*p1 == %d\n", *p1);
printf("*p2 == %d\n", *p2);
 
   p1 = (int*) calloc(25, sizeof(int));
   *p1 = 88;
printf("*p1 == %d\n", *p1);
printf("*p2 == %d\n",*p2);
 
printf("Hope you got the point of this example!\n");
 
free(p1);
free(p2);

   return 0;
}

