// Source : https://oj.leetcode.com/problems/jump-game-ii/
// Author : Hao Chen
// Date   : 2014-07-18

/********************************************************************************** 
* 
* Given an array of non-negative integers, you are initially positioned at the first index of the array.
* 
* Each element in the array represents your maximum jump length at that position. 
* 
* Your goal is to reach the last index in the minimum number of jumps.
* 
* For example:
* Given array A = [2,3,1,1,4]
* 
* The minimum number of jumps to reach the last index is 2. 
* (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
* 
*               
**********************************************************************************/

#include <iostream>
using namespace std;

//Acutally, using the Greedy algorithm can have the answer
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
        //Greedy: find the next place which can have biggest distance
        int nextPos=0;
        int maxDistance=0;
        for(int j=i+1; j<=coverPos; j++){
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
    #define TEST(a) printArray(a, sizeof(a)/sizeof(a[0])); cout<<jump(a, sizeof(a)/sizeof(a[0]))<<endl;

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

    // 0 -> 1 -> 4 -> end
    int a6[]={2,3,1,1,4,0,1};
    TEST(a6);

    // 0 -> 1 -> 3 -> end
    int a7[]={2,3,1,2,0,1};
    TEST(a7);

    return 0;
}
