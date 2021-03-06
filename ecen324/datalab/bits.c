/***********************************************************************
* Program:
*    Lab Datalab
*    Brother Jones, ECEN 324
* Author:
*    Donovan Gregory
* Summary:
*    Find solutions to 15 different puzzles without using if or loops.
*    Used https://github.com/zrnorth/CS_classwork/blob/master/CS33/Lab1/bits.c
*    As a reference. 
***********************************************************************/

/* 
 * CS:APP Data Lab 
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *          Even though you may work as a team, all students should
 *          individually submit a solution.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#include "btest.h"
#include <limits.h>

/*
 * Instructions to Students:
 *
 * STEP 1: Fill in the following struct with your identifying info.
 */
team_struct team =
{
   /* Team name: Replace with either:
      Your login ID (Linux Lab username) if working as a one person team
      or, ID1+ID2 where ID1 is the login ID of the first team member
      and ID2 is the login ID of the second team member.
       Example: joestudent+zmename */
    "donovang+", 
   /* Student name 1: Replace with the name of first team member */
   "Donovan Gregory",
   /* Login ID 1: Replace with the login ID of first team member */
   "donovang",

   /* The following should only be changed if there are two team members */
   /* Student name 2: Name of the second team member */
   "",
   /* Login ID 2: Login ID of the second team member */
   ""
};

#if 0
/*
 * STEP 2: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Note that in order to make the dlc (data lab checker) happy you need
  to declare all variables at the first of the function.
      dlc happy with:                 dlc not happy with:
      ---------------                 -------------------
      int Funct( arg1, arg2) {          int Funct( arg1, arg2) {
         int varA = ~0;                    int varA = ~0;
         int varB = 1;                     varA = varA + 4;
         varA = varA + 4;                  int varB = 1;
          ...                               ...

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
     NOTE: You may create big constants using code.  
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
     NOTE: You may define additional functions while you are working to
           solve the problems, but the final submission should not have any.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
#endif

/*
 * STEP 3: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest test harness to check that your solutions produce 
 *      the correct answers. Watch out for corner cases around Tmin and Tmax.
 */
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 *   Returns the 1 if they are both 0. 
 */
int bitNor(int x, int y) {
           return (~x) & (~y);
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 2
 *   Applied De Morgan's law to not use an or. It should return a o when
 *   both ints are the same. 
 */
int bitXor(int x, int y) {
   return ~(x&y) & ~(~x &~y);

}
/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 *   X or y should return 0 if they are equal dobuling the negative
 *   makes the boolean come correctly. 
 */
int isNotEqual(int x, int y) {
   return !!(x^y);
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 *   Shit the n by 3 is like multiplying it by 8. We are then moving n by that
 *   number and finally isolating the result by using and with all 1s.
 */
int getByte(int x, int n) {
   return 0xff &(x>> (n<<3));
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 *   Adding x and 1 isolates the lsb. This will end up with -1 and -2 so
 *   in order to get the appropriate 0 or -1 we need to add another 1. 
 */
int copyLSB(int x) {
   return ~(x& 1) + 1;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 1 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 *   We start with an arethmetic shift, however that propagates the sign bit
 *   across the byte. Then we mst create a fix that will get rid of extra 1s
 *   created by the shift.  by doing ~test and test allows the test to be
 *   done whether it is negative or positive. 
 */
int logicalShift(int x, int n) {
   return (x >> n) & ~(((0x1 << 31) >> n) << 1);
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
   // Mask 1 encompasses the 2 least significant bytes
   int mask1 = 0x11 | (0x11 << 8);

   // Mask 2 encompasses the final bytes
   int mask2 = mask1 | (mask1 << 16);

   // Sum will hold the number of 1 bits in the bit string
   // Computes the number of 1 bits within the first four bits
   int sum = x & mask2;
   sum = sum + ((x >> 1) & mask2);
   sum = sum + ((x >> 2) & mask2);
   sum = sum + ((x >> 3) & mask2);

   // Sum now represents the number of 1 bits within the first 4 bits.
   // in addition to extraneous bits beyond the first four bits.
   

   //Adjusts for overestimated in sum
   sum = sum + (sum >> 16);

   // Used to preserve current sum, and continue to mask 1 bits in the next byte.
   mask1 = 0xF | (0xF << 8);

  
   sum = (sum & mask1) + ((sum >> 4) & mask1);

   //Shift sum value 1 byte and implement mask to limit resulting sum to 6 bits
  // Max representation of 6 bits.
   return((sum + (sum >> 8)) & 0x3F);
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 *   So in order to return 1 both the most significant bit and and two's
 *   additive inverse must be 0. 
 */
int bang(int x) {
   return ((x >> 31) | ((~x +1) >> 31)) + 1;
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 4
 *   By notting the x and adding 1 we get a bunch of zeros and flipping
 * the lsb back to what he should be. 
 */
int leastBitPos(int x) {
   return x & (~x + 1);
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 *   Just returning the largest two's complement integer
 */
int tmax(void) {
   return ~(1 << 31);;
}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 *   Returns the oppisite of the msb. 
 */
int isNonNegative(int x) {
   return !(x >> 31);
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 * Check to see which is negative and which is positive
 */
int isGreater(int x, int y) {
   int value = !((x + ~y) >> 31);

   x = x >>31;
   y = y >> 31;
   return (!x & y) | (value & (!x | y));
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
   // Something is needed to account for x >> n if positive and x >> n + 1 if negative

   // Subtract 1 from 2^n
   // This accounts for the need to + 1
   int mask = (1 << n) + ~0;

   // Use & operator on mask and sign bit of x
   int equalizer = (x >> 31) & mask;

   // Adds 1 if x was originally negative
   // Adds 0 if x was originally positive
   return (x + equalizer) >> n;
}
/* 
 * abs - absolute value of x (except returns TMin for TMin)
 *   Example: abs(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 * Basically figures out if x is negative or positive.
 */
int abs(int x) {
   int test = x >> 31;
   return (~test & x) | (test & (~x+1));
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 *   Isolated the msb. Then it returns 1 when them added together is the same
 *   as x or y. 
 */
int addOK(int x, int y) {
   int temp = (x+y) >> 31;
   x = x>>31;
   y = y>> 31;
   return !!(~temp | x | y) & (temp |~x|~y);
}
