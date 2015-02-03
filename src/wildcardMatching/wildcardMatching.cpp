// Source : https://oj.leetcode.com/problems/wildcard-matching/
// Author : Hao Chen
// Date   : 2014-07-19

/********************************************************************************** 
* 
* Implement wildcard pattern matching with support for '?' and '*'.
* 
* '?' Matches any single character.
* '*' Matches any sequence of characters (including the empty sequence).
* 
* The matching should cover the entire input string (not partial).
* 
* The function prototype should be:
* bool isMatch(const char *s, const char *p)
* 
* Some examples:
* isMatch("aa","a") → false
* isMatch("aa","aa") → true
* isMatch("aaa","aa") → false
* isMatch("aa", "*") → true
* isMatch("aa", "a*") → true
* isMatch("ab", "?*") → true
* isMatch("aab", "c*a*b") → false
* 
*               
**********************************************************************************/

#include <iostream>
#include <string>
using namespace std;


bool isMatch(const char *s, const char *p) {
    const char *last_s = NULL;
    const char *last_p = NULL;
    while (*s != '\0') {
        // Here, '*' in the pattern is ungreedy. This means we are trying to
        // build one or more one-character-to-one-character mappings between
        // the pattern string and the target string as less as possible.
        if (*p == '*') {
            last_s = s;
            last_p = p++;
        } else if (*p == '?' || *p == *s) {
            s++;
            p++;
        } else if (last_s) {
            // Why not use stacks? Because '*' is ungreedy and it can match any
            // character. If s becomes '\0' and the rest of p contains
            // characters other than '*', that means:
            //      len(original_s) < len(original_p) - count(original_p, '*')
            s = ++last_s;
            p = last_p + 1;
        } else {
            return false;
        }
    }
    while (*p == '*') p++;
    return *p == '\0';
}


int main(int argc, char** argv)
{
    const char *s = "aab";
    const char *p = "a*a*b";
    cout << s << ", " << p << " : " << isMatch(s, p) << endl;

    s = "abbb";
    p = "a*b";
    cout << s << ", " << p << " : " << isMatch(s, p) << endl;

    s = "abb";
    p = "a*bb";
    cout << s << ", " << p << " : " << isMatch(s, p) << endl;

    s = "abddbbb";
    p = "a*d*b";
    cout << s << ", " << p << " : " << isMatch(s, p) << endl;

    s = "abdb";
    p = "a**";
    cout << s << ", " << p << " : " << isMatch(s, p) << endl;

    s = "a";
    p = "a**";
    cout << s << ", " << p << " : " << isMatch(s, p) << endl;

    s = "*";
    p = "*a";
    cout << s << ", " << p << " : " << isMatch(s, p) << endl;

    if (argc>2){
        s = argv[1];
        p = argv[2];
        cout << s << ", " << p << " : " << isMatch(s, p) << endl;
    }
    return 0;
}
