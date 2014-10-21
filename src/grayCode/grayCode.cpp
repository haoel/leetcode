// Source : https://oj.leetcode.com/problems/gray-code/
// Author : Hao Chen
// Date   : 2014-06-20

/********************************************************************************** 
* 
* The gray code is a binary numeral system where two successive values differ in only one bit.
* 
* Given a non-negative integer n representing the total number of bits in the code, 
* print the sequence of gray code. A gray code sequence must begin with 0.
* 
* For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
* 
* 00 - 0
* 01 - 1
* 11 - 3
* 10 - 2
* 
* Note:
* For a given n, a gray code sequence is not uniquely defined.
* 
* For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
* 
* For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*               
**********************************************************************************/

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
