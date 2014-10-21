// Source : https://oj.leetcode.com/problems/surrounded-regions/
// Author : Hao Chen
// Date   : 2014-10-12

/********************************************************************************** 
* 
* Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
* 
* A region is captured by flipping all 'O's into 'X's in that surrounded region.
* 
* For example,
* 
* X X X X
* X O O X
* X X O X
* X O X X
* 
* After running your function, the board should be:
* 
* X X X X
* X X X X
* X X X X
* X O X X
* 
*               
**********************************************************************************/

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void print(vector< vector<char> > &board);


//Runtime Error for 250 x 250 matrix
void markOpen(vector< vector<char> > &board, int row, int col, int r, int c) {

    if (board[r][c] == 'O'){

        board[r][c]='N'; // 'N' means it's not closed

        if (r < row-1) {
            markOpen(board, row, col, r+1, c);
        }
        if (r > 0) {
            markOpen(board, row, col, r-1, c);
        }
        if (c < col-1 ) {
            markOpen(board, row, col, r, c+1); 
        }
        if (c>0) {
            markOpen(board, row, col, r, c-1);
        }
    }
}

//Runtime Error for 250 x 250 matrix
void solve_recursively(vector< vector<char> > &board) {

    if (board.size()<=0 || board[0].size()<=0) return;

    int row = board.size();
    int col = board[0].size();
    //left & right edge
    for (int r=0; r<row; r++){
        if ( board[r][0] == 'O') {
            markOpen(board, row, col, r, 0); 
        }
        if ( board[r][col-1] == 'O') {
            markOpen(board, row, col, r, col-1); 
        }
    }
    //top & bottom edge
    for (int c=1; c<col-1; c++){
        if ( board[0][c] == 'O') {
            markOpen(board, row, col, 0, c); 
        }
        if ( board[row-1][c] == 'O') {
            markOpen(board, row, col, row-1, c); 
        }
    }
    print(board);
    // change 'N' to 'O', change 'O' to 'X'
    for (int r=0; r<row; r++) {
        for (int c=0; c<col; c++) {
            if (board[r][c] == 'O') {
                board[r][c]='X';
            } else if (board[r][c] == 'N') {
                board[r][c]='O';
            }
        }
    }
}


/*change the recursive method to non_recursive way by using queue*/

struct position{
    int row, col;
    void set(int r, int c) { row = r; col = c; }
    position(int r, int c): row(r), col(c) {}
};

void solve_non_recursively(vector< vector<char> > &board) {

    if (board.size()<=0 || board[0].size()<=0) return;

    int row = board.size();
    int col = board[0].size();

    queue<position> q;
    position p(0,0);

    //left & right edge
    for (int r=0; r<row; r++){
        if ( board[r][0] == 'O') {
            board[r][0] = 'N';
            p.set(r, 0);
            q.push(p) ; 
        }
        if ( board[r][col-1] == 'O') {
            board[r][col-1] = 'N';
            p.set(r, col-1);
            q.push(p) ; 
        }
    }
    //top & bottom edge
    for (int c=1; c<col-1; c++){
        if ( board[0][c] == 'O') {
            board[0][c] = 'N';
            p.set(0, c);
            q.push(p) ; 
        }
        if ( board[row-1][c] == 'O') {
            board[row-1][c] = 'N';
            p.set(row-1, c);
            q.push(p) ; 
        }
    }

    while (!q.empty()){
        p = q.front();
        q.pop(); 
        int r = p.row;
        int c = p.col;
        if (r < row-1 && board[r+1][c] == 'O') {
            board[r+1][c] = 'N';
            p.set(r+1, c);
            q.push(p);
        }
        if (r > 0 && board[r-1][c] == 'O') {
            board[r-1][c] = 'N';
            p.set(r-1, c);
            q.push(p);
        }
        if (c < col-1 && board[r][c+1] == 'O') {
            board[r][c+1] = 'N';
            p.set(r, c+1);
            q.push(p);
        }
        if (c>0 && board[r][c-1] == 'O') {
            board[r][c-1] = 'N';
            p.set(r, c-1);
            q.push(p);
        }
    }


    print(board);
    // change 'N' to 'O', change 'O' to 'X'
    for (int r=0; r<row; r++) {
        for (int c=0; c<col; c++) {
            if (board[r][c] == 'O') {
                board[r][c]='X';
            } else if (board[r][c] == 'N') {
                board[r][c]='O';
            }
        }
    }
}

void solve(vector< vector<char> > &board) {
    //Runtime Error for 250 x 250 matrix
    /* solve_recursively(board); */
    solve_non_recursively(board); 
}

void construct(vector< vector<char> > &board, int row, int col) {
    srand(time(0));
    for(int i=0; i<row; i++){
        vector<char> line;
        for(int j=0; j<col; j++){
            if (i==0 || j==0 || i==row-1 || j==col-1) 
                line.push_back(rand()%3 ? 'X' : 'O'); 
            else
                line.push_back(rand()%2 ? 'X' : 'O'); 
        }
        board.push_back(line);
    }
}

void print(vector< vector<char> > &board) {
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(int argc, char** argv )
{
    int row, col;
    row = col = 6;
    if (argc>1){
        row = atoi(argv[1]);
    }
    if (argc>2){
        col = atoi(argv[2]);
    }

    vector< vector<char> > data;

    construct(data, row, col);
    print(data);

    solve(data);
    print(data);

    return 0;
}
