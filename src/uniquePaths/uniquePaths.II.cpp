// Source : https://oj.leetcode.com/problems/unique-paths-ii/
// Author : Hao Chen
// Date   : 2014-06-25

#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    vector< vector<int> > v = obstacleGrid;
    unsigned int max=0;
    for (int i=0; i<obstacleGrid.size(); i++){
        for (int j=0; j<obstacleGrid[i].size(); j++){
            if(obstacleGrid[i][j] == 1){
                max = v[i][j] = 0;
            } else {
                if (i>0 && j>0) {
                    max= v[i][j] = v[i-1][j] + v[i][j-1];
                }else if(i>0){
                    max = v[i][j] = v[i-1][j];
                }else if(j>0){
                    max = v[i][j] = v[i][j-1];
                }else{
                    max = v[i][j] = 1 ;
                }
            }
        }
    }
    return max;
}


