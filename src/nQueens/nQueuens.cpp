// Source : https://oj.leetcode.com/problems/n-queens/
// Author : Hao Chen
// Date   : 2014-08-22

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector< vector<string> > solveNQueens(int n); 
void solveNQueensRecursive(int n, int currentRow, vector<int>& solution, vector< vector<string> >& result); 
bool isValid(int attemptedColumn, int attemptedRow, vector<int> &queenInColumn); 


vector< vector<string> > solveNQueens(int n) {
    vector< vector<string> > result;
    vector<int> solution(n);

    solveNQueensRecursive(n, 0, solution, result);

    return result;    
}


void solveNQueensRecursive(int n, int currentRow, vector<int>& solution, vector< vector<string> >& result) {
    if (currentRow == n){
        vector<string> s;
        for (int i = 0; i < n; i++) {
            string row;
            for (int j = 0; j < n; j++) {
                if ( solution[i]== j ) {
                    row += "Q";
                }else{
                    row += ".";
                }
            }
            s.push_back(row);
        }
        result.push_back(s);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isValid(i, currentRow, solution) ) {
            solution[currentRow] = i;
            solveNQueensRecursive(n, currentRow+1, solution, result);
        }
    } 
}


bool isValid(int attemptedColumn, int attemptedRow, vector<int> &queenInColumn) {

    for(int i=0; i<attemptedRow; i++) {
        if (attemptedColumn == queenInColumn[i]  || 
            abs(attemptedColumn - queenInColumn[i]) == abs(attemptedRow - i)) {
            return false;
        } 
    }
    return true;
}





void printMatrix(vector< vector<string> >& matrix ){
    for (int i = 0; i < matrix.size(); i++) {
        cout << "-----------" << endl;
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << endl;
        }
    }
}


int main(int argc, char** argv)
{
    int n = 8;
    if (argc>1){
        n = atoi(argv[1]);
    }
    
    vector< vector<string> > result = solveNQueens(n);
    printMatrix(result);
    
    return 0;
}

