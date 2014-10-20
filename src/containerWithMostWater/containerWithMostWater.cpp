// Source : https://oj.leetcode.com/problems/container-with-most-water/
// Author : Hao Chen
// Date   : 2014-06-22

class Solution {
public:
    int maxArea(vector<int> &height) {
        int area = 0;
        int i = 0; 
        int j = height.size()-1;
        
        while(i<j){
            int a = (j-i)* (height[i]>height[j] ? height[j] : height[i]);
            area = a>area ? a : area;
            height[i]>height[j] ? j-- : i++;
        }
        
        return area;
    }
};
