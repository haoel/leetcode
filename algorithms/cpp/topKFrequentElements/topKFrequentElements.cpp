// Source : https://leetcode.com/problems/top-k-frequent-elements/
// Author : Calinescu Valentin
// Date   : 2016-05-02

/*************************************************************************************** 
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * For example,
 * Given [1,1,1,2,2,3] and k = 2, return [1,2].
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is the 
 * array's size.
 * 
 ***************************************************************************************/

class Solution {
public:
    struct element//structure consisting of every distinct number in the vector,
    //along with its frequency
    {
        int number, frequency;
        bool operator < (const element arg) const
        {
            return frequency < arg.frequency;
        }
    };
    priority_queue <element> sol;//we use a heap so we have all of the elements sorted
    //by their frequency
    vector <int> solution;
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 1;
        for(; i < nums.size(); i++)
        {
            int freq = 1;
            while(i < nums.size() && nums[i] == nums[i - 1])
            {
                i++;
                freq++;
            }
            element el;
            el.number = nums[i - 1];
            el.frequency = freq;
            sol.push(el);
        }
        if(i == nums.size())//if we have 1 distinct element as the last
        {
            element el;
            el.number = nums[nums.size() - 1];
            el.frequency = 1;
            sol.push(el);
        }
        while(k)//we extract the first k elements from the heap
        {
            solution.push_back(sol.top().number);
            sol.pop();
            k--;
        }
        return solution;
    }
};
