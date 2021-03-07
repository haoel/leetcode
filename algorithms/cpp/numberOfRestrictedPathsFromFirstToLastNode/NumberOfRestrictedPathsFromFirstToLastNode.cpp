// Source : https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/
// Author : Hao Chen
// Date   : 2021-03-07

/***************************************************************************************************** 
 *
 * There is an undirected weighted connected graph. You are given a positive integer n which denotes 
 * that the graph has n nodes labeled from 1 to n, and an array edges where each edges[i] = [ui, vi, 
 * weighti] denotes that there is an edge between nodes ui and vi with weight equal to weighti.
 * 
 * A path from node start to node end is a sequence of nodes [z0, z1, z2, ..., zk] such that z0 = 
 * start and zk = end and there is an edge between zi and zi+1 where 0 <= i <= k-1.
 * 
 * The distance of a path is the sum of the weights on the edges of the path. Let 
 * distanceToLastNode(x) denote the shortest distance of a path between node n and node x. A 
 * restricted path is a path that also satisfies that distanceToLastNode(zi) > 
 * distanceToLastNode(zi+1) where 0 <= i <= k-1.
 * 
 * Return the number of restricted paths from node 1 to node n. Since that number may be too large, 
 * return it modulo 109 + 7.
 * 
 * Example 1:
 * 
 * Input: n = 5, edges = [[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]
 * Output: 3
 * Explanation: Each circle contains the node number in black and its distanceToLastNode value in 
 * blue. The three restricted paths are:
 * 1) 1 --> 2 --> 5
 * 2) 1 --> 2 --> 3 --> 5
 * 3) 1 --> 3 --> 5
 * 
 * Example 2:
 * 
 * Input: n = 7, edges = [[1,3,1],[4,1,2],[7,3,4],[2,5,3],[5,6,1],[6,7,2],[7,5,3],[2,6,4]]
 * Output: 1
 * Explanation: Each circle contains the node number in black and its distanceToLastNode value in 
 * blue. The only restricted path is 1 --> 3 --> 7.
 * 
 * Constraints:
 * 
 * 	1 <= n <= 2 * 104
 * 	n - 1 <= edges.length <= 4 * 104
 * 	edges[i].length == 3
 * 	1 <= ui, vi <= n
 * 	ui != vi
 * 	1 <= weighti <= 105
 * 	There is at most one edge between any two nodes.
 * 	There is at least one path between any two nodes.
 ******************************************************************************************************/

class Solution {
    void printVector(vector<int>& v) {
        cout << "[";
        for (int i = 0; i< v.size() -1 ; i ++) {
            cout << v[i] << ", ";
        }
        cout << v[v.size()-1] << "]" << endl;
    }
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        
        // re-orginanize the graph map
        vector<unordered_map<int, int>> graph(n);
        for(auto e : edges) {
            int x = e[0]-1;
            int y = e[1]-1;
            int d = e[2];
            graph[x][y] = graph[y][x] = d; 
        }
        
        
        
        //Dijkstra Algorithm
        vector<int> distance(n, INT_MAX);
        distance[n-1] = 0;
        
        auto cmp = [&](const int& lhs, const int& rhs) {return distance[lhs] > distance[rhs]; };
        priority_queue<int, vector<int>, decltype(cmp)> nodes(cmp);
        
        nodes.push(n-1);
        
        while( !nodes.empty() ) {
            int x = nodes.top(); nodes.pop();
            for(const auto & [ y, d ] : graph[x]) {  
                if ( distance[y] > d + distance[x] ) {
                    distance[y] = d + distance[x];
                    // if the node's distance is updated, 
                    // it's neighbor  must be recaluated 
                    nodes.push(y); 
                }
            }
        }
        
        //printVector(distance);
        

        //Dynamic Programming for restric paths
        vector<bool> visited(n, false);
        vector<long> restriced_path(n, 0);
        
        nodes.push(n-1);
        restriced_path[n-1] = 1;
        visited[n-1] = true;
        
        while( !nodes.empty() ) {
            int x = nodes.top(); nodes.pop();

            //cout << x+1 << ":";
            for(const auto & [ y, d ] : graph[x]) { 
                
                if ( distance[y] > distance[x]) {
                    restriced_path[y] += restriced_path[x];
                    restriced_path[y] %= 1000000007;
                }
                if (!visited[y]) {
                    //cout << y+1 << ",";
                    nodes.push(y);
                    visited[y] = true;
                }
            }
  
            //cout<<endl;
            //printVector(restriced_path);
        }
        //cout << "-------" <<endl;
        //printVector(restriced_path);
        return restriced_path[0];
    }
};
