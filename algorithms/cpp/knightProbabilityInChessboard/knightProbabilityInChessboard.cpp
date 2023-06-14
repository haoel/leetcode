// Source : https://leetcode.com/problems/knight-probability-in-chessboard/
// Author : Sunny Lin
// Date   : 2023-06-12

/***************************************************************************************************** 
 *
 *On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).
 *
 *A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.
 *
 *
 *Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.
 *
 *The knight continues moving until it has made exactly k moves or has moved off the chessboard.
 *
 *Return the probability that the knight remains on the board after it has stopped moving.
 * 
 ******************************************************************************************************/
#include <vector>
using namespace std;

class Solution {
    public:

        double Probability(int n, int i, int current_row, int current_column, vector<pair<int, int>>& directions, vector<vector<vector<double>>>& dp){
            if(current_row < 0 or current_row >= n or current_column < 0 or current_column >= n){
                return 0.0;
            }
            if (i == 0) return 1.0; 
            if (dp[i][current_row][current_column]!= NULL) return dp[i][current_row][current_column];

            for(auto& direction: directions){
                dp[i][current_row][current_column] += Probability(n, i-1, current_row + direction.first, current_column + direction.second, directions, dp)/8.0;
            }
            return dp[i][current_row][current_column];
        }

        double knightProbability(int n, int k, int row, int column) {
            vector<vector<vector<double>>>dp(k+1, vector<vector<double>>(n, vector<double>(n, NULL)));
            vector<pair<int, int>>directions{{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {1, -2}, {2, -1}, {-2, -1}, {-1, -2}};
            return Probability(n, k, row, column, directions, dp);
        }
};
