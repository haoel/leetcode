// Source : https://leetcode.com/problems/contains-duplicate-iii/
// Author : Hao Chen
// Date   : 2015-06-12

/********************************************************************************** 
 * 
 * Given an array of integers, find out whether there are two distinct indices i and j 
 * in the array such that the difference between nums[i] and nums[j] is at most t and 
 * the difference between i and j is at most k.
 *               
 **********************************************************************************/



class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size() < 2 || k == 0) return false;
        int low = 0;
        //maintain a sliding window 
        set<long long> window;
        for (int i=0; i<nums.size(); i++){
            //make sure window size <= k
            if (i - low > k) {
                window.erase(nums[low]);
                low++;
            }
            
            // lower_bound() is the key, 
            // it returns an iterator pointing to the first element >= val 
            auto it = window.lower_bound((long long)nums[i] - (long long)t );
            if (it != window.end() && abs((long long)nums[i] - *it) <= (long long)t) {
                return true;
            }
            window.insert(nums[i]);
        }
        return false;
    }
};

