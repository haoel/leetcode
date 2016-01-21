// Source : https://leetcode.com/problems/create-maximum-number/
// Author : Hao Chen
// Date   : 2016-01-21

/*************************************************************************************** 
 *
 * Given two arrays of length m and n with digits 0-9 representing two numbers.
 *     Create the maximum number of length k  from digits of the two. The relative 
 * order of the digits
 *     from the same array must be preserved. Return an array of the k digits. You 
 * should try to optimize your time and space complexity.
 * 
 *     Example 1:
 * 
 *     nums1 = [3, 4, 6, 5]
 *     nums2 = [9, 1, 2, 5, 8, 3]
 *     k = 5
 *     return [9, 8, 6, 5, 3]
 * 
 *     Example 2:
 * 
 *     nums1 = [6, 7]
 *     nums2 = [6, 0, 4]
 *     k = 5
 *     return [6, 7, 6, 0, 4]
 * 
 *     Example 3:
 * 
 *     nums1 = [3, 9]
 *     nums2 = [8, 9]
 *     k = 3
 *     return [9, 8, 9]
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating all test 
 * cases.
 ***************************************************************************************/



/*
 * Solution
 * --------
 * 
 * 1) We split the `K` to two parts : `i` & `k-i`  0<= i <= k
 * 
 * 2) Find the max number for both arrays with giving the length `i` and `k-i`
 *      - sub1 = FindMaxNumber(num1, len=i);
 *      - sub2 = FindMaxNumber(num2, len=k-i);
 *    Here, we need use stack-way to solve find the max number.
 * 
 * 3) Merge two arrays 
 *      - solution = Merge(sub1, sub2);
 *    Here, we need be careful if a two number are same which one we need to take.  For examples: 
 *      [6,7]
 *      [6,0,4]
 *      5
 *      
 *      [2,5,6,4,4,0]
 *      [7,3,8,0,6,5,7,6,2]
 *      15
 * 
 * 4) compare with the last solution
 *     - result = max(result, solution); 
 * 
 * 
 */


class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> result;
        int len1 = nums1.size();
        int len2 = nums2.size();
        for (int i=0; i<=k; i++){
            if (len1 < i || len2 < k-i) continue;
            vector<int> sub1 = findMaxSubArray(nums1, i);
            vector<int> sub2 = findMaxSubArray(nums2, k-i);
            vector<int> merge = mergeTwoArrays(sub1, sub2);
            if (compareTwoArray(merge, 0, result, 0)) {
                result = merge;
            }
        }
        return result;
    }
    
    
    bool compareTwoArray(vector<int>& nums1, int start1, vector<int>& nums2, int start2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(; start1<n1 && start2<n2; start1++, start2++){
            if (nums1[start1] > nums2[start2]) return true;
            if (nums1[start1] < nums2[start2]) return false;
        }
        //if num1 still have numbers, return true, else return false
        return start1 < nums1.size();
    }
    
    vector<int> mergeTwoArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int len1 = nums1.size();
        int len2 = nums2.size();
        int pos1=0, pos2=0;
        while ( pos1 < len1 && pos2 < len2 ){
            // Be careful if two numbers are equal. consider the following case
            // case 1: [6,7], [6,0,4]  - we have same item - 6
            // case 2: [4,0,2], [2,0,3,1] - we have same item - 0
            // which one we need to merge?
            // We need compare the rest of array.
            if (nums1[pos1] == nums2[pos2]){
                result.push_back( compareTwoArray(nums1, pos1+1, nums2, pos2+1) ? 
                                    nums1[pos1++] : nums2[pos2++]);
            }else {
                result.push_back(nums1[pos1] > nums2[pos2] ? 
                                    nums1[pos1++] : nums2[pos2++]);
            }
        }
        
        if (pos1 < len1){
            result.insert(result.end(), nums1.begin()+pos1, nums1.end());
        }
        if (pos2 < len2) {
            result.insert(result.end(), nums2.begin()+pos2, nums2.end());
        }
        
        return result;
    }
    
    
    // using a stack method to find the max sub-array
    // k <= nums.size()
    vector<int> findMaxSubArray(vector<int>& nums, int k) {
        int len = nums.size();
        if ( k >= len ) return nums;
        vector<int> result(k, 0);
        int idx = 0; // the postion for result array
        for (int i=0; i<len; i++){
            // if we met a number > the last element of result[], 
            // and we still have enough numbers,
            // then pop up the item
            while (idx>0 && k - idx < len - i && result[idx-1] < nums[i]) {
                idx--;
            }
            //push the number into the result[]
            if (idx < k) {
                result[idx++] = nums[i];
            }
        }
        return result;
    }
    
};
