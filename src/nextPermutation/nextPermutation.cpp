// Source : https://oj.leetcode.com/problems/next-permutation/
// Author : Hao Chen
// Date   : 2014-08-21

/********************************************************************************** 
* 
* Implement next permutation, which rearranges numbers into the lexicographically next 
* greater permutation of numbers.
* 
* If such arrangement is not possible, it must rearrange it as the lowest possible order 
* (ie, sorted in ascending order).
* 
* The replacement must be in-place, do not allocate extra memory.
* 
* Here are some examples. Inputs are in the left-hand column and its corresponding outputs 
* are in the right-hand column.
*
*   1,2,3 → 1,3,2
*   3,2,1 → 1,2,3
*   1,1,5 → 1,5,1
*               
**********************************************************************************/

/*
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2
2 1 3 4
...
*/

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int> &num) {

    if(num.size()<=1) return;

    for(int i=num.size()-1; i>0; i--) {
        if (num[i-1] < num[i]){
            int j = num.size()-1;
            while( num[i-1] >= num[j]) {
                //pass;
                j--;
            }
            int tmp = num[j];
            num[j] = num[i-1];
            num[i-1] = tmp;
            reverse(num.begin()+i, num.end()); 
            return; 
        }
        if (i == 1 ){
            reverse(num.begin(), num.end());
            return;
        }
    }

}

void printVector(vector<int> &num) {
    for(int i=0; i<num.size(); i++) {
        cout << num[i] << " ";
    } 
    cout <<endl;
}
bool isBeginVector(vector<int> &num) {
    for(int i=0; i<num.size(); i++) {
        if(num[i] != i+1) {
            return false;
        }
    } 
    return true;
}

int main(int argc, char** argv)
{
    int n = 4;
    if (argc>1){
        n = atoi(argv[1]);
    }
    vector<int> num;
    for(int i=1; i<=n; i++){
        num.push_back(i);
    }
    
    while(true){
        printVector(num);
        nextPermutation(num);
        if(isBeginVector(num)){
            break;
        }
    }
    return 0;
}
