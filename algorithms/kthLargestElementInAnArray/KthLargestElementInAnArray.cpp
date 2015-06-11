// Source : https://leetcode.com/problems/kth-largest-element-in-an-array/
// Author : Hao Chen
// Date   : 2015-06-11

/********************************************************************************** 
 * 
 * Find the kth largest element in an unsorted array. 
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * 
 * For example,
 * Given [3,2,1,5,6,4] and k = 2, return 5.
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.
 *               
 **********************************************************************************/




class Solution {
public:
    //STL using qsort to solve this problem
    int findKthLargest_buildin(vector<int>& nums, int k) {
        int n=nums.size();
        std::nth_element(nums.begin(),nums.end()-k,nums.end());
        return nums[n-k];
    }
    
    //qsort partition
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot){
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot) l++;
            if (nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
    
    int findKthLargest_qsort(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1){ 
                return nums[pos];
            }
            if (pos > k - 1) {
                right = pos - 1;
            }else{
                left = pos + 1;  
            }  
        }
    }
    
    
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest_qsort(nums, k);
    }
};
