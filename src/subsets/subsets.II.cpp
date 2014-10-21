// Source : https://oj.leetcode.com/problems/subsets-ii/
// Author : Hao Chen
// Date   : 2014-07-05

/********************************************************************************** 
* 
* Given a collection of integers that might contain duplicates, S, return all possible subsets.
* 
* Note:
* 
* Elements in a subset must be in non-descending order.
* The solution set must not contain duplicate subsets.
* 
* For example,
* If S = [1,2,2], a solution is:
* 
* [
*   [2],
*   [1],
*   [1,2,2],
*   [2,2],
*   [1,2],
*   []
* ]
* 
*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getCombination(vector<int>& v, int n, int k, vector<int>& solution, vector< vector<int> >& result );
vector<vector<int> > combine(vector<int>& v, int k); 
vector<vector<int> > combine1(vector<int>& v, int k); 
vector<vector<int> > combine2(vector<int>& v, int k);

vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int> > result;
    sort(S.begin(), S.end());
    for(int i=0; i<=S.size(); i++){
        vector<vector<int> > r = combine(S, i); 
        result.insert(result.end(), r.begin(), r.end()); 
    } 
    return result;
}


vector<vector<int> > combine(vector<int> &v, int k) {
    vector<vector<int> > result;
    vector<int> solution;
    getCombination(v, v.size(), k, solution, result);
    return result;
}

void getCombination(vector<int> &v, int n, int k, vector<int>& solution, vector< vector<int> >& result ){
    if (k==0){
        //sort to meet LeetCode requirement
        vector<int> v = solution;
        sort(v.begin(), v.end());
        result.push_back(v);
        return;
    }
    for(int i=n; i>0; i--){
        solution.push_back(v[i-1]);
        getCombination(v, i-1, k-1, solution, result);
        solution.pop_back();
        //skip the duplication
        while (i>1 && v[i-1]==v[i-2]) i--;
   }
}


void printResult(vector<vector<int> >& result)
{
    for(int i=0; i<result.size(); i++){
        cout << "{";
        for(int j=0; j<result[i].size(); j++){
            cout << " " << result[i][j];
        }
        cout << " }" <<endl;
    }
}

void printArray(vector<int>& v){
    cout << "{";
    for(int i=0; i<v.size(); i++) {
        cout << " " << v[i];
    }
    cout << " }" << endl;
}

int main(int argc, char** argv)
{
    srand(time(NULL));

    int n = 3;
    if (argc>1){
        n = atoi(argv[1]);
    }
    vector<int> v;
    for(int i=n; i>0; i--){
        v.push_back(random()%n+1);
    }
    printArray(v);
    cout << "--------------------" <<endl;
    vector<vector<int> > r = subsets(v);
    printResult(r);
    cout << "====================" <<endl;

    int a[] = {1, 4, 4, 4, 4,};
    v.clear();
    v.insert(v.begin(), a, a+5);
    printArray(v);
    cout << "--------------------" <<endl;
    r = subsets(v);
    printResult(r);
    cout << "====================" <<endl;
}
