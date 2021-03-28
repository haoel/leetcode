// Source : https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/
// Author : Hao Chen
// Date   : 2021-03-28

/***************************************************************************************************** 
 *
 * There is an integer array nums that consists of n unique elements, but you have forgotten it. 
 * However, you do remember every pair of adjacent elements in nums.
 * 
 * You are given a 2D integer array adjacentPairs of size n - 1 where each adjacentPairs[i] = [ui, vi] 
 * indicates that the elements ui and vi are adjacent in nums.
 * 
 * It is guaranteed that every adjacent pair of elements nums[i] and nums[i+1] will exist in 
 * adjacentPairs, either as [nums[i], nums[i+1]] or [nums[i+1], nums[i]]. The pairs can appear in any 
 * order.
 * 
 * Return the original array nums. If there are multiple solutions, return any of them.
 * 
 * Example 1:
 * 
 * Input: adjacentPairs = [[2,1],[3,4],[3,2]]
 * Output: [1,2,3,4]
 * Explanation: This array has all its adjacent pairs in adjacentPairs.
 * Notice that adjacentPairs[i] may not be in left-to-right order.
 * 
 * Example 2:
 * 
 * Input: adjacentPairs = [[4,-2],[1,4],[-3,1]]
 * Output: [-2,4,1,-3]
 * Explanation: There can be negative numbers.
 * Another solution is [-3,1,4,-2], which would also be accepted.
 * 
 * Example 3:
 * 
 * Input: adjacentPairs = [[100000,-100000]]
 * Output: [100000,-100000]
 * 
 * Constraints:
 * 
 * 	nums.length == n
 * 	adjacentPairs.length == n - 1
 * 	adjacentPairs[i].length == 2
 * 	2 <= n <= 10^5
 * 	-10^5 <= nums[i], ui, vi <= 10^5
 * 	There exists some nums that has adjacentPairs as its pairs.
 ******************************************************************************************************/

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        // only two numbers have one neighbour
        // start from one of them to travel all number.
        
        unordered_map<int, vector<int>> dict;
        for(auto& pair : adjacentPairs) {
            dict[pair[0]].push_back(pair[1]);
            dict[pair[1]].push_back(pair[0]);
        }
        
        int end[2]; int i=0;
        for (auto& [key, pair] : dict) {
            if(pair.size()==1) end[i++] = key;
            if (i>1) break;
        }
        //cout << "start=" << end[0] <<", end=" << end[1] << endl;
        vector<int> result(1, end[0]);
        int start = end[0];
        int prev = -1;
        while ( start != end[1] ) {
            auto& v = dict[start];
            for(int i= 0; i< v.size(); i++) {
                if (v[i] == prev) continue;
                result.push_back(v[i]);
                prev = start;
                start = v[i];
                break;
            }
        }
        return result;
    }
};
