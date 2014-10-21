// Source : https://oj.leetcode.com/problems/combinations/
// Author : Hao Chen
// Date   : 2014-07-03

/********************************************************************************** 
* 
* Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
* 
* For example,
* If n = 4 and k = 2, a solution is:
* 
* [
*   [2,4],
*   [3,4],
*   [2,3],
*   [1,2],
*   [1,3],
*   [1,4],
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

void getCombination(int n, int k, vector<int>& solution, vector< vector<int> >& result );
vector<vector<int> > combine1(int n, int k); 
vector<vector<int> > combine2(int n, int k);

vector<vector<int> > combine(int n, int k) {
    if (random()%2){
        cout << "recusive method!" << endl;
        return combine1(n, k);
    }
    cout << "non-recusive method!" << endl;
    return combine2(n, k);
}

vector<vector<int> > combine1(int n, int k) {
    vector<vector<int> > result;
    vector<int> solution;
    getCombination(n, k, solution, result);
    return result;
}

void getCombination(int n, int k, vector<int>& solution, vector< vector<int> >& result ){
    if (k==0){
        //sort to meet LeetCode requirement
        vector<int> v = solution;
        sort(v.begin(), v.end());
        result.push_back(v);
        return;
    }
    for(int i=n; i>0; i--){
        solution.push_back(i);
        getCombination(i-1, k-1, solution, result);
        solution.pop_back();
    }
}

vector<vector<int> > combine2(int n, int k) {
    
    vector<vector<int> > result;
    vector<int> d;
    for (int i=0; i<n; i++){
        d.push_back( (i<k) ? 1 : 0 );
    }

    //1) from the left, find the [1,0] pattern, change it to [0,1]
    //2) move all of the 1 before the pattern to the most left side
    //3) check all of 1 move to the right
    while(1){
        vector<int> v;
        for(int x=0; x<n; x++){
            if (d[x]) v.push_back(x+1);
        }
        result.push_back(v);
        //step 1), find [1,0] pattern
        int i;
        bool found = false;
        int ones =0;
        for(i=0; i<n-1; i++){
            
            if (d[i]==1 && d[i+1]==0){
                d[i]=0; d[i+1]=1;
                found = true;
                //step 2) move all of right 1 to the most left side
                for (int j=0; j<i; j++){
                    d[j]=( ones > 0 ) ? 1 : 0;
                    ones--;
                }
                break; 
            } 
            if (d[i]==1) ones++;
        }
        if (!found){
            break;
        }
        
    }
    return result;
    
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

int main(int argc, char** argv)
{
    srand(time(NULL));

    int n = 4, k =2;
    if (argc>2){
        n = atoi(argv[1]);
        k = atoi(argv[2]);
    }
    vector<vector<int> > r = combine(n, k);
    printResult(r);
}
