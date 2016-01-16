// Source : https://leetcode.com/problems/single-number-iii/
// Author : Hao Chen
// Date   : 2016-01-16

/*************************************************************************************** 
 *
 * Given an array of numbers nums, in which exactly two elements appear only once and 
 * all the other elements appear exactly twice. Find the two elements that appear only 
 * once.
 * 
 * For example:
 * 
 * Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 * 
 * Note:
 * 
 * The order of the result is not important. So in the above example, [5, 3] is also 
 * correct.
 * Your algorithm should run in linear runtime complexity. Could you implement it using 
 * only constant space complexity?
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating 
 * all test cases.
 ***************************************************************************************/


/*
 * For the problem - only one number appears once when all other numbers appears exactly twice.
 * 
 * We know, we can XOR all of the array elements. Since X^X is zero, and X^0 is X, 
 * so all of the duplicated number will zero themselves out, and the only number would be the result.
 * 
 * However, this solution cannot be applied directly to finding two numbers that appear once each. 
 * 
 * Suppose that these numbers that appear once are X and Y, and all other numbers appear twice. 
 * If we decide to XOR all the array's elements, the overall result would actually be `X^Y`. 
 * 
 * Unfortunately, there is no way to extract J and K out of their XOR. 
 * 
 * But since X and Y are different, we are sure that X^Y is different than zero. 
 * 
 * This information is valuable in sense that we know pieces of information that differ.
 * If we pick up any bit that is 1 in X XOR Y, we can use it as a mask to test each element of the array. 
 * 
 * Obviously, that mask will be the discriminator between X and Y - 
 * 
 *    Only one of them will have value 1 at that particular position.
 *         
 *         
 * Now that we have the mask with exactly one bit set to 1, we can walk through the array once again. 
 * 
 * But this time we are going to maintain two XORed results. 
 * 
 *   - One for numbers that have bit 1 at the mask's position 
 *   - Another for numbers that have bit 0 at that position
 *   
 * In this way, we are sure that all duplicates will go into the same pile. 
 * 
 * But likewise, we are sure that X and Y will go into separate piles. 
 * 
 * So, the overall result is that 
 *  - the first XORed result will be equal to X 
 *  - and the second XORed result will be equal to Y
 *  
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int allxor = 0;
        for (int n : nums) {
            allxor ^= n;
        }
        int mask = 1;
        while ( (mask & allxor) == 0 ) {
            mask <<= 1;
        }

        int zero = 0;
        int one = 0;
        for (int n : nums) {
            if (n & mask ){
                one ^= n;
            }else {
                zero ^= n;
            }
        }
        
        vector<int> result;
        result.push_back(zero);
        result.push_back(one);
        return result;
    }
};
