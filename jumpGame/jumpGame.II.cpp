// Source : https://oj.leetcode.com/problems/jump-game-ii/
// Author : Hao Chen
// Date   : 2014-07-18

#include <iostream>
using namespace std;

int jump(int A[], int n) {
    if (n<=1) return 0;
    
    int steps = 0;
    int coverPos = 0;
    for (int i=0; i<=coverPos&& i<n; ){
        if (A[i]==0) return -1; 
        if(coverPos < A[i]+i){
            coverPos = A[i]+i;
            steps++;
        }
        if (coverPos >= n-1){
            return steps;
        }
        int nextPos=0;
        int maxDistance=0;
        for(int j=i+1; j<=A[i]+i; j++){
            if ( A[j]+j > maxDistance ) {
                maxDistance = A[j]+j;
                nextPos = j;
            }
        }
        i = nextPos;
    }
    return steps;
}

void printArray(int a[], int n){
    cout << "{ ";
    for(int i=0; i<n; i++){
        if(i) cout << ", ";
        cout << a[i];
    }
    cout << " } ";
}
int main()
{
    #define TEST(a) printArray(a, sizeof(a)/sizeof(int)); cout<<jump(a, sizeof(a)/sizeof(int))<<endl;

    int a1[]={0};
    TEST(a1);

    int a2[]={1};
    TEST(a2);

    int a3[]={3,2,1,0,4};
    TEST(a3);

    int a4[]={2,3,1,1,4};
    TEST(a4);

    int a5[]={1,2,3};
    TEST(a5);

    return 0;
}
