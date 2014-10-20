// Source : https://oj.leetcode.com/problems/combination-sum/
// Author : Hao Chen
// Date   : 2014-07-19

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void combinationSumHelper(vector<int> &candidates, int start, int target, vector<int> &solution, vector< vector<int> > &result) {
    if (target<0){
        return;
    }
    if (target==0){
        result.push_back(solution);
    }
    for(int i=start; i<candidates.size(); i++){
        //remote duplicates
        if (i>start && candidates[i] == candidates[i-1]) {
            continue;
        }
        solution.push_back(candidates[i]);
        combinationSumHelper(candidates, i, target - candidates[i], solution, result);
        solution.pop_back();
    }
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    vector< vector<int> > result;
    if (candidates.size()<=0){
        return result;
    }
    sort(candidates.begin(), candidates.end());
    
    vector<int> solution;
    combinationSumHelper(candidates, 0, target, solution, result);

    return result;
}

void printMatrix(vector< vector<int> > &vv)
{
    for(int i=0; i<vv.size(); i++) {
        cout << "[";
        for(int j=0; j<vv[i].size(); j++) {
            cout << " " << vv[i][j];
        }
        cout << "]" << endl;;
    }
}

void printArray(vector<int> &v)
{
    cout << "{";
    for(int i=0; i<v.size(); i++) {
        cout << " " << v[i];
    }
    cout << "}" << endl;
}


int main(int argc, char** argv)
{
    int a[] = {4,2,3,3,5,7};
    vector<int> v(a, a+sizeof(a)/sizeof(int));
    int target = 7;
    cout << "array  = ";
    printArray(v);
    cout << "target = " << target << endl;
    
    vector< vector<int> > vv = combinationSum(v, target);
    printMatrix(vv);

    return 0;
}
