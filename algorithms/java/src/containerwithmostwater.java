// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
// n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0).
// Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

// Notice that you may not slant the container.

// Solution: Start with walls at either end. If the current area is greater than the max area, update it.
// At each step, move the shorter wall one step towards the longer wall and recalculate. O(n) complexity. 

class Solution {
    public int maxArea(int[] height) {
        List<Integer> list = new ArrayList<Integer>();
        int start = 0, end = height.length - 1, multiplier = height.length - 1;
        int maxarea = Integer.MIN_VALUE;

        while (multiplier != 0) {
       
            maxarea = Integer.max(maxarea, Integer.min(height[start], height[end]) * multiplier--);
            if (height[start] > height[end]) {
                end--;
            } else {
                start++;
            }
        }
        return maxarea;
    }
}
