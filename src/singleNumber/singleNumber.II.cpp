// Source : https://oj.leetcode.com/problems/single-number-ii/
// Author : Hao Chen
// Date   : 2014-06-17

/********************************************************************************** 
* 
* Given an array of integers, every element appears three times except for one. Find that single one.
* 
* Note:
* Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
* 
*               
**********************************************************************************/

class Solution {
public:
    Solution(){
        srand(time(0));
    }
    
    //random invoker
    int singleNumber(int A[], int n) {
        if (rand()%2){
            return singleNumber_1(A, n);
        }
        return singleNumber_2(A, n);
    }

    /*
     *  This solution is clear & straightforward implementation.
     *  
     *  We use an array of 32 length(e.g. count[32]) to count the the bits for all of numbers. 
     *
     *  Because the same number appear 3 times, which means the sum of i-th bits for all numbers should be 3 times.
     *
     *  In other word, the sum of i-th bits mod 3, it must be 0 or 1. 1 means that is the single number bit.
     *
     * This solution can be easy to extend to "every element appears k times except for one."
     *
     */
    int singleNumber_1(int A[], int n) {
        int count[32] = {0};
        int result = 0;
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < n; j++) {
                if ((A[j] >> i) & 1) {
                    count[i]++;
                }
            }
            result |= ((count[i] % 3) << i);
        }
        return result;
    }


    /*
     *   The following solution is popular solution on Internet, but it looks it's not easy to understand.
     *
     *   Actually, it just optimizes the above soultion.
     *
     *   Let's see how it improve the above.
     *
     *   We use three bitmask, 
     *    1) `ones` stores current bits.
     *    2) `twos` stores 1s that have appeared twice.
     *    3) `threes` stores 1s that have appeared three times.
     *
     *    When there are 1s that have appeared three times, remove them from both `ones` and `twos`.
     *    And all 1s that just appeared twice did not affect the final bits by using XOR operations.
     *    The final answer will be the value of `ones`
     *
     */
    int singleNumber_2(int A[], int n) {
        int ones = 0, twos = 0, threes = 0;
        for (int i = 0; i < n; i++) {
            twos |= ones & A[i];  // use OR "|=" to keep old 1s in `two`, not "="
            ones ^= A[i];
            threes = ones & twos;
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;
    }

};
