// Source : https://oj.leetcode.com/problems/3sum-closest/
// Author : Hao Chen
// Date   : 2014-07-03

/********************************************************************************** 
* 
* Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
* 
*     For example, given array S = {-1 2 1 -4}, and target = 1.
* 
*     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
* 
*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define INT_MAX 2147483647
//solution:  http://en.wikipedia.org/wiki/3SUM
int threeSumClosest(vector<int> &num, int target) {


    sort(num.begin(), num.end());

    int n = num.size();
    int distance = INT_MAX; 
    int result;

    for (int i=0; i<n-2; i++) {
        //skip the duplication
        if (i>0 && num[i-1]==num[i]) continue;
        int a = num[i];
        int low = i+1;
        int high = n-1;
        while ( low < high ) {
            int b = num[low];
            int c = num[high];
            int sum = a+b+c;
            if (sum - target == 0) {
                //got the final soultion
                return target;
            } else if (sum -target> 0) {
                if (abs(sum-target) < distance ) {
                    distance = abs(sum - target); 
                    result = sum;
                }
                //skip the duplication
                while(high>0 && num[high]==num[high-1]) high--;
                high--;
            } else{
                if (abs(sum-target) < distance) {
                    distance = abs(sum - target); 
                    result = sum;
                }
                //skip the duplication
                while(low<n && num[low]==num[low+1]) low++;
                low++;
            } 
        }
    }
    return result;

}




int main()
{
    int a[] = {-1, 2, 1, -4};
    vector<int> n(a, a+sizeof(a)/sizeof(int));
    int target = 1;
    cout << threeSumClosest(n, target) << endl;
    return 0;
}
