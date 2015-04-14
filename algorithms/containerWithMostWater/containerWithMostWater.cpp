// Source : https://oj.leetcode.com/problems/container-with-most-water/
// Author : Hao Chen
// Date   : 2014-06-22

/********************************************************************************** 
* 
* Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
* n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
* 
* Find two lines, which together with x-axis forms a container, such that the container contains the most water.
* 
* Note: You may not slant the container.
* 
*               
**********************************************************************************/

class Solution {
public:
    int maxArea(vector<int> &height) {

        int maxArea = 0;
        // two pointers scan from two sides to middle
        int left = 0; 
        int right = height.size()-1;

        int area; 
        while ( left < right ){
            int leftHeight = height[left];
            int rightHeight = height[right];
            // calculate the area
            area = (right - left) * (leftHeight < rightHeight ? leftHeight : rightHeight);
            // tracking the maxium area
            maxArea = area > maxArea ? area : maxArea;
            // because the area is decided by the shorter edge
            // so we increase the area is to increase the shorter edge
            //
            //     height[left] < height[right] ? left++ : right-- ;
            //
            // However, the above code could cause the unnecessary `area` cacluation
            // We can do some improvement as below:
            if (leftHeight < rightHeight) {
                do {
                    left++;
                } while (left < right && leftHeight >= height[left]);
            } else {
                do {
                    right--;
                } while (right > left && rightHeight >= height[right]);
            }
        }
        
        return maxArea;
    }
};
