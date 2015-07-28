// Source : https://oj.leetcode.com/problems/median-of-two-sorted-arrays/
// Author : Hao Chen
// Date   : 2014-07-22

/********************************************************************************** 
* 
* There are two sorted arrays A and B of size m and n respectively. 
* Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*               
**********************************************************************************/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t len = nums1.size() + nums2.size();
        return (len % 2 == 1) ?
            findKthSmall (nums1, nums2, len / 2 + 1) :
            (findKthSmall (nums1, nums2, len / 2 + 1) + 
            findKthSmall (nums1, nums2, len / 2)) / 2;
    }
private:
    double findKthSmall (const vector<int> &nums1, const vector<int> &nums2, size_t k) {
        size_t len1 = nums1.size(), len2 = nums2.size();
        if (len1 > len2) // ensure that len1 is always not greater than len2
            return findKthSmall(nums2, nums1, k);
        // simple situations
        if (len1 == 0)
            return nums2[k - 1];
        if (k == 1)
            return min(nums1[0], nums2[0]);
        size_t pNums1 = min(k / 2, len1), pNums2 = k - pNums1; // two working pointers (size_t)
        // algorithm: divide and conquer, binary search
        if (nums1[pNums1 - 1] < nums2[pNums2 - 1]) {
            // this means the former pNums1 elements in nums1 are too small
            // we could drop them and findKthSmall in temp and nums2, and k is k - pNums1
            vector<int> temp((nums1.begin() + pNums1), nums1.end());
            return findKthSmall(temp, nums2, k - pNums1);
        }
        else if (nums1[pNums1 - 1] > nums2[pNums2 - 1]) {
            // this means the former pNums2 elements in nums2 are too small
            // similar method compared to the first case
            vector<int> temp((nums2.begin() + pNums2), nums2.end());
            return findKthSmall(nums1, temp, k - pNums2);
        }
        else
            // this means we've found the answer, return level by level
            return nums1[pNums1 - 1];
    }
};
