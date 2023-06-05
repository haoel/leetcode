// Source : https://leetcode.com/problems/walls-and-gates/
// Author : Sunny Lin
// Date   : 2023-05-20

/********************************************************************************** 
 * 
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
 * 
For example, given the 2D grid:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
 * 
 * 
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define INF 2147483647

using namespace std;


void dfs(vector<vector<int>>& grid, int row, int col, vector<pair<int, int>>& directions, int current_steps){

    if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || current_steps > grid[row][col] ) return;

    grid[row][col] = current_steps;

    for(auto& direction: directions){
        dfs(grid, row + direction.first, col + direction.second, directions, current_steps+1);
    }
}

vector<vector<int>>& wallAndGates(vector<vector<int>>& grid) {
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
 
    for(int row{}; row < grid.size(); row++){
        for(int col{}; col < grid[0].size(); col++){
            if(grid[row][col] == 0){
                dfs(grid, row, col, directions, 0);
            }
        }
    }
    return grid;

}

int printMatrix(vector< vector<int> > &vv)
{
    for(int i=0; i<vv.size(); i++) {
        cout << "[";
        for(int j=0; j<vv[i].size(); j++) {
            cout << " " << vv[i][j];
        }
        cout << "]" << endl;;
    }
}

int main(void)
{
    vector< vector<int> > grid;
    grid = {{INF, -1, 0, INF},
            {INF, INF, INF, -1},
            {INF, -1, INF, -1},
            {0, -1, INF, INF}};
    printMatrix(wallAndGates(grid));

    return 0;
}
