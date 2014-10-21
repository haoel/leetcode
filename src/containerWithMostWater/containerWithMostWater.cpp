// Source : https://oj.leetcode.com/problems/container-with-most-water/
// Author : Hao Chen
// Date   : 2014-06-22

/********************************************************************************** 
* 
* Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
* 
* Note: You may not slant the container.
* 
*               
**********************************************************************************/

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
