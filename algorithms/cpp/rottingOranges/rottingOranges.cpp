// Source : https://leetcode.com/problems/rotting-oranges/
// Author : David Lin
// Date   : 2023-05-18

/********************************************************************************** 
 * 
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
 * 
 * Example 1:
 *   211
 *   110
 *   011
 * Answer: 4
 * 
 * Example 2:
 *   211
 *   011
 *   101
 * Answer: -1
 * 
 * Example 3:
 *   02
 * Answer: 0
 * 
 * 
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


int orangesRotting(vector<vector<int> >& grid) {
    int minutes{};
    int num_fresh{};
    queue<pair<int, int>> q;
    int row_size = grid.size();
    int col_size = grid[0].size();
    for(int row{}; row < row_size; row++){
        for(int col{}; col< col_size; col++){
            switch (grid[row][col])
            {
            case 2:
                q.push({row, col});
                break;
            case 1:
                num_fresh++;
                break;
            default:
                break;
            }            
        }
    }
    
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int q_size = q.size();
    if (q_size == 0){
        if (num_fresh == 0)return 0;
        return -1;
    } 

    while (!q.empty())
    {   
        if(q_size == 0 && q.size() > 0){
            minutes++;
            q_size = q.size();
        }
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(auto& direction: directions){
            int new_row = row + direction.first;
            int new_col = col + direction.second;
            if(new_row < row_size && new_row >= 0 && new_col < col_size && new_col >= 0){
                if(grid[new_row][new_col] == 1){
                    grid[new_row][new_col] = 2;
                    q.push({new_row, new_col});
                    num_fresh--;
            }
            }
        }
        q_size--;
    }
    if(num_fresh > 0)return -1;
    return minutes;
}


int main(void)
{
    vector< vector<int> > grid;
    grid.push_back( vector<int>(1, 0) );
    cout << orangesRotting(grid) << endl;
    grid.clear();

    grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout << orangesRotting(grid) << endl;
    grid.clear();

    grid = {{2,1,1},{0,1,1},{1,0,1}};
    cout << orangesRotting(grid) << endl;
    grid.clear();

    grid = {{0,2}};
    cout << orangesRotting(grid) << endl;
    return 0;
}
