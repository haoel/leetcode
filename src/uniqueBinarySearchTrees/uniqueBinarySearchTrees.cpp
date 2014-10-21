// Source : https://oj.leetcode.com/problems/unique-binary-search-trees/
// Author : Hao Chen
// Date   : 2014-06-25

/********************************************************************************** 
* 
* Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
* 
* For example,
* Given n = 3, there are a total of 5 unique BST's.
* 
*    1         3     3      2      1
*     \       /     /      / \      \
*      3     2     1      1   3      2
* 
*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numTrees1(int n) ;
int numTrees2(int n) ;

int numTrees(int n) {
    return numTrees1(n);
}

int numTrees1(int n) {
    int *cnt = (int*)malloc((n+1)*sizeof(int));
    memset(cnt, 0, (n+1)*sizeof(int));
    cnt[0] = 1;
    cnt[1] = 1;
    
    for (int i=2; i<=n; i++){
        for(int j=0; j<i; j++){
           cnt[i] += cnt[j]*cnt[i-j-1];
        }
    }
    int sum = cnt[n];
    free(cnt);
    return sum;
}



int numTrees2(int n) {
    if (n<=0) return 0;
    if (n == 1 ) return 1;
    int sum=0;
    for (int i=1; i<=n; i++){
        if (i==1||i==n){
            sum += numTrees(n-1);
        }else{
            sum += (numTrees(i-1) * numTrees(n-i));
        }
    }
    return sum;
}


int main(int argc, char** argv) 
{
    int n=2;
    if (argc>1){
        n = atoi(argv[1]);
    }
    printf("%d=%d\n", n, numTrees(n));
    return 0;
}
