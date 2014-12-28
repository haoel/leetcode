// Source : https://oj.leetcode.com/problems/reverse-integer/
// Author : Hao Chen
// Date   : 2014-06-18

/********************************************************************************** 
* 
* Reverse digits of an integer.
* 
* Example1: x =  123, return  321
* Example2: x = -123, return -321
* 
* 
* Have you thought about this?
* 
* Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
* 
* > If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
* 
* > Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, 
*   then the reverse of 1000000003 overflows. How should you handle such cases?
* 
* > Throw an exception? Good, but what if throwing an exception is not an option? 
*   You would then have to re-design the function (ie, add an extra parameter).
* 
*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

//Why need the INT_MIN be defined like that?
//Please take a look: 
//  http://stackoverflow.com/questions/14695118/2147483648-0-returns-true-in-c
#define INT_MAX     2147483647
#define INT_MIN     (-INT_MAX - 1)
int reverse(int x) {
    int y=0;
    int n;
    while( x != 0){
        n = x%10;
        //Checking the over/underflow.
        //Actually, it should be y>(INT_MAX-n)/10, but n/10 is 0, so omit it.
        if (y > INT_MAX/10 || y < INT_MIN/10){
             return 0;
        }
        y = y*10 + n;
        x /= 10;
    }
    return y;
}

#define TEST(n, e)  printf("%12d  =>  %-12d    %s!\n",  n, reverse(n),  e == reverse(n)?"passed":"failed")

int main(int argc, char**argv)
{
    //basic cases
    TEST(  123,  321);
    TEST( -123, -321);
    TEST( -100,   -1);
    TEST( 1002, 2001);
    //big integer
    TEST( 1463847412,  2147483641);
    TEST(-2147447412, -2147447412);
    TEST( 2147447412,  2147447412);
    //overflow
    TEST( 1000000003, 0);
    TEST( 2147483647, 0);
    TEST(-2147483648, 0);
    //customized cases
    if (argc<2){
        return 0;
    }
    printf("\n");
    for (int i=1; i<argc; i++) {
        int n = atoi(argv[i]); 
        printf("%12d  =>  %-12d    %s!\n",  n, reverse(n), reverse(reverse(n))==n ? "passed":"failed");
    }
    return 0;
}
