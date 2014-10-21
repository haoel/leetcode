// Source : https://oj.leetcode.com/problems/two-sum/
// Author : Hao Chen
// Date   : 2014-06-17

/********************************************************************************** 
* 
* Given an array of integers, find two numbers such that they add up to a specific target number.
* 
* The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
* 
* You may assume that each input would have exactly one solution.
* 
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2
* 
*               
**********************************************************************************/

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> m;
        vector<int> result;
        for(int i=0; i<numbers.size(); i++){
            if (m.find(numbers[i])==m.end() ) { // not found
                m[target - numbers[i]] = i;
            }else { // found
                result.push_back(m[numbers[i]]+1);
                result.push_back(i+1);
                break;
            }
        }
        return result;
    }
};
