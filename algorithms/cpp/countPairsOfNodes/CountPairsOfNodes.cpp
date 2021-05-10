// Source : https://leetcode.com/problems/count-pairs-of-nodes/
// Author : Hao Chen
// Date   : 2021-03-23

/***************************************************************************************************** 
 *
 * You are given an undirected graph represented by an integer n, which is the number of nodes, and 
 * edges, where edges[i] = [ui, vi] which indicates that there is an undirected edge between ui and 
 * vi. You are also given an integer array queries.
 * 
 * The answer to the j^th query is the number of pairs of nodes (a, b) that satisfy the following 
 * conditions:
 * 
 * 	a < b
 * 	cnt is strictly greater than queries[j], where cnt is the number of edges incident to a or 
 * b.
 * 
 * Return an array answers such that answers.length == queries.length and answers[j] is the answer of 
 * the j^th query.
 * 
 * Note that there can be repeated edges.
 * 
 * Example 1:
 * 
 * Input: n = 4, edges = [[1,2],[2,4],[1,3],[2,3],[2,1]], queries = [2,3]
 * Output: [6,5]
 * Explanation: The number of edges incident to at least one of each pair is shown above.
 * 
 * Example 2:
 * 
 * Input: n = 5, edges = [[1,5],[1,5],[3,4],[2,5],[1,3],[5,1],[2,3],[2,5]], queries = [1,2,3,4,5]
 * Output: [10,10,9,8,6]
 * 
 * Constraints:
 * 
 * 	2 <= n <= 2 * 10^4
 * 	1 <= edges.length <= 10^5
 * 	1 <= ui, vi <= n
 * 	ui != vi
 * 	1 <= queries.length <= 20
 * 	0 <= queries[j] < edges.length
 ******************************************************************************************************/

/*
   The constraint `a < b` could mislead us,
      - it doesn't mean we need check the pair,
      - it only means we don't include the duplicated pair.

   For Example: [1, 2] and [2, 1] are duplicated.

   So, we can ignore the `a < b` if we make sure there hasn't duplicated pair.




   We assume all of the nodes are independent, and there is no any pair has connection.
   So, we can count the number of edge for every node.

   For Example: n = 4, edges = [[1,2],[2,4],[1,3],[2,3],[2,1]],

   We can have - the `degree` means number of edges.
        degree[1] = 3
        degree[2] = 4
        degree[3] = 2
        degree[4] = 1

   Then, we could sort all of node by their edges.

       degree:  1 ,  2 ,  3 ,  4
         node: [4], [3], [1], [2]

   Now, if the `query = 2`, we can have two pointer, one is from left, another one from right.

         degree:  1 ,  2 ,  3 ,  4
           node: [4], [3], [1], [2]
                  ^              ^
                  left          right

        So, (degree[left] + degree[right] > q), it means we can have the following pairs:

         degree:     1+4   2+4   3+4
           node:    [4,2] [3,2] [1,2]

         ( NB: don't worry about [4,2] & [3,2] are not satsfied `a>b`, they could be [2,4] & [2,3] )

        Then, we can have the following soure code:

            if (degree[left] + degree[right] > query) {
                count_of_pairs = right - left;
                right--;
            }else {
                left++;
            }



   Now, we can deal with pair which are connected, because they have shared edges.
   So, we need go through all of the pairs they are connect.

   And we need check two condition:

   -  `degree[a] + degree[b] > query` ==> this pair had been counted before!
   -  `degree[a] + degree[b] - shared_edges(a,b) < query` ==> this pair should be counted!

*/

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> degree(n+1);
        unordered_map<int, unordered_map<int, int>> shared;
        for (auto& e : edges) {
            int x = e[0], y = e[1];
            degree[x]++;
            degree[y]++;
            shared[min(x,y)][max(x,y)]++;
        }

        vector<int> sorted = degree;
        sort(sorted.begin(), sorted.end());

        vector<int> result;
        for (auto& q : queries) {
            int cnt = 0;
            int left = 1, right = n;
            //Assuming all of the nodes are independent.
            while( left < right ) {
                if (q < sorted[left] + sorted[right] ) {
                    cnt += (right - left);
                    right--;
                }else {
                    left++;
                }
            }
            //check all of pair they are connected.
            for (int i = 1; i <= n; i++){
                for (auto [j, shared_edges] : shared[i]) {
                    int all_edges = degree[i] + degree[j];
                    // `q < all_edges`  ==> this pair had been counted before!
                    // `q >= all_edges - shared_edges` ==> this pair should be counted!
                    if ( q < all_edges && q >= all_edges - shared_edges ) {
                        cnt--;
                    }
                }
            }
            result.push_back(cnt);
        }
        return result;
    }
};
