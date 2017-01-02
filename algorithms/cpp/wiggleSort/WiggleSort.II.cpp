// Source : https://leetcode.com/problems/wiggle-sort-ii/
// Author : Hao Chen
// Date   : 2017-01-02

/*************************************************************************************** 
 *
 * Given an unsorted array nums, reorder it such that
 *     nums[0]  nums[2] .
 * 
 *     Example:
 *     (1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
 *     (2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].
 * 
 *     Note:
 *     You may assume all input has valid answer.
 * 
 *     Follow Up:
 *     Can you do it in O(n) time and/or in-place with O(1) extra space?
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating all test 
 * cases.
 ***************************************************************************************/

class Solution {

public:
    //
    // Solution - O(N*logN)
    // --------------------
    // 1) Sorting the array with descending order
    //
    // 2) Split the sorted array into two parts,
    //    and insert the 2nd half array into the 1st half array
    //
    //    For example: [ 9 8 7 6 5  4 3 2 1 0  ]
    //
    //  
    //        1st Large half:    . 9 . 8 . 7 . 6 . 5
    //        2nd Small half:    4 . 3 . 2 . 1 . 0 .
    //        ---------------------------------------
    //                Result:    4 9 3 8 2 7 1 6 0 5
    //
    // Be careful if the length of array is odd number, 
    // Such as: [5 4 3 2 1], 
    // The 2nd half is [3 2 1] instead of [2 1]
    // 

    void wiggleSort01(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int x, int y) { return x > y; });
        int half = (nums.size() / 2);
        
        for (int i=0; i<half; i++) {
            int v = nums[half+i];
            nums.erase(nums.begin() + half + i );
            nums.insert(nums.begin() + (2*i), v);
        }
        cout << endl;
    }
    
    //
    // After checked the discussion of Leetcode, I found there is a really brilliant idea
    // which used a tricky idea - virtual index.
    // 
    // Please refer to the following link to see the full details:
    // https://discuss.leetcode.com/topic/32929/o-n-o-1-after-median-virtual-indexing
    
    void wiggleSort02(vector<int>& nums) {
        int n = nums.size();
        
        // Find a median.
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        
        // Index-rewiring.
        #define A(i) nums[(1+2*(i)) % (n|1)]
    
        // 3-way-partition-to-wiggly in O(n) time with O(1) space.
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (A(j) > mid)
                swap(A(i++), A(j++));
            else if (A(j) < mid)
                swap(A(j), A(k--));
            else
                j++;
        }
    }
    void wiggleSort(vector<int>& nums) {
        return wiggleSort02(nums); //~140ms
        return wiggleSort01(nums); //~230ms
    }
};
