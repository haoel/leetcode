// Source : https://leetcode.com/problems/largest-color-value-in-a-directed-graph/
// Author : Hao Chen
// Date   : 2021-05-10

/***************************************************************************************************** 
 *
 * There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.
 * 
 * You are given a string colors where colors[i] is a lowercase English letter representing the color 
 * of the i^th node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = 
 * [aj, bj] indicates that there is a directed edge from node aj to node bj.
 * 
 * A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a 
 * directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of 
 * nodes that are colored the most frequently occurring color along that path.
 * 
 * Return the largest color value of any valid path in the given graph, or -1 if the graph contains a 
 * cycle.
 * 
 * Example 1:
 * 
 * Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
 * Output: 3
 * Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above 
 * image).
 * 
 * Example 2:
 * 
 * Input: colors = "a", edges = [[0,0]]
 * Output: -1
 * Explanation: There is a cycle from 0 to 0.
 * 
 * Constraints:
 * 
 * 	n == colors.length
 * 	m == edges.length
 * 	1 <= n <= 10^5
 * 	0 <= m <= 10^5
 * 	colors consists of lowercase English letters.
 * 	0 <= aj, bj < n
 ******************************************************************************************************/


const int COLOR_CNT = 26;

class Node {
public:
    Node(char c) {
        incomming = 0;
        color = c;
        processed = false;
        memset(colors, 0, sizeof(colors));
    }
    void AddMyColor() { colors[color]++; }
    void Processed() { processed = true; }
    bool isProcessed() { return processed; }
    void AddIncomming(int n=1) { incomming += n;}
    int Incomming() {return incomming;}
    void AddChildNode(int n) { children.push_back(n); }
    vector<int>& Children() { return children; }
    int ChildrenCount() { return children.size(); }
    int* Colors() {return colors;}
    int MaxColorValue() {
        int m = -1;
        for(auto c: colors) {
            m = max(m, c);
        }
        return m;
    }
    void MergeChildColors(Node& child){
        int* c = child.Colors();
        for(int i=0; i<COLOR_CNT; i++) {
            colors[i] = max(colors[i], c[i]);
        }
    }

private:
    int incomming;          // incomming connection
    char color;             // node's color
    bool processed;         // if the node has been processed
    int colors[COLOR_CNT];  // the colors count stastices 
    vector<int> children;   // children nodes
};


class Solution {
private:
    void print(vector<int>& v) {
        cout << "[";
        int i = 0;
        for(; i<v.size()-1; i++) {
            cout << v[i] << ",";
        }
        cout << v[i] << "]" << endl;
    }
private:
    int nodes_cnt;
    vector<Node> nodes;
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        nodes_cnt = colors.size() ;
        for(int i=0; i<nodes_cnt; i++) {
            Node n( colors[i]-'a');
            nodes.push_back(n);
        }
        for(auto& e : edges) {
            nodes[e[0]].AddChildNode(e[1]);
            nodes[e[1]].AddIncomming();
        }
        
         vector<bool> visited(nodes_cnt, false);
        
        // We can do toplogical sort
        // 
        //vector<int> topSort;
        //for(int id=0; id <nodes_cnt; id++){
        //    auto& n = nodes[id];
        //    topologicalSort(id, topSort, visited);
        //}
        //print(topSort);
        
        int m = -1;
        for (int i=0; i<nodes_cnt; i++) {
            //int id = topSort[i];
            int id = i;
            auto& n = nodes[id];
            
            //using to check cycle.
            std::fill(visited.begin(), visited.end(), false);
            
            bool succ = travel(id, visited);
            if (!succ) return -1;
           
            m = max(m, nodes[id].MaxColorValue());
        }
        return m;
    }
    
    void topologicalSort(int i, vector<int>& topSort, vector<bool>& visited) {
        if (visited[i]) return;
        visited[i] = true;
        for(auto& id : nodes[i].Children()) {
            if (!visited[id]) {
                topologicalSort(id, topSort, visited);
            }
        }
        topSort.push_back(i);
    }
    
    //return true if it is successful
    //return false if there is an error  - has cycle
    bool travel(int i, vector<bool>& visited ) {
        //this node has been processed already
        if (nodes[i].isProcessed()) return true;
        
        //cycled 
        if (visited[i]) return false;
        visited[i] = true;
        
        // leaf node
        if (nodes[i].ChildrenCount() <= 0 ) {
            nodes[i].AddMyColor();
            nodes[i].Processed();
            return true;
        }
      
        for(auto& n : nodes[i].Children() ) {
            bool succ = travel(n, visited);
            if (!succ) return false;
            nodes[i].MergeChildColors( nodes[n] );
        }
        
        nodes[i].AddMyColor();
        nodes[i].Processed();

        //cout << "["<< i << "]: " ;
        //for(int k=0; k<26; k++) {
        //    cout << nodes[i].colors[k] << " ";
        //}
        //cout << endl;
        
        return true;
    }
};
