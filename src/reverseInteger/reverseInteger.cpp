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


int reverse(int x) {
    int y=0;
    int n;
    while( x>0 || x<0){
        n = x%10;
        y = y*10 + n;
        x /= 10;
    }
    return y;
}

int main()
{
    printf("%d, %d\n", 123, reverse(123));
    printf("%d, %d\n", -123, reverse(-123));
    printf("%d, %d\n", 100, reverse(100));
    printf("%d, %d\n", 1002, reverse(1002));
    //overflow
    printf("%d, %d\n", 1000000003 , reverse(1000000003 ));
    printf("%d, %d\n", -2147447412 , reverse(-2147447412 ));
    printf("%d\n",  -2147447412 == reverse(-2147447412 ));
    return 0;
}
