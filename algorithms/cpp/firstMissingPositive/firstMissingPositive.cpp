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
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <map>
using namespace std;

#define INT_MAX      2147483647

/*
 *  Idea:
 * 
 *    We can move the num to the place whcih the index is the num. 
 *   
 *    for example,  (considering the array is zero-based.
 *       1 => A[0], 2 => A[1], 3=>A[2]
 *   
 *    Then, we can go through the array check the i+1 == A[i], if not ,just return i+1;
 *   
 *    This solution comes from StackOverflow.com
 *    http://stackoverflow.com/questions/1586858/find-the-smallest-integer-not-in-a-list
*/
int firstMissingPositive_move(int A[], int n) {
    if (n<=0) return 1;
    int num;
    for(int i=0; i<n; i++) {
        num = A[i];
        while (num>0 && num<n && A[num-1]!=num) {
            swap(A[i], A[num-1]);
            num = A[i];
        }
    }
    for (int i=0; i<n; i++){
        if (i+1 != A[i]){
            return i+1;
        }
    }
    return n+1;
}

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
 *    NOTE: this solution is not constant space slution!!!!
 *
 */
int firstMissingPositive_map(int A[], int n) {
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

int firstMissingPositive(int A[], int n) {
    srand(time(0));
    if (rand()%2){
        return firstMissingPositive_move(A, n);
    }
    return firstMissingPositive_map(A, n);
}


void printArray(int a[], int n){
    cout << "[ ";
    for(int i=0; i<n-1; i++) {
        cout << a[i] << ", ";
    }
    cout << a[n-1] << " ]";
}

void Test(int a[], int n, int expected) {
    printArray(a, n);
    int ret = firstMissingPositive(a, n);
    cout << "\t   missed = " << ret << "  " << (ret==expected?"passed!":"failed!") << endl;
    //printArray(a, n);
    //cout <<endl;
}

int main()
{
#define TEST(a, e) Test(a, sizeof(a)/sizeof(int), e) 

    int a0[]={1};
    TEST(a0, 2);

    int a1[]={1,2,0};
    TEST(a1, 3);

    int a2[]={3,4,-1,1};
    TEST(a2, 2);

    int a3[]={1000,-1};
    TEST(a3, 1);

    int a4[]={1000, 200};
    TEST(a4, 1);

    int a5[]={2,5,3,-1};
    TEST(a5, 1);

    int a6[]={1, 100};
    TEST(a6, 2);

    int a7[]={7,8,9,11};
    TEST(a7, 1);

    int a8[]={4,3,2,1};
    TEST(a8, 5);

    return 0;
}
