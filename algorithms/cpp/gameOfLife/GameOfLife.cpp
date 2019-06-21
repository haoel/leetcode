// Source : https://leetcode.com/problems/game-of-life/
// Author : Hao Chen
// Date   : 2019-03-20

/***************************************************************************************************** 
 *
 * According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular 
 * automaton devised by the British mathematician John Horton Conway in 1970."
 * 
 * Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell 
 * interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules 
 * (taken from the above Wikipedia article):
 * 
 * 	Any live cell with fewer than two live neighbors dies, as if caused by under-population.
 * 	Any live cell with two or three live neighbors lives on to the next generation.
 * 	Any live cell with more than three live neighbors dies, as if by over-population..
 * 	Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
 * 
 * Write a function to compute the next state (after one update) of the board given its current state. 
 * The next state is created by applying the above rules simultaneously to every cell in the current 
 * state, where births and deaths occur simultaneously.
 * 
 * Example:
 * 
 * Input: 
 * [
 *   [0,1,0],
 *   [0,0,1],
 *   [1,1,1],
 *   [0,0,0]
 * ]
 * Output: 
 * [
 *   [0,0,0],
 *   [1,0,1],
 *   [0,1,1],
 *   [0,1,0]
 * ]
 * 
 * Follow up:
 * 
 * 	Could you solve it in-place? Remember that the board needs to be updated at the same time: 
 * You cannot update some cells first and then use their updated values to update other cells.
 * 	In this question, we represent the board using a 2D array. In principle, the board is 
 * infinite, which would cause problems when the active area encroaches the border of the array. How 
 * would you address these problems?
 * 
 ******************************************************************************************************/


class Solution {
public:
    // the problem here is we need store two states in one cell,
    // one is the original state, another is the new state
    // So, we could store the state into the bit.
    //  - Old State: the first  bit from the right
    //  - New State: the second bit from the right
    void liveCheck(vector<vector<int>>& board, int r, int c) {
        int cnt = 0;
        for (int i=r-1; i<=r+1; i++) {
            if (i < 0 || i>=board.size()) continue;
            for (int j=c-1; j<=c+1; j++) {
                if (j<0 || j>=board[0].size() || (i==r && j==c)) continue;
                if ( board[i][j] & 1 ) cnt++;
            }
        }

        //live -> die
        //if (board[r][c]==1 && (cnt < 2 || cnt > 3)) board[r][c] = 1;

        //live -> live
        if ( board[r][c] == 1 && (cnt == 2 || cnt == 3) ) board[r][c] = 3;

        //die -> live
        if ( board[r][c] == 0 && cnt == 3 ) board[r][c] = 2;

    }

    void gameOfLife(vector<vector<int>>& board) {
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                liveCheck(board, i, j);
            }
        }

        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                board[i][j] >>= 1;
            }

        }

    }
};
