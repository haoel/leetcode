// Source : https://leetcode.com/problems/maximum-number-of-groups-getting-fresh-donuts/
// Author : Hao Chen
// Date   : 2021-04-08

/***************************************************************************************************** 
 *
 * There is a donuts shop that bakes donuts in batches of batchSize. They have a rule where they must 
 * serve all of the donuts of a batch before serving any donuts of the next batch. You are given an 
 * integer batchSize and an integer array groups, where groups[i] denotes that there is a group of 
 * groups[i] customers that will visit the shop. Each customer will get exactly one donut.
 * 
 * When a group visits the shop, all customers of the group must be served before serving any of the 
 * following groups. A group will be happy if they all get fresh donuts. That is, the first customer 
 * of the group does not receive a donut that was left over from the previous group.
 * 
 * You can freely rearrange the ordering of the groups. Return the maximum possible number of happy 
 * groups after rearranging the groups.
 * 
 * Example 1:
 * 
 * Input: batchSize = 3, groups = [1,2,3,4,5,6]
 * Output: 4
 * Explanation: You can arrange the groups as [6,2,4,5,1,3]. Then the 1^st, 2^nd, 4^th, and 6^th 
 * groups will be happy.
 * 
 * Example 2:
 * 
 * Input: batchSize = 4, groups = [1,3,2,5,2,2,1,6]
 * Output: 4
 * 
 * Constraints:
 * 
 * 	1 <= batchSize <= 9
 * 	1 <= groups.length <= 30
 * 	1 <= groups[i] <= 10^9
 ******************************************************************************************************/

class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        vector<int> reminder(batchSize, 0);
        for(auto& g : groups) {
            reminder[g % batchSize]++;
        }
        
        // greedy for reminder is zero and two groups reminder is zero.
        // for example: batchSize = 3, groups = [1,2,3,4,5,6]
        // then we will find: (3) (6) (1,5) (2,4) 
        
        // greedy for one group
        int result = reminder[0]; 
        //greedy for two groups
        for (int i=1; i<=batchSize/2; i++){
            if (reminder[i] == 0 || reminder[batchSize-i] == 0 ) continue;
            
            int m = (i == batchSize-i) ? 
                reminder[i]/2 :
                min(reminder[i], reminder[batchSize-i]);
            
            reminder[i] -= m;
            reminder[batchSize-i] -= m;
            result += m;
        }
        
        map<vector<int>, int> cache;
        //DFS for the rest groups
        result += dfs(reminder, batchSize, 0, cache);
        return result;
    }
    
    int dfs(vector<int>& reminder, int batchSize, int sum, map<vector<int>, int>& cache) {
        if (cache.find(reminder) != cache.end()) return cache[reminder];
        int ret = 0; 
        int bonus = sum == 0 ? 1: 0;
        for(int i=1; i<batchSize; i++) {
            if (reminder[i] <= 0)  continue;
            reminder[i]--;
            ret = max(ret, bonus + dfs(reminder, batchSize, (sum + i) % batchSize, cache));
            reminder[i]++;
        }
        cache[reminder] = ret;
        return ret;
    }
};
