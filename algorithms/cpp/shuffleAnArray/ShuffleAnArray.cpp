// Source : https://leetcode.com/problems/shuffle-an-array/
// Author : Hao Chen
// Date   : 2016-08-24

/*************************************************************************************** 
 *
 * Shuffle a set of numbers without duplicates.
 * 
 * Example:
 * 
 * // Init an array with set 1, 2, and 3.
 * int[] nums = {1,2,3};
 * Solution solution = new Solution(nums);
 * 
 * // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must 
 * equally likely to be returned.
 * solution.shuffle();
 * 
 * // Resets the array back to its original configuration [1,2,3].
 * solution.reset();
 * 
 * // Returns the random shuffling of array [1,2,3].
 * solution.shuffle();
 ***************************************************************************************/

class Solution {
public:
    Solution(vector<int> nums) : _nums(nums), _solution(nums) {
        srand(time(NULL));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return _solution = _nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        //Fisher Yates
        //https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
        
        int i = _solution.size();
        
        while ( --i > 0 ) {
            int j = rand() % (i+1);
            swap(_solution[i], _solution[j]);
        }
        return _solution;
    }
private:
    vector<int> _nums, _solution;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
