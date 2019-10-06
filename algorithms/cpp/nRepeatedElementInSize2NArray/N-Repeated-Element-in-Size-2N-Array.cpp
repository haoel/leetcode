// Source : https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
// Author : Manu Gond
// Date   : 2019-10-06

/***************************************************************************************************** 
*	In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.
*	
*	Return the element repeated N times.
*	
*	 
*	
*	Example 1:
*	
*	Input: [1,2,3,3]
*	Output: 3
*	Example 2:
*	
*	Input: [2,1,2,5,3,2]
*	Output: 2
*	Example 3:
*	
*	Input: [5,1,5,2,5,3,5,4]
*	Output: 5
*	 
*	
*	Note:
*	
*	4 <= A.length <= 10000
*	0 <= A[i] < 10000
*	A.length is even
 ******************************************************************************************************/
 
 class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        map<int,int>myMap;
        for(int i=0;i<A.size();i++){
            myMap[A[i]]++;
        }
        for(auto x:myMap){
            if((x.second)==(A.size()/2)){
                return x.first;
            }
        }
        return 0;
    }
};
