// Source : https://leetcode.com/problems/minimum-interval-to-include-each-query/
// Author : Hao Chen
// Date   : 2021-05-03

/***************************************************************************************************** 
 *
 * You are given a 2D integer array intervals, where intervals[i] = [lefti, righti] describes the i^th 
 * interval starting at lefti and ending at righti (inclusive). The size of an interval is defined as 
 * the number of integers it contains, or more formally righti - lefti + 1.
 * 
 * You are also given an integer array queries. The answer to the j^th query is the size of the 
 * smallest interval i such that lefti <= queries[j] <= righti. If no such interval exists, the answer 
 * is -1.
 * 
 * Return an array containing the answers to the queries.
 * 
 * Example 1:
 * 
 * Input: intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5]
 * Output: [3,3,1,4]
 * Explanation: The queries are processed as follows:
 * - Query = 2: The interval [2,4] is the smallest interval containing 2. The answer is 4 - 2 + 1 = 3.
 * - Query = 3: The interval [2,4] is the smallest interval containing 3. The answer is 4 - 2 + 1 = 3.
 * - Query = 4: The interval [4,4] is the smallest interval containing 4. The answer is 4 - 4 + 1 = 1.
 * - Query = 5: The interval [3,6] is the smallest interval containing 5. The answer is 6 - 3 + 1 = 4.
 * 
 * Example 2:
 * 
 * Input: intervals = [[2,3],[2,5],[1,8],[20,25]], queries = [2,19,5,22]
 * Output: [2,-1,4,6]
 * Explanation: The queries are processed as follows:
 * - Query = 2: The interval [2,3] is the smallest interval containing 2. The answer is 3 - 2 + 1 = 2.
 * - Query = 19: None of the intervals contain 19. The answer is -1.
 * - Query = 5: The interval [2,5] is the smallest interval containing 5. The answer is 5 - 2 + 1 = 4.
 * - Query = 22: The interval [20,25] is the smallest interval containing 22. The answer is 25 - 20 + 
 * 1 = 6.
 * 
 * Constraints:
 * 
 * 	1 <= intervals.length <= 10^5
 * 	1 <= queries.length <= 10^5
 * 	queries[i].length == 2
 * 	1 <= lefti <= righti <= 10^7
 * 	1 <= queries[j] <= 10^7
 ******************************************************************************************************/

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        set<vector<int>> s;
        
        vector<vector<int>> iQueries;
        for(int i=0; i < queries.size(); i++) {
            iQueries.push_back({queries[i], i});
        }
        
        sort(intervals.begin(), intervals.end());
        sort(iQueries.begin(), iQueries.end());
        
        vector<int> result(queries.size(), -1);
        
        int i = 0, len = intervals.size();
        
        for(auto& iq: iQueries) {
            int q = iq[0];
            int idx = iq[1];
            
            while( i < len && intervals[i][0] <= q) {
                s.insert({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }
            while( !s.empty() ) {
                auto it = s.begin();
                if ( (*it)[1] >= q ) break;
                s.erase(s.begin());
            }
            if ( !s.empty() ) {
                auto it = s.begin();
                result[idx] = (*it)[0];
            }
        }
        
        return result;
    }
};
