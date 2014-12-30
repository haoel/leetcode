// Source : https://oj.leetcode.com/problems/factorial-trailing-zeroes/
// Author : Hao Chen
// Date   : 2014-12-30

/********************************************************************************** 
 * 
 * Given an integer n, return the number of trailing zeroes in n!.
 * 
 * Note: Your solution should be in polynomial time complexity.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *               
 **********************************************************************************/

/*
 * The idea is: 
 * 
 *  1. The ZERO comes from 10.  
 *  2. The 10 comes from 2 x 5 
 *  3. And we need to account for all the products of 5 and 2. likes 4×5 = 20 ...
 *  4. So, if we take all the numbers with 5 as a factor, we'll have way more than enough even numbers 
 *     to pair with them to get factors of 10
 * 
 * **Example One**
 * 
 * How many multiples of 5 are between 1 and 23? 
 * There is 5, 10, 15, and 20, for four multiples of 5. Paired with 2's from the even factors, 
 * this makes for four factors of 10, so: **23! has 4 zeros**.
 * 
 * 
 * **Example Two**
 * 
 * How many multiples of 5 are there in the numbers from 1 to 100? 
 * 
 * because   100 ÷ 5 = 20, so, there are twenty multiples of 5 between 1 and 100.
 * 
 * but wait, actually 25 is 5×5, so each multiple of 25 has an extra factor of 5, 
 * ( e.g. 25 × 4 = 100，which introduces extra of zero )
 * 
 * So, we need know how many multiples of 25 are between 1 and 100? Since 100 ÷ 25 = 4, 
 * (there are four multiples of 25 between 1 and 100)
 * 
 * Finally, we get 20 + 4 = 24 trailing zeroes in 100!
 * 
 * 
 * The above example tell us, we need care about 5, 5×5, 5×5×5, 5×5×5×5 ....
 * 
 * **Example Three**
 * 
 * 
 * 5^1 :  4617 ÷ 5 = 923.4, so we get 923 factors of 5
 * 5^2 :  4617 ÷ 25 = 184.68, so we get 184 additional factors of 5
 * 5^3 :  4617 ÷ 125 = 36.936, so we get 36 additional factors of 5
 * 5^4 :  4617 ÷ 625 = 7.3872, so we get 7 additional factors of 5
 * 5^5 :  4617 ÷ 3125 = 1.47744, so we get 1 more factor of 5
 * 5^6 :  4617 ÷ 15625 = 0.295488, which is less than 1, so stop here.
 * 
 * Then 4617! has 923 + 184 + 36 + 7 + 1 = 1151 trailing zeroes.
 * 
 */


class Solution {
    public:
        int trailingZeroes(int n) {
            int result = 0;
            //To avoid the integer overflow ( e.g. 'n >=1808548329' )
            for(long long i=5; n/i>0 && i <= INT_MAX; i*=5){
                result += (n/i);
            }
            return result;
        }

        // Alternative implementation which naturally avoid integer overflow issue.
        int trailingZeroes(int n) {
            int sum=0;
            int tmp=0;
            while(n/5>0)
            {
                tmp=n/5;
                sum+=tmp;
                n=tmp;
            }
            return sum;
        }
};
