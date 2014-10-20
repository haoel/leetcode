// Source : https://oj.leetcode.com/problems/regular-expression-matching/
// Author : Hao Chen
// Date   : 2014-08-24

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
