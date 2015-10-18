// Source : https://oj.leetcode.com/problems/missing-ranges/
// Author : Hao Chen
// Date   : 2014-12-11

/********************************************************************************** 
 * 
 * Given a sorted integer array where the range of elements are [lower, upper] inclusive, 
 * return its missing ranges.
 *
 * For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, 
 * return ["2", "4->49", "51->74", "76->99"]. 
 * 
 **********************************************************************************/

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;


string& makeRange(int lo, int hi){
    static string result;
    result="";
    stringstream ss;
    if (lo != hi){
        ss << lo << "->" << hi;
    }else{
        ss << lo;
    }
    ss >> result;
    return result;
}


vector<string> findMissingRanges(int A[], int n, int lower, int upper) {

    vector<string> result;

    if ( n<=0 ) {
        result.push_back(makeRange(lower, upper));
        return result;
    }

    if (lower < A[0]){
        result.push_back(makeRange(lower, A[0]-1 < upper ? A[0]-1 : upper));
    }

    for(int i=0; i<n-1; i++){
        if ( A[i] + 1 == A[i+1] ) {
            continue;
        }
        result.push_back(makeRange(A[i]+1, A[i+1]-1));
    }

    if (upper > A[n-1]){
        result.push_back(makeRange(A[n-1]+1, upper));
    }

    return result;
}


void printVector(vector<string> v){
    cout << "[";
    int i=0;
    for(; i<v.size(); i++){
        cout << "\"" << v[i] << "\"" << (i==v.size()-1 ? "":", " );
    }
    cout << "]" <<endl;
}


vector<int> string2Array(string s){


    vector<string> strarr;
    istringstream iss(s);
    copy(istream_iterator<string>(iss),
            istream_iterator<string>(),
            back_inserter(strarr));

    vector<int> result;
    for (int i=0; i<strarr.size(); i++){
        result.push_back(atoi(strarr[i].c_str()));
    }

    return result;
}

int main(int argc, char**argv)
{
    int A[] = {0, 1, 3, 50, 75};
    int lo = 0;
    int hi = 99;

    vector<string> result = findMissingRanges(A, sizeof(A)/sizeof(A[0]), lo ,hi);

    printVector(result);    


    //usage: ./missingRanges 0 9 "3 5 7"
    if (argc>3){
        lo = atoi(argv[1]);
        hi = atoi(argv[2]);
        vector<int> a;
        a = string2Array(argv[3]);

        int *pA = &a[0];
        result = findMissingRanges(pA, a.size(), lo, hi);
        printVector(result);    
    }

    return 0;
}
