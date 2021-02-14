// Source : https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/
// Author : Hao Chen
// Date   : 2021-02-14

/***************************************************************************************************** 
 *
 * You are given an undirected graph. You are given an integer n which is the number of nodes in the 
 * graph and an array edges, where each edges[i] = [ui, vi] indicates that there is an undirected edge 
 * between ui and vi.
 * 
 * A connected trio is a set of three nodes where there is an edge between every pair of them.
 * 
 * The degree of a connected trio is the number of edges where one endpoint is in the trio, and the 
 * other is not.
 * 
 * Return the minimum degree of a connected trio in the graph, or -1 if the graph has no connected 
 * trios.
 * 
 * Example 1:
 * 
 * Input: n = 6, edges = [[1,2],[1,3],[3,2],[4,1],[5,2],[3,6]]
 * Output: 3
 * Explanation: There is exactly one trio, which is [1,2,3]. The edges that form its degree are bolded 
 * in the figure above.
 * 
 * Example 2:
 * 
 * Input: n = 7, edges = [[1,3],[4,1],[4,3],[2,5],[5,6],[6,7],[7,5],[2,6]]
 * Output: 0
 * Explanation: There are exactly three trios:
 * 1) [1,4,3] with degree 0.
 * 2) [2,5,6] with degree 2.
 * 3) [5,6,7] with degree 2.
 * 
 * Constraints:
 * 
 * 	2 <= n <= 400
 * 	edges[i].length == 2
 * 	1 <= edges.length <= n * (n-1) / 2
 * 	1 <= ui, vi <= n
 * 	ui != vi
 * 	There are no repeated edges.
 ******************************************************************************************************/

class Solution {
private:
    vector<vector<bool>>* edge_matrix;
    vector<int>* node_edge_num;
    
    bool has_edge(int x, int y) {
        return (*edge_matrix)[x][y];
    }
    
    int node_edges(int x){
        return (*node_edge_num)[x];
    }
    
    int degree(int x, int y, int z) {
        if (has_edge(x,y) && has_edge(y,z) && has_edge(x,z)) {
            return node_edges(x) +  node_edges(y) +  node_edges(z) - 6; 
        }
        return -1;
    }
public:
   
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> edge_matrix(n+1, vector<bool>(n+1, false));
        vector<int> node_edge_num(n+1, 0);
        
        this->edge_matrix = &edge_matrix;
        this->node_edge_num = &node_edge_num;
        
        for (auto& edge : edges) {
            edge_matrix[edge[0]][edge[1]] = true;
            edge_matrix[edge[1]][edge[0]] = true;
            node_edge_num[edge[0]]++;
            node_edge_num[edge[1]]++;
        }
        
        int result = -1;
        for(int i=1; i<=n; i++) {
            if (node_edge_num[i] < 2) continue;
            for(int j=i+1; j<=n; j++) {
                if (!has_edge(i, j)) continue;
                for(int k=j+1; k<=n; k++) {
                    if (!has_edge(j, k)) continue;
                    int d = degree(i, j, k);
                    if ( d >= 0 ) {
                        result = result < 0 ? d : min(result, d);
                    }
                }
            }
        }
        return result;
    }
};
