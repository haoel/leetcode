// Source : https://leetcode.com/problems/closest-subsequence-sum/
// Author : Hao Chen
// Date   : 2021-02-15

/***************************************************************************************************** 
 *
 * You are given an integer array nums and an integer goal.
 * 
 * You want to choose a subsequence of nums such that the sum of its elements is the closest possible 
 * to goal. That is, if the sum of the subsequence's elements is sum, then you want to minimize the 
 * absolute difference abs(sum - goal).
 * 
 * Return the minimum possible value of abs(sum - goal).
 * 
 * Note that a subsequence of an array is an array formed by removing some elements (possibly all or 
 * none) of the original array.
 * 
 * Example 1:
 * 
 * Input: nums = [5,-7,3,5], goal = 6
 * Output: 0
 * Explanation: Choose the whole array as a subsequence, with a sum of 6.
 * This is equal to the goal, so the absolute difference is 0.
 * 
 * Example 2:
 * 
 * Input: nums = [7,-9,15,-2], goal = -5
 * Output: 1
 * Explanation: Choose the subsequence [7,-9,-2], with a sum of -4.
 * The absolute difference is abs(-4 - (-5)) = abs(1) = 1, which is the minimum.
 * 
 * Example 3:
 * 
 * Input: nums = [1,2,3], goal = -7
 * Output: 7
 * 
 * Constraints:
 * 
 * 	1 <= nums.length <= 40
 * 	-107 <= nums[i] <= 107
 * 	-109 <= goal <= 109
 ******************************************************************************************************/

class Solution {
private: 
    int abs(int n){
        return n>0 ? n : -n;
    }
    
    void printSet(set<int>& s){
        cout << "[";
        for(auto& n : s) {
            cout << n << ", ";
        }
        cout << "]" << endl;
    }
    
    int findClosetDiff(set<int>& sums, int goal) {
        auto it = sums.lower_bound(goal);
        
        // find the first item >= goal
        int high = (it == sums.end()) ? *(sums.rbegin()) : *it;
        // find the first item < goal
        int low = (it != sums.begin()) ? *(--it) : *it; 
        
        return min(abs(low - goal), abs(high - goal));
    }
    
    // walk through all of element, and each element could have two chioces:
    // add itself into sum or not. So, the time complexity is O(2^n)
    void getAllSums(int index, int end, vector<int>& nums, int sum, set<int>& sums) {
        if (index > end ) { // the latest one
            sums.insert(sum);
            return;
        }
        getAllSums(index+1, end, nums, sum+nums[index], sums); // add it into sum
        getAllSums(index+1, end, nums, sum, sums); // skip this item
    }
    
    void getAllSums(int start, int end, vector<int>& nums, set<int>& sums) {
        //sums.clear(); 
        sums.insert(0);
        for (int i=start; i<=end; i++) {
            vector<int> s(sums.begin(), sums.end());
            for (auto n : s) {
                sums.insert(n + nums[i]);
            }
        }
    }
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        set<int> sums_left, sums_right;
        //seprate the arrage to two parts
        int mid = nums.size() / 2;
        // ---The recusive way cause the TLE problem---
        //getAllSums(0, mid, nums, 0, sums_left);
        //getAllSums(mid+1, nums.size()-1, nums, 0, sums_right);
        getAllSums(0, mid, nums, sums_left);
        getAllSums(mid+1, nums.size()-1, nums, sums_right);
        
        int minDiff = INT_MAX;
        for (auto& sum : sums_left) {
            // Two Sum problem:
            //  - sum_left + sum_right = goal
            //  - sum_right = goal = sum_left
            minDiff = min(minDiff, findClosetDiff(sums_right, goal - sum));
        }
        return minDiff;
    }
    

};
