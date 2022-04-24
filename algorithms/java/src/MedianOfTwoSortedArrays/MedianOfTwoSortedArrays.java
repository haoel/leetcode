// Source : https://leetcode.com/problems/median-of-two-sorted-arrays/
// Author : Diego Ruiz Piqueras (Pikeras72)
// Date   : 23-04-2022

/***************************************************************************************************** 
 *
 * Given two sorted arrays nums1 and nums2 of size m and n respectively,
 * return the median of the two sorted arrays.
 * 
 * The overall run time complexity should be O(log (m+n)).
 * 
 * Example 1:
 * 
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 * 
 * Example 2:
 *
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 * 
 * 
 * Constraints:
 * 
 *  nums1.length == m
 *  nums2.length == n
 *  0 <= m <= 1000
 *  0 <= n <= 1000
 *  1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 * 
 * Explanation of the solution:
 * 
 * 1. Concatenate both arrays (int[] concatenate).
 * 
 * 2. Sort the 'concatenate' array.
 * 
 * 3. If 'concatenate' have an odd nuber of elements return the element in the middle, otherwise return the sum of the middle numbers.
 ******************************************************************************************************/

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        double c;
        int[] concatenate = new int[nums1.length + nums2.length];
        System.arraycopy(nums1, 0, concatenate, 0, nums1.length);              //Add the first array
        System.arraycopy(nums2, 0, concatenate, nums1.length, nums2.length);   //Add the second array
        Arrays.sort(concatenate);
        if (concatenate.length % 2 == 0){
            c = concatenate[concatenate.length/2-1]+concatenate[concatenate.length/2];
            return c/2;
        }else {
            return concatenate[concatenate.length/2];
        }
    }
}
