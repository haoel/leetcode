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

    bool star = false;
    const char *s1, *p1;
    while( *s && (*p || star) ){
        if (*p=='?' || *s == *p){
            s++; p++;
        }else if (*p=='*'){
            star = true;
            p++;
            if (*p=='\0') return true;
            s1 = s;
            p1 = p;
        }else{
            if (star==false) return false;
            p = p1;
            s = ++s1; 
        }
    }
    if (*s=='\0') {
         while (*p=='*') p++; //filter all of * 
         if (*p=='\0') return true;
    }
    return false;
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
    if (argc>2){
        s = argv[1];
        p = argv[2];
        cout << s << ", " << p << " : " << isMatch(s, p) << endl;
    }
    return 0;
}
