// Source : https://oj.leetcode.com/problems/fraction-to-recurring-decimal/
// Author : Hao Chen
// Date   : 2014-12-16

/********************************************************************************** 
* 
* Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
* 
* If the fractional part is repeating, enclose the repeating part in parentheses.
* 
* For example,
* 
* Given numerator = 1, denominator = 2, return "0.5".
* Given numerator = 2, denominator = 1, return "2".
* Given numerator = 2, denominator = 3, return "0.(6)".
* 
* Credits:Special thanks to @Shangrila for adding this problem and creating all test cases.
*               
**********************************************************************************/

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/*
 *  Be careful the following cases:
 *
 *    > 0/2
 *    > 1/0
 *    > 1/3
 *    > 2/4
 *    > 100/2
 *    > 100/3
 *    > 1/-4
 *    > -1/4
 *    > -1/-4
 *    > 25/99 = 0.25252525....
 *    > 1/7 = 0.142857142857...
 *    > 1/17 = 0.(0588235294117647)
 */


// Notes:
//  > check 3 times repeated-decimail numbers
//  > using c-style string for performance
bool checkRepeat(string &dec) {

    size_t dot = dec.find('.') + 1;
    const char *p = dec.c_str() + dot ;

    //for case: 0.000
    if (atoi(p) ==0 ) return false;

    //check 3 times repeated string
    size_t len = dec.size();
    //static string s1, s2, s3;
    for(int i=2; i<=(len-dot)/3; i++) {
        int j=0;
        const char *p1 = dec.c_str()+len - i;
        const char *p2 = dec.c_str()+len - i*2;
        const char *p3 = dec.c_str()+len - i*3;
        for(; j<i; j++, p1++, p2++, p3++){
            if (*p1!=*p2 || *p1 != *p3){
                break;
            }
        }
        if ( i == j) {
            dec.erase(dec.end()-i*2, dec.end());
            dec.insert(dec.end()-i,'(');
            dec.push_back(')');
            return true;
        }
    } 
    return false;
}

/*
 *    0.16  
 *  -------
 *6 ) 1.00
 *    0 
 *    -
 *    1 0       <-- Remainder=1, mark 1 as seen at position=0.
 *    - 6 
 *    ---
 *      40      <-- Remainder=4, mark 4 as seen at position=1.
 *    - 36 
 *    ---
 *       4      <-- Remainder=4 was seen before at position=1, so the fractional part which is 16 starts repeating at position=1 => 1(6).
 */

string fractionToDecimal(int numerator, int denominator) {
    string result;
    //deal with the `ZERO` cases
    if (denominator == 0){ return result; }
    if (numerator == 0) { return "0"; }
    
    //using long long type make sure there has no integer overflow
    long long n = numerator;
    long long d = denominator;

    //deal with negtive cases 
    int sign = 1;
    if ( n < 0 ) {
        n = -n;
        sign = -sign; 
    }
    if ( d < 0 ) {
        d = -d;
        sign = -sign; 
    }

    if (sign < 0){
        result.push_back('-');
    }

    //real work
    long long remainder = 0;
    long long division = 0;
    bool point = false;

    while( n != 0 )  {

        division = n / d;
        remainder = n % d; 

        if (division >=10){
            ostringstream oss;
            oss << division;
            result += oss.str();
        }else{
            result.push_back( division + '0' );
        }

        if ( point == false && remainder !=0 ){
            result.push_back('.');
            point = true;
        }

        //deal with case only have one number repeated. e.g. 1/3 = 0.3333
        if ( point == true && n == remainder * 10 ) {
            result.insert(result.end()-1, '(');
            result.push_back(')');
            break;
        }

        //deal with the case which have multiple number repeated. e.g. 25/99 = 0.252525...
        if (checkRepeat(result) == true){
            break;
        }


        n = remainder * 10;

    }

    return result;
}

void test(int num, int deno)
{
    cout << "numerator: " << num << "\tdenominator: " << deno << "\tresult: " << fractionToDecimal(num, deno) << endl;
}

int main(int argc, char** argv)
{
    test(1, 2);
    test(10, 2);
    test(100, 2);
    test(1, 3);
    test(100, 3);
    test(1, 6);
    test(100, 6);
    test(-1, 4);
    test(1, -3);
    test(-1, -6);
    test(25, 99);
    test(1, 7);
    test(10, 7);
    test(100, 7);
    test(1, 17);
    test(1, 1024);
    test( -2147483648, -1999);
    test(-1, -2147483648);


    if (argc > 2) {
        int num = atoi(argv[1]);
        int deno = atoi(argv[2]);
        test(num, deno);
    }
    return 0;
}
