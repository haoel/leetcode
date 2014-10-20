// Source : https://oj.leetcode.com/problems/gray-code/
// Author : Hao Chen
// Date   : 2014-06-20

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;


vector<int> grayCode(int n) {
    vector<int> v;
    //n = 1<<n;
    
    int x =0;   
    v.push_back(x); 
    for(int i=0; i<n; i++){
        int len = v.size();
        for (int j=0; j<len; j++){
            x = v[j]<<1;
            if (j%2==0){
                v.push_back(x);
                v.push_back(x+1);
            }else{
                v.push_back(x+1);
                v.push_back(x);
            }
        }
        v.erase(v.begin(), v.begin()+len);
    }
     
    return v;
}

void printBits(int n, int len){
    for(int i=len-1; i>=0; i--) {
        if (n & (1<<i)) {
            printf("1");
        }else{
            printf("0");
        }
    }
}

void printVector(vector<int>& v, int bit_len)
{
    vector<int>::iterator it;
    
    for(it=v.begin(); it!=v.end(); ++it){
        //bitset<bit_len> bin(*it);
        printBits(*it, bit_len);
        cout <<  " ";
        //cout << *it <<  " ";
    }
    cout << endl;
}

int main(int argc, char** argv)
{
    int n = 2;
    if (argc>1){
       n = atoi(argv[1]); 
    }
    vector<int> v = grayCode(n);
    printVector(v, n);
    return 0;
}
