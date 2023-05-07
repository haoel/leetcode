// Source : https://leetcode.com/problems/number-of-islands/
// Author : Hao Chen
// Date   : 2015-06-08

/********************************************************************************** 
 * 
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
 * An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
 * You may assume all four edges of the grid are all surrounded by water.
 * 
 * Example 1:
 *   11110
 *   11010
 *   11000
 *   00000
 * Answer: 1
 * 
 * Example 2:
 *   11000
 *   11000
 *   00100
 *   00011
 * Answer: 3
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <array>
using namespace std;


void dfs(vector<vector<char> >& grid, int row, int col, int row_boarder, int col_boarder){
    
    if (row < 0 
    || col < 0 
    || row >= row_boarder 
    || col >= col_boarder 
    || grid[row][col]=='0') return;
    grid[row][col] = '0';
    

    dfs(grid, row + 1, col, row_boarder, col_boarder);
    dfs(grid, row, col + 1, row_boarder, col_boarder);
    dfs(grid, row, col - 1, row_boarder, col_boarder);
    dfs(grid, row -1, col, row_boarder, col_boarder);
}

int numIslands(vector<vector<char> >& grid) {
    if (grid.size()== 0) return 0;
    int count = 0;
    int row_boarder = grid.size();
    int col_boarder = grid[0].size();
    for (int row = 0; row < grid.size(); row++){
        for (int col = 0; col < grid[0].size(); col++){
            if (grid[row][col] == '1'){
                count++;
                dfs(grid, row, col, row_boarder, col_boarder);
            }
        }
    }
    return count;

}



void initGrid( string g[], int len, vector<vector<char> >& grid )
{
    for (int i=0; i<len; i++){
       grid.push_back(vector<char>(g[i].begin(), g[i].end())); 
    }
}

int main(void)
{
    vector< vector<char> > grid;
    grid.push_back( vector<char>(1, '1') );

    cout << numIslands(grid) << endl;


    grid.clear();

    string g1[] = { "11110",
                    "11010", 
                    "11000", 
                    "00000" };

    initGrid(g1, 4, grid);
    cout << numIslands(grid) << endl;



    grid.clear();

    string g2[] = { "11000",
                    "11000",
                    "00100",
                    "00011" };

    initGrid(g2, 4, grid);
    cout << numIslands(grid) << endl;


    return 0;
}
