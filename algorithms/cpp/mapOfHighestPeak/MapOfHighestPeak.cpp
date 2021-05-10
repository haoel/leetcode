// Source : https://leetcode.com/problems/map-of-highest-peak/
// Author : Hao Chen
// Date   : 2021-03-26

/***************************************************************************************************** 
 *
 * You are given an integer matrix isWater of size m x n that represents a map of land and water cells.
 * 
 * 	If isWater[i][j] == 0, cell (i, j) is a land cell.
 * 	If isWater[i][j] == 1, cell (i, j) is a water cell.
 * 
 * You must assign each cell a height in a way that follows these rules:
 * 
 * 	The height of each cell must be non-negative.
 * 	If the cell is a water cell, its height must be 0.
 * 	Any two adjacent cells must have an absolute height difference of at most 1. A cell is 
 * adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., 
 * their sides are touching).
 * 
 * Find an assignment of heights such that the maximum height in the matrix is maximized.
 * 
 * Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there 
 * are multiple solutions, return any of them.
 * 
 * Example 1:
 * 
 * Input: isWater = [[0,1],[0,0]]
 * Output: [[1,0],[2,1]]
 * Explanation: The image shows the assigned heights of each cell.
 * The blue cell is the water cell, and the green cells are the land cells.
 * 
 * Example 2:
 * 
 * Input: isWater = [[0,0,1],[1,0,0],[0,0,0]]
 * Output: [[1,1,0],[0,1,1],[1,2,2]]
 * Explanation: A height of 2 is the maximum possible height of any assignment.
 * Any height assignment that has a maximum height of 2 while still meeting the rules will also be 
 * accepted.
 * 
 * Constraints:
 * 
 * 	m == isWater.length
 * 	n == isWater[i].length
 * 	1 <= m, n <= 1000
 * 	isWater[i][j] is 0 or 1.
 * 	There is at least one water cell.
 ******************************************************************************************************/

class Cell{
public:
    int x;
    int y;
    int height;
};

class Solution {
private:
    void setHeight(vector<vector<int>>& height, 
                   queue<Cell>& q,
                   int x, int y, int h, 
                   int m, int n) 
    {
        if (x < 0 || y < 0 || x>=m || y>=n ) return;
        if (height[x][y] == -1) {
            height[x][y] = h;
            q.push({x, y, h});
        }
    }
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        int m = isWater.size();
        int n = isWater[0].size();
        
        vector<vector<int>> height(m, vector(n, -1));
        queue<Cell> q;
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (isWater[i][j]) {
                    height[i][j] = 0;
                    q.push({i, j, 0});
                }
            }
        }
        
        while(!q.empty()){
            auto cell = q.front(); q.pop();
            setHeight(height, q, cell.x-1, cell.y, cell.height+1,  m, n);
            setHeight(height, q, cell.x+1, cell.y, cell.height+1,  m, n);
            setHeight(height, q, cell.x, cell.y-1, cell.height+1,  m, n);
            setHeight(height, q, cell.x, cell.y+1, cell.height+1,  m, n);
        }
        
        return height;
    }
                        
};
