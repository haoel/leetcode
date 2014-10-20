// Source : https://oj.leetcode.com/problems/two-sum/
// Author : Hao Chen
// Date   : 2014-06-17

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
