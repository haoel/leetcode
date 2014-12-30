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

    string stack;

    while(s.size()>0){

        char lch = s.back();

        if (lch == '[' || lch=='{' || lch=='(') {
            if (s.size()<=0) return false;
            char rch = stack.back();
            if ((lch=='[' && rch ==']') ||
                    (lch=='{' && rch =='}') ||
                    (lch=='(' && rch ==')') ) {
                s.pop_back();
                stack.pop_back();
            }else{
                return false;
            }
        } else if (lch== ']' || lch=='}' || lch==')' ) {
            s.pop_back();
            stack.push_back(lch);
        } else {
            //skip the other charactors
            s.pop_back();
        }
    }
    return (s.size()==0 && stack.size()==0 );
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
