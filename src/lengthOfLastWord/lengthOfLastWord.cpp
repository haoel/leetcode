// Source : https://oj.leetcode.com/problems/length-of-last-word/
// Author : Hao Chen
// Date   : 2014-07-01

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
