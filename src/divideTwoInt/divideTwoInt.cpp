// Source : https://oj.leetcode.com/problems/divide-two-integers/
// Author : Hao Chen
// Date   : 2014-06-20

/********************************************************************************** 
* 
* Divide two integers without using multiplication, division and mod operator.
* 
*               
**********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;


int divide(int dividend, int divisor) {
  
    int sign = 1;
    long long dvd = dividend;
    long long dvs = divisor;
    if (dvd<0) {
        dvd = -dvd;
        sign = -sign;
    } 
    if (dvs<0) {
        dvs = -dvs;
        sign = -sign;
    }

    long long bit_num[32];
    memset( bit_num, 0, sizeof(bit_num) );

    int i=0;
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

    return result * sign;
}


int main()
{
    cout << "10/2=" << divide(10, 2) << endl;
    cout << "10/3=" << divide(10, 3) << endl;
    cout << "10/5=" << divide(10, 5) << endl;
    cout << "10/7=" << divide(10, 7) << endl;
    cout << "10/10=" << divide(10, 10) << endl;
    cout << "10/11=" << divide(10, 11) << endl;
    cout << "1/-1=" << divide(1, -1) << endl;
    cout << "-1/-1=" << divide(-1, -1) << endl;
    cout << "2147483647/1=" << divide(2147483647, 1) << endl;
    cout << "-2147483647/1=" << divide(-2147483647, 1) << endl;
    cout << "2147483647/-1=" << divide(2147483647, -1) << endl;
    cout << "-2147483647/-1=" << divide(-2147483647, -1) << endl;
    cout << "2147483647/2=" << divide(2147483647, 2) << endl;
    cout << "2147483647/10=" << divide(2147483647, 10) << endl;
    cout << "-2147483648/1=" << divide(-2147483648, 1) << endl;
}
