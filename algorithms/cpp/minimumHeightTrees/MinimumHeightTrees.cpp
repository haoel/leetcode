// Source : https://leetcode.com/problems/minimum-height-trees/
// Author : Hao Chen
// Date   : 2016-01-24

/*************************************************************************************** 
 *
 * For a undirected graph with tree characteristics, we can choose any node as the 
 * root. The result graph is then a rooted tree. Among all possible rooted trees, those 
 * with minimum height are called minimum height trees (MHTs).
 *
 * Given such a graph, write a function to find all the MHTs and return a list of 
 * their root labels.
 * 
 *     *Format*
 *     The graph contains n nodes which are labeled from 0 to n - 1.
 *     You will be given the number n and a list of undirected edges (each edge is a 
 *     pair of labels).
 * 
 *  
 *     You can assume that no duplicate edges will appear in edges. Since all edges are
 *     undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
 * 
 *     Example 1:
 * 
 *     Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]
 * 
 *         0
 *         |
 *         1
 *        / \
 *       2   3
 * 
 *     return  [1]
 * 
 *     Example 2:
 * 
 *     Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
 * 
 *      0  1  2
 *       \ | /
 *         3
 *         |
 *         4
 *         |
 *         5
 * 
 *     return  [3, 4]
 * 
 *     How many MHTs can a graph have at most?
 * 
 *     Note:
 * 
 *     (1) According to the definition of tree on Wikipedia: https://en.wikipedia.org/wiki/Tree_(graph_theory)
 *         “a tree is an undirected graph in which any two vertices are connected by exactly one path. 
 *         In other words, any connected graph without simple cycles is a tree.”
 * 
 *     (2) The height of a rooted tree is the number of edges on the longest downward path between 
 *         the root and a leaf.
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating all test 
 * cases.
 ***************************************************************************************/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        //corner case
        if ( n <= 1 ) return {0};
        
        //construct a edges search data stucture
        vector<unordered_set<int>> graph(n);
        for (auto e : edges) {
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }
        
        //find all of leaf nodes
        vector<int> current;
        for (int i=0; i<graph.size(); i++){
            if (graph[i].size() == 1)  current.push_back(i);
        }
        
        // BFS the graph
        while (true) {
            vector<int> next;
            for (int node : current) {
                for (int neighbor : graph[node]) {
                    graph[neighbor].erase(node);
                    if (graph[neighbor].size() == 1) next.push_back(neighbor);
                }
            }
            if (next.empty()) break;
            current = next;
        }
        return current;
    }
    
};
