// Source : https://oj.leetcode.com/problems/combination-sum/
// Author : Hao Chen
// Date   : 2014-07-19

/********************************************************************************** 
* 
* Given a set of candidate numbers (C) and a target number (T), find all unique combinations 
* in C where the candidate numbers sums to T. 
* 
* The same repeated number may be chosen from C unlimited number of times.
* 
* Note:
* 
* All numbers (including target) will be positive integers.
* Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
* The solution set must not contain duplicate combinations.
* 
* For example, given candidate set 2,3,6,7 and target 7, 
* A solution set is: 
* [7] 
* [2, 2, 3] 
* 
*               
**********************************************************************************/

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
        return;
    }
    for(int i=start; i<candidates.size(); i++){
        //skip duplicates
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
