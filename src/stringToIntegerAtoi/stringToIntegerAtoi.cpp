// Source : https://oj.leetcode.com/problems/string-to-integer-atoi/
// Author : Hao Chen
// Date   : 2014-06-18

/********************************************************************************** 
* 
* Implement atoi to convert a string to an integer.
* 
* Hint: Carefully consider all possible input cases. If you want a challenge, 
*       please do not see below and ask yourself what are the possible input cases.
* 
* Notes: 
*   It is intended for this problem to be specified vaguely (ie, no given input specs). 
*   You are responsible to gather all the input requirements up front. 
* 
* 
* Requirements for atoi:
* 
* The function first discards as many whitespace characters as necessary until the first 
* non-whitespace character is found. Then, starting from this character, takes an optional 
* initial plus or minus sign followed by as many numerical digits as possible, and interprets 
* them as a numerical value.
* 
* The string can contain additional characters after those that form the integral number, 
* which are ignored and have no effect on the behavior of this function.
* 
* If the first sequence of non-whitespace characters in str is not a valid integral number, 
* or if no such sequence exists because either str is empty or it contains only whitespace 
* characters, no conversion is performed.
* 
* If no valid conversion could be performed, a zero value is returned. If the correct value 
* is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) 
* is returned.
*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define INT_MIN     (-2147483647 - 1)
#define INT_MAX      2147483647

int atoi(const char *str) {
    if (str==NULL || *str=='\0'){
        return 0;
    }
    
    int ret=0;
    
    for(;isspace(*str); str++);
    
    bool neg=false;
    if (*str=='-' || *str=='+') {
        neg = (*str=='-') ;
        str++;
    }
    
    for(; isdigit(*str); str++) {
        int digit = (*str-'0');
        if(neg){
            if( -ret < (INT_MIN + digit)/10 ) {
                return INT_MIN;
            }
        }else{
            if( ret > (INT_MAX - digit) /10 ) {
                return INT_MAX;
            }
        }

        ret = 10*ret + digit ;
    }
    
    return neg?-ret:ret;
}


int main()
{
    printf("\"%s\" = %d\n", "123", atoi("123"));
    printf("\"%s\" = %d\n", "   123", atoi("    123"));
    printf("\"%s\" = %d\n", "+123", atoi("+123"));
    printf("\"%s\" = %d\n", " -123", atoi(" -123"));
    printf("\"%s\" = %d\n", "123ABC", atoi("123ABC"));
    printf("\"%s\" = %d\n", " abc123ABC", atoi(" abc123ABC"));
    printf("\"%s\" = %d\n", "2147483647", atoi("2147483647"));
    printf("\"%s\" = %d\n", "-2147483648", atoi("-2147483648"));
    printf("\"%s\" = %d\n", "2147483648", atoi("2147483648"));
    printf("\"%s\" = %d\n", "-2147483649", atoi("-2147483649"));
    return 0;
}
