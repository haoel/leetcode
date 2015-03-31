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
#include <map>
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

string fractionToDecimal(int numerator, int denominator) {
    string result;
    //deal with the `ZERO` cases
    if (denominator == 0){ return result; }
    if (numerator == 0) { return "0"; }

    //using long long type make sure there has no integer overflow
    long long n = numerator;
    long long d = denominator;

    //deal with negtive cases 
    bool sign = ((float)numerator/denominator >= 0);
    if ( n < 0 ){ n = -n; }
    if ( d < 0 ){ d = -d; }
    if (sign == false){
        result.push_back('-');
    }

    long long remainder = n % d;
    long long division = n / d;
    ostringstream oss;
    oss << division;
    result += oss.str();
    if (remainder == 0){
        return result;
    }
    //remainder has value, the result is a float
    result.push_back('.');

    //using a map to record all of reminders and their position.
    //if the reminder appeared before, which means the repeated loop begin, 
    //then, get the place from map to insert "(".
    //(In C++11, it's better to use unordered_map )
    map<long long, int> rec;

    for (int pos=result.size(); remainder!=0; pos++, remainder=(remainder*10)%d ) {
        if (rec.find(remainder) != rec.end()) {
            result.insert(result.begin()+rec[remainder], '(');
            result.push_back(')');
            return result;
        }
        rec[remainder] = pos;
        result.push_back((remainder*10)/d + '0');
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
