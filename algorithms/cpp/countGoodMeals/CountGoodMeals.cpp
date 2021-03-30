// Source : https://leetcode.com/problems/count-good-meals/
// Author : Hao Chen
// Date   : 2021-03-30

/***************************************************************************************************** 
 *
 * A good meal is a meal that contains exactly two different food items with a sum of deliciousness 
 * equal to a power of two.
 * 
 * You can pick any two different foods to make a good meal.
 * 
 * Given an array of integers deliciousness where deliciousness[i] is the deliciousness of the i^​​​​​​
 * th​​​​​​​​ item of food, return the number of different good meals you can make from this list 
 * modulo 10^9 + 7.
 * 
 * Note that items with different indices are considered different even if they have the same 
 * deliciousness value.
 * 
 * Example 1:
 * 
 * Input: deliciousness = [1,3,5,7,9]
 * Output: 4
 * Explanation: The good meals are (1,3), (1,7), (3,5) and, (7,9).
 * Their respective sums are 4, 8, 8, and 16, all of which are powers of 2.
 * 
 * Example 2:
 * 
 * Input: deliciousness = [1,1,1,3,3,3,7]
 * Output: 15
 * Explanation: The good meals are (1,1) with 3 ways, (1,3) with 9 ways, and (1,7) with 3 ways.
 * 
 * Constraints:
 * 
 * 	1 <= deliciousness.length <= 10^5
 * 	0 <= deliciousness[i] <= 2^20
 ******************************************************************************************************/

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        const int MAX_EXP = 22;
        int pow2[MAX_EXP];
        for (int i=0; i<MAX_EXP; i++){
            pow2[i] = 1 << i;
            //cout << pow2[i] << ", ";
        }
        
        unordered_map<int, int> stat;
        int big = 0;
        for(auto& d: deliciousness){
            stat[d]++;

        }

        long m = 0;
        for(auto& d: deliciousness){
            for(int i=MAX_EXP-1; i>=0 && pow2[i] >= d; i--){
                int x = pow2[i] - d;
                if ( stat.find(x) != stat.end() ){
                    m += (x==d) ? stat[x]-1 : stat[x];
                }
            }
        }
        
        // remove the duplication - m/2, 
        // because both [1,3] and [3,1] are counted.
        return (m/2) % 1000000007;
    }
};
