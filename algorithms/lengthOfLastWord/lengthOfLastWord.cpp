// Source : https://oj.leetcode.com/problems/length-of-last-word/
// Author : Hao Chen
// Date   : 2014-07-01

/********************************************************************************** 
* 
* Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
* return the length of last word in the string.
* 
* If the last word does not exist, return 0.
* 
* Note: A word is defined as a character sequence consists of non-space characters only.
* 
* For example, 
* Given s = "Hello World",
* return 5.
* 
*               
**********************************************************************************/

#include <stdio.h>
#include <ctype.h>

int lengthOfLastWord(const char *s) {

    if ( !s ||!*s ) return 0;

    int wordLen=0;
    int cnt=0;

    for (;*s!='\0';s++) {
        if (isalpha(*s)){
            cnt++;
        }
        if (!isalpha(*s)){
            if (cnt>0){
                wordLen = cnt;
            }
            cnt=0;
        }
    }

    return cnt>0 ? cnt : wordLen;
}


int main(int argc, char** argv)
{
    const char* p;
    p = "hello world";
    printf("%s, %d\n", p, lengthOfLastWord(p)); 
    p = "a";
    printf("%s, %d\n", p, lengthOfLastWord(p)); 
    
    if(argc>1){
        p = argv[1];
        printf("%s, %d\n", p, lengthOfLastWord(p)); 
    }
}
