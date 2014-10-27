// Source : https://oj.leetcode.com/problems/first-missing-positive/
// Author : Hao Chen
// Date   : 2014-07-18

/********************************************************************************** 
* 
* Given an unsorted integer array, find the first missing positive integer.
* 
* For example,
* Given [1,2,0] return 3,
* and [3,4,-1,1] return 2.
* 
* Your algorithm should run in O(n) time and uses constant space.
* 
*               
**********************************************************************************/

#include <iostream>
#include <map>
using namespace std;

#define INT_MAX      2147483647

/*
 *    The idea is simple:
 *
 *    1) put all of number into a map.
 *    2) for each number a[i] in array, remove its continous number in the map
 *        2.1)  remove ... a[i]-3, a[i]-2, a[i]-1, a[i]
 *        2.2)  remove a[i]+1, a[i]+2, a[i]+3,...
 *    3) during the removeing process, if some number cannot be found, which means it's missed.
 *
 *    considering a case [-2, -1, 4,5,6], 
 *        [-2, -1] => missed 0
 *        [4,5,6]  => missed 3
 *
 *    However, we missed 1, so, we have to add dummy number 0 whatever.
 *
 */
int firstMissingPositive(int A[], int n) {
    map<int, int> cache;
    for(int i=0; i<n; i++){
        cache[A[i]] = i;
    }

    //add dummy
    if (cache.find(0)==cache.end() ) {
        cache[0] = -1;
    }

    int miss = INT_MAX;
    int x;
    for (int i=-1; i<n && cache.size()>0; i++){
        
        if (i == -1){
            x = 0; //checking dummy
        }else{
            x = A[i];
        } 
    
        if ( cache.find(x)==cache.end() ){
            continue;
        }

        int num ;
        // remove the ... x-3, x-2, x-1, x
        for( num=x; cache.find(num)!=cache.end(); num--){
            cache.erase(cache.find(num));
        }
        if ( num>0 && num < miss  ){
            miss = num;
        }
        // remove the x+1, x+2, x+3 ...
        for ( num=x+1; cache.find(num)!=cache.end(); num++){
            cache.erase(cache.find(num));
        }
        if ( num>0 && num < miss) {
            miss = num;
        }
    }
    

    return miss;
}

int main()
{
    #define TEST(a) cout << firstMissingPositive(a, sizeof(a)/sizeof(int)) << endl

    int a1[]={1,2,0};
    TEST(a1);

    int a2[]={3,4,-1,1};
    TEST(a2);

    int a3[]={1000,-1};
    TEST(a3);

    int a4[]={1000, 200};
    TEST(a4);

    int a5[]={2,5,4,3,-1};
    TEST(a5);

    int a6[]={1, 100};
    TEST(a6);

    return 0;
}
