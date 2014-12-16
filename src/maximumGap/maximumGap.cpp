// Source : https://oj.leetcode.com/problems/maximum-gap/
// Author : Hao Chen
// Date   : 2014-12-17

/********************************************************************************** 
 * 
 * Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
 * 
 * Try to solve it in linear time/space.
 * 
 * Return 0 if the array contains less than 2 elements.
 * 
 * You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
 * 
 * Credits:Special thanks to @porker2008 for adding this problem and creating all test cases.
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int maximumGap(vector<int> &num) {

    if (num.size() < 2) return 0;

    //find the max & min element
    int min=num[0], max=num[0];
    for(int i=1; i<num.size(); i++){
        min = min > num[i] ? num[i] : min;
        max = max < num[i] ? num[i] : max;
    }

    //Divide the interval [min, max] into n "buckets" of equal size = (max -min)/n
    int bucket_size = (max - min)/num.size() + 1;

    //For each of the remaining n-2 numbers, determin in which bucket it falls .
    //The number num[i] belongs to the kth bucket B[k] if and only if (num[i]-min)/m = k-1

    vector< vector<int> > buckets ( (max-min)/bucket_size + 1);
    //For each bucket B[k], compute its max & min among the numbers which falls in B[k].
    //if the bucket is empty, remain it nothing.
    //if the bucket has one number, make this number as both max & min 
    for(int i=0; i<num.size(); i++){
        int idx = (num[i] - min) / bucket_size ;
        if (buckets[idx].empty()){
            buckets[idx].push_back(num[i]);
            buckets[idx].push_back(num[i]);
        }else{
            buckets[idx][0] = buckets[idx][0] > num[i] ? num[i] : buckets[idx][0];
            buckets[idx][1] = buckets[idx][1] < num[i] ? num[i] : buckets[idx][1];
        }
    }

    //calculate the max gap
    int maxGap = 0;
    int prev = 0;
    for (int i = 1; i < buckets.size(); i++) {
        if (buckets[i].empty()) continue;
        int gap = buckets[i][0] - buckets[prev][1];
        maxGap = maxGap > gap ? maxGap : gap;
        prev = i;
    }
    return maxGap;
}

int main()
{
    //int a[] = {3, 6, 19, 1};
    int a[] = {1,1,1,1,1,5,5,5,5,5};
    vector<int> num(a, a+sizeof(a)/sizeof(a[0]));
    cout << maximumGap(num) << endl;

    return 0;
}
