// Source : https://leetcode.com/problems/sum-of-unique-elements/
// Author : Hao Chen
// Date   : 2021-02-12

/***************************************************************************************************** 
 *
 * You are given an integer array nums. The unique elements of an array are the elements that appear 
 * exactly once in the array.
 * 
 * Return the sum of all the unique elements of nums.
 * 
 * Example 1:
 * 
 * Input: nums = [1,2,3,2]
 * Output: 4
 * Explanation: The unique elements are [1,3], and the sum is 4.
 * 
 * Example 2:
 * 
 * Input: nums = [1,1,1,1,1]
 * Output: 0
 * Explanation: There are no unique elements, and the sum is 0.
 * 
 * Example 3:
 * 
 * Input: nums = [1,2,3,4,5]
 * Output: 15
 * Explanation: The unique elements are [1,2,3,4,5], and the sum is 15.
 * 
 * Constraints:
 * 
 * 	1 <= nums.length <= 100
 * 	1 <= nums[i] <= 100
 ******************************************************************************************************/

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        return sumOfUnique_special(nums);
        return sumOfUnique_general(nums);
    }
    
    int sumOfUnique_general(vector<int>& nums) {
        enum stat {UNIQ, DUP};
        unordered_map<int, stat> dict;
        int sum = 0;
        for (auto i : nums) {
            if (dict.find(i) == dict.end()){
                sum += i;
                dict[i] = UNIQ;
            } else {
                if (dict[i] == UNIQ) {
                    sum -= i;
                    dict[i] = DUP;
                }
            }
            
        }
        return sum;
    }
    
    int sumOfUnique_special(vector<int>& nums) {
        //because we have constraint: 1 <= nums[i] <= 100
        //we can use array instead of map 
        enum stat {NO=0,UNIQ=1,DUP=2};
        stat dict[100]={NO};
        int sum = 0;
        for (auto i : nums) {
            switch(dict[i-1]) {
                case NO:
                    sum += i;
                    dict[i-1] = UNIQ;
                    break;
                case UNIQ:
                    sum -= i;
                    dict[i-1] = DUP;
                    break;
                default:
                    continue;
            }
        }
        return sum;
    }
    
};
