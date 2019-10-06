// Source : https://leetcode.com/problems/unique-number-of-occurrences/
// Author : Manu Gond
// Date   : 2019-10-06

/***************************************************************************************************** 
*	Given an array of integers arr, write a function that returns true if and only if the number of occurrences of each value in the array is unique.
*	
*	 
*
*	Example 1:
*	
*	Input: arr = [1,2,2,1,1,3]
*	Output: true
*	Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
*	Example 2:
*	
*	Input: arr = [1,2]
*	Output: false
*	Example 3:
*	
*	Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
*	Output: true
*	 
*	
*	Constraints:
*	
*	1 <= arr.length <= 1000
*	-1000 <= arr[i] <= 1000
 ******************************************************************************************************/
 class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>myMap;
        for(int i=0;i<arr.size();i++){
            myMap[arr[i]]++;
        }
        int temp=0;
        vector<int>v;
        for (auto i : myMap) {
            v.push_back(i.second);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            if(v[i]==temp)
                return false;
            else
                temp=v[i];
        }
        return true;
             
    }
};
