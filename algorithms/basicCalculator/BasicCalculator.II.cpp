// Source : https://leetcode.com/problems/basic-calculator-ii/
// Author : Hao Chen
// Date   : 2015-06-24

/********************************************************************************** 
 * 
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string contains only non-negative integers, +, -, *, / operators and empty spaces  . 
 * The integer division should truncate toward zero.
 * 
 * You may assume that the given expression is always valid.
 * 
 * Some examples:
 * 
 * "3+2*2" = 7
 * " 3/2 " = 1
 * " 3+5 / 2 " = 5
 * 
 * Note: Do not use the eval built-in library function.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 **********************************************************************************/
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
using namespace std;

/* 
 * Acuatlly, everything I've already implemented in "Basic Calculator"(RPN way and Design pattern way).
 * So, here, I just use the quick-dirty way - just like the "two stacks solution" in "Basic Calulator".
 */


//Quick & Dirty Solution
bool isOperator(const char ch) {
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/');
}


int Priority(const char c) {
    if (c == '*' || c == '/') {
        return 2;
    } else if (c== '+' || c == '-') {
        return 1;
    } else {
        return 0;
    }
}

long long calculate_exp(long long x, long long y, char op) {
    switch(op) {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/': return x / y;
    }
    return -1;
}


//Two Stacks solution
int calculate_two_stacks(string& s) {

    s += "+0";
    stack<long long> num_stack; //put the number
    stack<char> op_stack; //put the operations

    #define CALCULATE_IT { \
        long long y = num_stack.top(); num_stack.pop(); \
        long long x = num_stack.top(); num_stack.pop(); \
        char op = op_stack.top(); op_stack.pop(); \
        num_stack.push(calculate_exp(x, y, op));\
    }

    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        if (isspace(ch)) continue;
        if (isdigit(ch)) {
            string num;
            num += s[i];
            while(isdigit(s[i+1])){
                num += s[i+1];
                i++;
            }
            num_stack.push(stoll(num));
            continue;
        }
        if (isOperator(ch)) {
            while (!op_stack.empty() && Priority(op_stack.top()) >= Priority(ch) ) {
                CALCULATE_IT;
            }

            op_stack.push(ch);
        }

    }

    while(!op_stack.empty()){
        CALCULATE_IT;
    }
    
    return num_stack.top();
}


int calculate(string s) {
    return calculate_two_stacks(s);
}

int main(int argc, char**argv) 
{
    string exp = " 3+5 / 2 ";
    if (argc>1) {
        exp = argv[1];
    }

    cout << "\"" << exp << "\" = " << calculate(exp) << endl;

}

