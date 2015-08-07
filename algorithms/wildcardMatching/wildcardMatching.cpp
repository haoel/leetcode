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
    while( *s != '\0' ){
        if (*p=='*'){
            //skip the "*", and mark a flag
            p++;
            //edge case
            if (*p=='\0') return true;
            //use last_s and last_p to store where the "*" match starts.
            last_s = s;
            last_p = p;
        }else if (*p=='?' || *s == *p){
            s++; p++;
        }else if (last_s != NULL){ // check "last_s" to know whether meet "*" before
            // if meet "*" previously, and the *s != *p
            // reset the p, using '*' to match this situation
            p = last_p;
            s = ++last_s; 
        }else{
            // *p is not wildcard char, 
            // doesn't match *s, 
            // there are no '*' wildcard matched before
            return false;
        }
    }
    //edge case: "s" is done, but "p" still have chars.
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

    /* thanks @jakwings (GitHub) find this problem */
    s = "*aa"; // <-- it is not a pattern, it just a string where '*' is not a wildcard
    p = "*a";
    cout << s << ", " << p << " : " << isMatch(s, p) << endl;

    if (argc>2){
        s = argv[1];
        p = argv[2];
        cout << s << ", " << p << " : " << isMatch(s, p) << endl;
    }
    return 0;
}
