// Source : https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/
// Author : Hao Chen
// Date   : 2021-03-27

/***************************************************************************************************** 
 *
 * You are given an array rectangles where rectangles[i] = [li, wi] represents the i^th rectangle of 
 * length li and width wi.
 * 
 * You can cut the i^th rectangle to form a square with a side length of k if both k <= li and k <= 
 * wi. For example, if you have a rectangle [4,6], you can cut it to get a square with a side length 
 * of at most 4.
 * 
 * Let maxLen be the side length of the largest square you can obtain from any of the given rectangles.
 * 
 * Return the number of rectangles that can make a square with a side length of maxLen.
 * 
 * Example 1:
 * 
 * Input: rectangles = [[5,8],[3,9],[5,12],[16,5]]
 * Output: 3
 * Explanation: The largest squares you can get from each rectangle are of lengths [5,3,5,5].
 * The largest possible square is of length 5, and you can get it out of 3 rectangles.
 * 
 * Example 2:
 * 
 * Input: rectangles = [[2,3],[3,7],[4,3],[3,7]]
 * Output: 3
 * 
 * Constraints:
 * 
 * 	1 <= rectangles.length <= 1000
 * 	rectangles[i].length == 2
 * 	1 <= li, wi <= 10^9
 * 	li != wi
 ******************************************************************************************************/

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        return countGoodRectangles2(rectangles);
        return countGoodRectangles1(rectangles); 
    }
    
    int countGoodRectangles1(vector<vector<int>>& rectangles) {
        int maxLen = 0;
        for(auto& rect : rectangles) {
            int  len = min(rect[0], rect[1]);
            maxLen = max(maxLen, len);
        }
        
        int cnt = 0;
        for(auto& rect : rectangles) {
            if (maxLen <= rect[0] && maxLen <= rect[1]) cnt++;
        }
        return cnt;
    }
    
    int countGoodRectangles2(vector<vector<int>>& rectangles) {
        int maxLen = 0;
        int cnt = 0;
        for(auto& rect : rectangles) {
            int  len = min(rect[0], rect[1]);
            if (len > maxLen ) {
                cnt = 1;
                maxLen = len;
            }else if (len == maxLen ) {
                cnt++;
            }
        }

        return cnt;
    }
};
