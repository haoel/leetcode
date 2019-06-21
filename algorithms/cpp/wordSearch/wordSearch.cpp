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

bool exist(vector<vector<char> > &board, string& word, int idx, int row, int col) {
    if ( row<0 || row>=board.size() ||
            col<0 || col>=board[0].size() ||
            board[row][col] != word[idx]) {
        return false;
    }


    if (idx+1 == word.size()) return true;

    //replace to a special char to avoid duplication.
    board[row][col] = '\0';

    if ( exist(board, word, idx+1, row+1, col ) ||
            exist(board, word, idx+1, row-1, col ) ||
            exist(board, word, idx+1, row, col+1 ) ||
            exist(board, word, idx+1, row, col-1 ) ) {
        return true;
    }

    //restore the char
    board[row][col] = word[idx];

    return false;
}

bool exist(vector<vector<char> > &board, string word) {
    if (board.size()<=0 || word.size()<=0) return false;
    int row = board.size();
    int col = board[0].size();

    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[i].size(); j++){
            if ( board[i][j]==word[0]  ){
                if( exist(board, word, 0, i, j) ){
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
