// Source : https://oj.leetcode.com/problems/4sum/
// Author : Hao Chen
// Date   : 2014-07-03

/********************************************************************************** 
* 
* Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
* Find all unique quadruplets in the array which gives the sum of target.
* 
* Note:
* 
* Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
* The solution set must not contain duplicate quadruplets.
* 
*     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
* 
*     A solution set is:
*     (-1,  0, 0, 1)
*     (-2, -1, 1, 2)
*     (-2,  0, 0, 2)
* 
*               
**********************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > threeSum(vector<int> num, int target); 

/*
 * 1) Sort the array,
 * 2) traverse the array, and solve the problem by using "3Sum" soultion.
 */

vector<vector<int> > fourSum(vector<int> &num, int target) {
    vector< vector<int> > result;
    if (num.size()<4) return result;
    sort( num.begin(), num.end() );
    
    for(int i=0; i<num.size()-3; i++) {
        //skip the duplication
        if (i>0 && num[i-1]==num[i]) continue;
        vector<int> n(num.begin()+i+1, num.end());
        vector<vector<int> > ret = threeSum(n, target-num[i]);
        for(int j=0; j<ret.size(); j++){
            ret[j].insert(ret[j].begin(), num[i]);
            result.push_back(ret[j]);
        }
    }

    return result; 
}

vector<vector<int> > threeSum(vector<int> num, int target) {

    vector< vector<int> > result;
    //sort the array (if the qrray is sorted already, it won't waste any time)
    sort(num.begin(), num.end());

    int n = num.size();

    for (int i=0; i<n-2; i++) {
        //skip the duplication
        if (i>0 && num[i-1]==num[i]) continue;
        int a = num[i];
        int low = i+1;
        int high = n-1;
        while ( low < high ) {
            int b = num[low];
            int c = num[high];
            if (a+b+c == target) {
                //got the soultion
                vector<int> v;
                v.push_back(a);
                v.push_back(b);
                v.push_back(c);
                result.push_back(v);
                // Continue search for all triplet combinations summing to zero.
                //skip the duplication
                while(low<n && num[low]==num[low+1]) low++;
                while(high>0 && num[high]==num[high-1]) high--;
                low++;
                high--;
            } else if (a+b+c > target) {
                //skip the duplication
                while(high>0 && num[high]==num[high-1]) high--;
                high--;
            } else{
                //skip the duplication
                while(low<n && num[low]==num[low+1]) low++;
                low++;
            }
        }
    }
    return result;
}


int printMatrix(vector< vector<int> > &vv)
{
    for(int i=0; i<vv.size(); i++) {
        cout << "[";
        for(int j=0; j<vv[i].size(); j++) {
            cout << " " << vv[i][j];
        }
        cout << "]" << endl;;
    }
}


int main()
{
    int a[] = {1,0,-1,0,-2,2};
    vector<int> n(a, a+6);
    int t = 0;
    vector< vector<int> > v = fourSum(n, t);
    printMatrix(v);

    n.clear();
    int b[] = {-1,-5,-5,-3,2,5,0,4};
    n.insert(n.begin(), b, b+8);
    t = -7;
    v = fourSum(n, t);
    printMatrix(v);

    return 0;
}
