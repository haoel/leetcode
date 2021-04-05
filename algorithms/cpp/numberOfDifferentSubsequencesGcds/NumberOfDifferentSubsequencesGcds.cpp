// Source : https://leetcode.com/problems/number-of-different-subsequences-gcds/
// Author : Hao Chen
// Date   : 2021-04-05

/***************************************************************************************************** 
 *
 * You are given an array nums that consists of positive integers.
 * 
 * The GCD of a sequence of numbers is defined as the greatest integer that divides all the numbers in 
 * the sequence evenly.
 * 
 * 	For example, the GCD of the sequence [4,6,16] is 2.
 * 
 * A subsequence of an array is a sequence that can be formed by removing some elements (possibly 
 * none) of the array.
 * 
 * 	For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
 * 
 * Return the number of different GCDs among all non-empty subsequences of nums.
 * 
 * Example 1:
 * 
 * Input: nums = [6,10,3]
 * Output: 5
 * Explanation: The figure shows all the non-empty subsequences and their GCDs.
 * The different GCDs are 6, 10, 3, 2, and 1.
 * 
 * Example 2:
 * 
 * Input: nums = [5,15,40,5,6]
 * Output: 7
 * 
 * Constraints:
 * 
 * 	1 <= nums.length <= 10^5
 * 	1 <= nums[i] <= 2 * 10^5
 ******************************************************************************************************/

class Solution {
private:
    // Euclidean algorithm
    // https://en.wikipedia.org/wiki/Euclidean_algorithm
    int gcd(int a, int b) {
        while ( b != 0 ) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int len = nums.size();
        vector<int> gcds(200001, 0);
        
        for(int i=0; i<len; i++) {
            int n = nums[i];
            int m = sqrt(n);
            for(int g=1; g<=m; g++){
                if (n % g != 0) continue;
                int x = g, y = n/g;
                if (x != y ){
                    gcds[x] = gcd(n, gcds[x]);
                    gcds[y] = gcd(n, gcds[y]);
                }else {
                    gcds[x] = gcd(n, gcds[x]);
                }
            }
        }
        
        int cnt = 0;
        for(int i=1; i<gcds.size(); i++){
            if (gcds[i]==i) cnt++;
        }
        return cnt;
    }
};
