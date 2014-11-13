// Source : https://oj.leetcode.com/problems/valid-parentheses/
// Author : Hao Chen
// Date   : 2014-06-30

/********************************************************************************** 
* 
* Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
* determine if the input string is valid.
* 
* The brackets must close in the correct order, "()" and "()[]{}" are all valid 
* but "(]" and "([)]" are not.
* 
*               
**********************************************************************************/

#include <iostream>
#include <string>
using namespace std;

bool isValid(string s) {
    if (s.size() % 2 != 0) return false;

    string stack;

    while(s.size()>0){

        char lch = s.back();

        if (lch == '[' || lch=='{' || lch=='(') {
            if (s.size()<=0) return false;
            char rch = stack.back();
            if ((lch=='[' && rch ==']') ||
                    (lch=='{' && rch =='}') ||
                    (lch=='(' && rch ==')') ) {
                stack.pop_back();
            }else{
                return false;
            }
        } else if (lch== ']' || lch=='}' || lch==')' ) {
            stack.push_back(lch);
        } else {
            return false;
        }

        s.pop_back();
    }
    return stack.size()==0;
}

int main(int argc, char**argv)
{
    string s = "{{}{[]()}}";
    if (argc>1){
        s = argv[1];
    }
    cout << "str = \"" << (s) << "\"" << endl;
    cout << isValid(s) << endl;
}
