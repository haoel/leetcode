// Source : https://oj.leetcode.com/problems/word-search/
// Author : Hao Chen
// Date   : 2014-07-19

/********************************************************************************** 
* 
* Given a 2D board and a word, find if the word exists in the grid.
* 
* The word can be constructed from letters of sequentially adjacent cell, 
* where "adjacent" cells are those horizontally or vertically neighboring. 
* The same letter cell may not be used more than once.
* 
* For example,
* Given board = 
* 
* [
*   ["ABCE"],
*   ["SFCS"],
*   ["ADEE"]
* ]
* 
* word = "ABCCED", -> returns true,
* word = "SEE", -> returns true,
* word = "ABCB", -> returns false.
* 
*               
**********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Recursive backtracking algorithm
bool exist(vector<vector<char> > &board, string word, int idx, int row, int col, vector< vector<int> > &mask) {
    int i = row;
    int j = col;
    if (board[i][j] == word[idx] && mask[i][j]==0 ) {
        mask[i][j]=1; //mark the current char is matched
        if (idx+1 == word.size()) return true;
        //checking the next char in `word` through the right, left, up, down four directions in the `board`.
        idx++; 
        if (( i+1<board.size()    && exist(board, word, idx, i+1, j, mask) ) ||
            ( i>0                 && exist(board, word, idx, i-1, j, mask) ) ||
            ( j+1<board[i].size() && exist(board, word, idx, i, j+1, mask) ) ||
            ( j>0                 && exist(board, word, idx, i, j-1, mask) ) )
        {
             return true;
        }
        mask[i][j]=0; //cannot find any successful solution, clear the mark. (backtracking)
    }

    return false;
}

bool exist(vector<vector<char> > &board, string word) {
    if (board.size()<=0 || word.size()<=0) return false;
    int row = board.size();
    int col = board[0].size();
    //using a mask to mark which char has been selected.
    //do not use vector<bool>, it has big performance issue, could cause Time Limit Error
    vector< vector<int> > mask(row, vector<int>(col, 0));

    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[i].size(); j++){
            if ( board[i][j]==word[0] ){
                vector< vector<int> > m = mask;
                if( exist(board, word, 0, i, j, m) ){
                    return true;
                }
            }
        }
    }
    return false;
}

vector< vector<char> > buildBoard(char b[][5], int r, int c) {
    vector< vector<char> > board;
    for (int i=0; i<r; i++){
        vector<char> v(b[i], b[i]+c);
        cout << b[i] << endl;
        board.push_back(v);
    }
    cout << "----------" << endl;    
    return board;
}

int main(int argc, char** argv)
{
    string s;
    char b[3][5] ={ "ABCE", "SFCS", "ADEE" };
    vector< vector<char> > board = buildBoard(b, 3, 4);

    s = "SEE";
    cout << s << ":" << exist(board, s) << endl; 
    
    s = "ABCCED";
    cout << s << ":" << exist(board, s) << endl; 
    
    s = "ABCB";
    cout << s << ":" << exist(board, s) << endl; 


    if (argc>1){
        s = argv[1];
        cout << s << ":" << exist(board, s) << endl; 
    }

    cout << endl << "----------" << endl;    
    char b1[3][5] ={ "CAA", "AAA", "BCD" };
    board = buildBoard(b1, 3, 3);

    s = "AAB";
    cout << s << ":" << exist(board, s) << endl; 


    cout << endl << "----------" << endl;    
    char b2[3][5] ={ "ABCE", "SFES", "ADEE" };
    board = buildBoard(b2, 3, 4);

    s = "ABCESEEEFS";
    cout << s << ":" << exist(board, s) << endl; 

    cout << endl << "----------" << endl;    
    char b3[3][5] ={ "aaaa", "aaaa", "aaaa" };
    board = buildBoard(b3, 3, 4);

    s = "aaaaaaaaaaaaa";
    cout << s << ":" << exist(board, s) << endl; 

    return 0;
}
