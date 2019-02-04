// Source : https://leetcode.com/problems/island-perimeter/
// Author : Hao Chen
// Date   : 2019-02-04

/***************************************************************************************************** 
 *
 * You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 
 * represents water.
 * 
 * Grid cells are connected horizontally/vertically (not diagonally). The grid is completely 
 * surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
 * 
 * The island doesn't have "lakes" (water inside that isn't connected to the water around the island). 
 * One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 
 * 100. Determine the perimeter of the island.
 * 
 * Example:
 * 
 * Input:
 * [[0,1,0,0],
 *  [1,1,1,0],
 *  [0,1,0,0],
 *  [1,1,0,0]]
 * 
 * Output: 16
 * 
 * Explanation: The perimeter is the 16 yellow stripes in the image below:
 * 
 ******************************************************************************************************/
class Solution {
public:
    int edge(vector<vector<int>> &grid, int x, int y) {
        int edge = 0;
        
        if (x==0 || (x>0 && grid[x-1][y] == 0 ) ) edge++; //up
        if (y==0 || (y>0 && grid[x][y-1] == 0 ) ) edge++; //left
        if (x == grid.size() - 1 || 
            (x < grid.size() - 1 && grid[x+1][y] == 0)) edge++; //down
        if (y == grid[0].size() - 1 || 
            (y < grid[0].size() - 1 && grid[x][y+1] == 0)) edge++; //right
        
        return edge;
    }
            
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    perimeter += edge (grid, i, j);
                }
            }
        }
        return perimeter;
    }
};
