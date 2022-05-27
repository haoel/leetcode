// Source : https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
// Author : Kritebh
// Date   : 2021-12-26

/***************************************************************************************

Given an integer number n, return the difference between the product of its digits and the sum of its digits.

Example 1:
Input: n = 234
Output: 15 
Explanation: 
Product of digits = 2 * 3 * 4 = 24 
Sum of digits = 2 + 3 + 4 = 9 
Result = 24 - 9 = 15

Example 2:
Input: n = 4421
Output: 21
Explanation: 
Product of digits = 4 * 4 * 2 * 1 = 32 
Sum of digits = 4 + 4 + 2 + 1 = 11 
Result = 32 - 11 = 21

Constraints:
1 <= n <= 10^5

We are going to apply simple approach as said in question

First extract the digit from given number then find product and sum

Finally return product -sum in integer

******************************************************************************************/

class Solution {
public:
    int subtractProductAndSum(int n) {
        
        long long int product=1;
        long long int sum =0;
        long long int digit;
        while(n){
            digit = n%10;
            product*=digit;
            sum+=digit;
            n/=10;
        }
        
        return (int)product - sum;
    }
};