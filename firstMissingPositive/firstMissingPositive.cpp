// Source : https://oj.leetcode.com/problems/first-missing-positive/
// Author : Hao Chen
// Date   : 2014-07-18

#include <iostream>
#include <map>
using namespace std;

#define INT_MAX      2147483647

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
        for( num=x; cache.find(num)!=cache.end(); num--){
            cache.erase(cache.find(num));
        }
        if ( num>0 && num < miss  ){
            miss = num;
        }
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
