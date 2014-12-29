// Source : https://oj.leetcode.com/problems/divide-two-integers/
// Author : Hao Chen
// Date   : 2014-06-20

/********************************************************************************** 
* 
* Divide two integers without using multiplication, division and mod operator.
* 
* If it is overflow, return MAX_INT. 
*
**********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define INT_MAX     2147483647
#define INT_MIN     (-INT_MAX - 1)

int divide(int dividend, int divisor) {

    int sign = (float)dividend / divisor > 0 ? 1 : -1;
    unsigned int dvd = dividend > 0 ? dividend : -dividend;
    unsigned int dvs = divisor > 0 ? divisor : -divisor;

    unsigned int bit_num[32];
    unsigned int i=0;
    long long d = dvs;
    bit_num[i] = d;
    while( d <= dvd ){
        bit_num[++i] = d = d << 1;
    }
    i--;

    unsigned int result = 0;
    while(dvd >= dvs){
        if (dvd >= bit_num[i]){
            dvd -= bit_num[i];
            result += (1<<i);
        }else{
            i--;
        }
    }

    //becasue need to return `int`, so we need to check it is overflowed or not.
    if ( result > INT_MAX && sign > 0 ) {
        return INT_MAX;
    }
    return (int)result * sign;
}


int main()
{
    cout << "0/2=" << divide(0, 2) << endl;
    cout << "10/2=" << divide(10, 2) << endl;
    cout << "10/3=" << divide(10, 3) << endl;
    cout << "10/5=" << divide(10, 5) << endl;
    cout << "10/7=" << divide(10, 7) << endl;
    cout << "10/10=" << divide(10, 10) << endl;
    cout << "10/11=" << divide(10, 11) << endl;
    cout << "-1/1=" << divide(1, -1) << endl;
    cout << "1/-1=" << divide(1, -1) << endl;
    cout << "-1/-1=" << divide(-1, -1) << endl;
    cout << "2147483647/1=" << divide(2147483647, 1) << endl;
    cout << "-2147483647/1=" << divide(-2147483647, 1) << endl;
    cout << "2147483647/-1=" << divide(2147483647, -1) << endl;
    cout << "-2147483647/-1=" << divide(-2147483647, -1) << endl;
    cout << "2147483647/2=" << divide(2147483647, 2) << endl;
    cout << "2147483647/10=" << divide(2147483647, 10) << endl;
    cout << "-2147483648/1=" << divide(-2147483648, 1) << endl;
    cout << "-2147483648/-1=" << divide(-2147483648, -1) << endl;
}
