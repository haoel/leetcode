// Source : https://oj.leetcode.com/problems/permutation-sequence/
// Author : Hao Chen
// Date   : 2014-08-22

/********************************************************************************** 
* 
* The set [1,2,3,…,n] contains a total of n! unique permutations.
* 
* By listing and labeling all of the permutations in order,
* We get the following sequence (ie, for n = 3):
* 
* "123"
* "132"
* "213"
* "231"
* "312"
* "321"
* 
* Given n and k, return the kth permutation sequence.
* 
* Note: Given n will be between 1 and 9 inclusive.
*               
**********************************************************************************/

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


/*
"123"
"132"
"213"
"231"
"312"
"321"
*/

void nextPermutation(vector<int>& num); 

/* Extreamly Optimized */
string getPermutation(int n, int k) {
    vector<int> num;
    int total = 1;
    for(int i=1; i<=n; i++){
        num.push_back(i);
        total *= i;
    }

    //invalid k;
    if( total < k ) {
        return "";
    }

    // Construct the k-th permutation with a list of n numbers
    // Idea: group all permutations according to their first number (so n groups, each of
    // (n-1)! numbers), find the group where the k-th permutation belongs, remove the common
    // first number from the list and append it to the resulting string, and iteratively
    // construct the (((k-1)%(n-1)!)+1)-th permutation with the remaining n-1 numbers
    int group = total;
    stringstream ss;
    while (n>0) {
        group = group / n;
        int idx = (k-1) / group;
        ss << num[idx];
        num.erase(num.begin()+idx);
        n--;
        //the next k also can be caculated like this: 
        //    k = (k-1)%group + 1; 
        k -= group * idx;
    }

    return ss.str();
}



/* Optimization by determining the group */
string getPermutation_0(int n, int k) {
    vector<int> num;
    int total = 1;
    for(int i=1; i<=n; i++){
        num.push_back(i);
        total *= i;
    }

    //invalid k;
    if( total < k ) {
        return "";
    }
    int group = total / n;
    int idx = (k-1) / group;
    int nn = num[idx];
    num.erase(num.begin()+idx);
    num.insert(num.begin(), nn);

    int offset = (k-1) % group;
    for(int i=0; i<offset; i++) {
        nextPermutation(num);
    }

    //string result;
    stringstream ss;
    for(int i=0; i<n; i++){
        ss << num[i];
    }

    return ss.str();
}

/* Time Limit Exceeded */
string getPermutation_1(int n, int k) {
    vector<int> num;
    for(int i=1; i<=n; i++){
        num.push_back(i);
    }

    for(int i=1; i<k; i++) {
        nextPermutation(num);
    }

    //string result;
    stringstream ss;
    for(int i=0; i<n; i++){
        ss << num[i];
    }

    return ss.str();
}



void nextPermutation(vector<int>& num) {
    if (num.size()<=1) return;
    for (int i=num.size()-1; i>0; i-- ) {
        if (num[i-1] < num[i]) {
            int j = num.size() - 1;
            while( num[i-1] > num[j] ) {
                j--;
            }
            int temp = num[i-1];
            num[i-1] = num[j];
            num[j] = temp;

            reverse(num.begin()+i, num.end());
            return;
        }
    }

    reverse( num.begin(), num.end() );
}


int main(int argc, char**argv)
{
    int n=3, k=6;
    if ( argc > 2 ) {
        n = atoi(argv[1]);
        k = atoi(argv[2]);
    }
    cout << "n = " << n << ", k = " << k << " : " << getPermutation(n, k) << endl;

    return 0;
}
