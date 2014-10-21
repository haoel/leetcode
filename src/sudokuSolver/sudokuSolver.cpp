// Source : https://oj.leetcode.com/problems/sudoku-solver/
// Author : Hao Chen
// Date   : 2014-09-20

/********************************************************************************** 
* 
* Write a program to solve a Sudoku puzzle by filling the empty cells.
* 
* Empty cells are indicated by the character '.'.
* 
* You may assume that there will be only one unique solution.
* 
* A sudoku puzzle...
* 
* ...and its solution numbers marked in red.
* 
*               
**********************************************************************************/

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <vector>
using namespace std;


const int SodukuSize = 9;
bool row_mask[SodukuSize][SodukuSize];
bool col_mask[SodukuSize][SodukuSize];
bool area_mask[SodukuSize][SodukuSize];

bool initSudokuMask(vector< vector<char> > &board){
    //reset the memory
    memset(row_mask, false, sizeof(row_mask));
    memset(col_mask, false, sizeof(col_mask));
    memset(area_mask, false, sizeof(area_mask));

    //check each rows and cols
    for(int r=0; r<board.size(); r++){
        for (int c=0; c<board[r].size(); c++){
            if (!isdigit(board[r][c])) {
                continue;
            };
            int idx =  board[r][c] - '0' - 1;

            //check the rows/cols/areas
            int area = (r/3) * 3 + (c/3);
            if (row_mask[r][idx] || col_mask[c][idx] || area_mask[area][idx] ){
                return false;
            }
            row_mask[r][idx] = col_mask[c][idx] = area_mask[area][idx] = true;
        }
    }
    return true;

}


bool recursiveSudoKu(vector< vector<char> > &board, int row, int col){

    if (row >= SodukuSize) {
        return true;
    }

    if (col >= SodukuSize){
        return recursiveSudoKu(board, row+1, 0);
    }
    
    if (board[row][col] != '.'){
        return recursiveSudoKu(board, row, col+1);    
    }
    //pick a number for empty cell
    int area;
    for(int i=0; i<SodukuSize; i++){
        area = (row/3) * 3 + (col/3);
        if (row_mask[row][i] || col_mask[col][i] || area_mask[area][i] ){
            continue;
        }
        //set the number and sovle it recursively
        board[row][col] = i + '1';
        row_mask[row][i] = col_mask[col][i] = area_mask[area][i] = true;
        if (recursiveSudoKu(board, row, col+1) == true){
            return true;
        }
        //backtrace
        board[row][col] = '.';
        row_mask[row][i] = col_mask[col][i] = area_mask[area][i] = false;
         
    }
    return false;
}


void solveSudoku(vector<vector<char> > &board) {
    if (initSudokuMask(board) == false){
        return;
    }
    recursiveSudoKu(board, 0, 0); 
}


int main(int argc, char**argv) {
    return 0;
}
