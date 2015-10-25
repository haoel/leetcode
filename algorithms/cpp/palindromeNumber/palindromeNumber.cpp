// Source : https://oj.leetcode.com/problems/palindrome-number/
// Author : Hao Chen
// Date   : 2014-06-18

/********************************************************************************** 
* 
* Determine whether an integer is a palindrome. Do this without extra space.
* 
* 
* Some hints:
* 
* Could negative integers be palindromes? (ie, -1)
* 
* If you are thinking of converting the integer to string, note the restriction of using extra space.
* 
* You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", 
* you know that the reversed integer might overflow. How would you handle such case?
* 
* There is a more generic way of solving this problem.
* 
*               
**********************************************************************************/

#include <math.h>
#include <stdio.h>

class Solution {
public:

    bool isPalindrome(int x) {
        if (x<0) {
            return false;
        }
        
        int len=1;
        for (len=1; (x/len) >= 10; len*=10 );
        
        while (x != 0 ) {
            int left = x / len;
            int right = x % 10;
            
            if(left!=right){
                return false;
            }
            
            x = (x%len) / 10;
            len /= 100;
        }
        return true;
    }
    
    bool isPalindrome2(int x) {
        return (x>=0 && x == reverse(x));
    }

    bool isPalindrome3(int x) {
        if(x < 0) return false;

        int len = (int)log10(x) + 1;
        for(int i = 0, j = len-1; i < j; i++, j--) {
            int a = x / (int)pow(10, i) % 10;
            int b = x / (int)pow(10, j) % 10;
            if(a != b) return false;
        }
        return true;
    }
private:    
    int reverse(int x) {
        int y=0;

        int n;
        while( x!=0 ){
            n = x%10;
            y = y*10 + n;
            x /= 10;
        }
        return y;
    }
};



int main()
{
    Solution s;
    printf("%d is %d\n", 0, s.isPalindrome(0) );
    printf("%d is %d\n", -101, s.isPalindrome(-101) );
    printf("%d is %d\n", 1001, s.isPalindrome(1001) );
    printf("%d is %d\n", 1234321, s.isPalindrome(1234321) );
    printf("%d is %d\n", 2147447412, s.isPalindrome(2147447412) );
    printf("%d is %d\n", 2142, s.isPalindrome(2142) );
}
