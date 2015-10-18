// Source : https://oj.leetcode.com/problems/combination-sum-ii/
// Author : Hao Chen
// Date   : 2014-07-19

/********************************************************************************** 
* 
* Given a collection of candidate numbers (C) and a target number (T), find all 
* unique combinations in C where the candidate numbers sums to T.
* 
* Each number in C may only be used once in the combination.
* 
* Note:
* 
* > All numbers (including target) will be positive integers.
* > Elements in a combination (a1, a2, … , ak) must be in non-descending order. 
*   (ie, a1 ≤ a2 ≤ … ≤ ak).
* > The solution set must not contain duplicate combinations.
* 
* For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
* A solution set is: 
* [1, 7] 
* [1, 2, 5] 
* [2, 6] 
* [1, 1, 6] 
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
        int n = candidates[i];
        if (i>start && candidates[i] == candidates[i-1]) {
            continue;
        }
        solution.push_back(n);
        combinationSumHelper(candidates, i+1, target - n, solution, result);
        solution.pop_back();
    }
}

vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
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

void test(int a[], int len, int target)
{
    vector<int> v(a, a+len);
    cout << "array  = ";
    printArray(v);
    cout << "target = " << target << endl;

    vector< vector<int> > vv = combinationSum2(v, target);
    printMatrix(vv);
}

int main(int argc, char** argv)
{
    #define TEST(a, t) test(a, sizeof(a)/sizeof(int), target)
    int a[] = {4,2,3,3,5,7};
    int target = 7;
    TEST(a, target);

    int b[] = {10,1,2,7,6,1,5};
    target = 8;
    TEST(b, target);

    int c[] = {2,2,2};
    target = 2;
    TEST(c, target);

    return 0;
}
