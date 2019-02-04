// Source : https://leetcode.com/problems/unique-paths-iii/
// Author : Hao Chen
// Date   : 2019-02-03

/***************************************************************************************************** 
 *
 * On a 2-dimensional grid, there are 4 types of squares:
 * 
 * 	1 represents the starting square.  There is exactly one starting square.
 * 	2 represents the ending square.  There is exactly one ending square.
 * 	0 represents empty squares we can walk over.
 * 	-1 represents obstacles that we cannot walk over.
 * 
 * Return the number of 4-directional walks from the starting square to the ending square, that walk 
 * over every non-obstacle square exactly once.
 * 
 * Example 1:
 * 
 * Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
 * Output: 2
 * Explanation: We have the following two paths: 
 * 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
 * 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
 * 
 * Example 2:
 * 
 * Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
 * Output: 4
 * Explanation: We have the following four paths: 
 * 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
 * 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
 * 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
 * 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
 * 
 * Example 3:
 * 
 * Input: [[0,1],[2,0]]
 * Output: 0
 * Explanation: 
 * There is no path that walks over every empty square exactly once.
 * Note that the starting and ending square can be anywhere in the grid.
 * 
 * Note:
 * 
 * 	1 <= grid.length * grid[0].length <= 20
 * 
 ******************************************************************************************************/
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int path = 0;
        int startX, startY;
	if (!findStartPoint( grid, startX, startY)) return 0;
        uniquePathsHelper(grid, startX, startY, path);
        return path;
    }
    
    bool findStartPoint(vector<vector<int>> &grid, int& x, int& y) {
         for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    x = i; y =j;
                    return true;
                }
            }
         }
        return false;
    }
    bool check(vector<vector<int>> &grid ) {
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if (grid[i][j]  == 0 ) return false;
            }
        }
        return true;
    }
    
    
    void uniquePathsHelper(vector<vector<int>> &grid, int x, int y, int& path ) {
        
        if (x < 0 || y < 0 || x>= grid.size() || y>=grid[0].size()) return;
        
        if ( grid[x][y] < 0)  return;
 
        if ( grid[x][y] == 2) {  
            if (check(grid)) path++;
            return;
        }
        
        //back tracing - mark -2 means already passed.
        grid[x][y] = -2;
        uniquePathsHelper(grid, x, y-1, path); // up
        uniquePathsHelper(grid, x, y+1, path); // down
        uniquePathsHelper(grid, x+1, y, path); // right
        uniquePathsHelper(grid, x-1, y, path); // left
        grid[x][y] = 0;
    
    }
};
