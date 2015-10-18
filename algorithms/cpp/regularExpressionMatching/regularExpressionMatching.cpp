// Source : https://oj.leetcode.com/problems/regular-expression-matching/
// Author : Hao Chen
// Date   : 2014-08-24

/********************************************************************************** 
* 
* Implement regular expression matching with support for '.' and '*'.
* 
* '.' Matches any single character.
* '*' Matches zero or more of the preceding element.
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
* isMatch("aa", "a*") → true
* isMatch("aa", ".*") → true
* isMatch("ab", ".*") → true
* isMatch("aab", "c*a*b") → true
* 
*               
**********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;


bool isMatch(const char *s, const char *p) {

    if (*p=='\0') {
        return *s == '\0';
    }
    //p's length 1 is special case 
    if (*(p+1) == '\0' || *(p+1) !='*' ) {
        if (*s=='\0' || ( *p !='.' && *s != *p )) {
            return false;
        }
        return isMatch(s+1, p+1);
    }
    int len = strlen(s);
    int i = -1;
    while (i < len && (i <0 || *p=='.' || *p==*(s+i)) ){
        if (isMatch(s+i+1, p+2)) {
            return true;
        }
        i++;
    }
    return false;
}


int main(int argc, char** argv)
{
    const char* s = "aaa";
    const char* p = "a.*";

    if (argc>2) {
        s = argv[1];
        p = argv[2];
    }

    cout << s << ", " << p << " : " << isMatch(s,p) << endl;
}
