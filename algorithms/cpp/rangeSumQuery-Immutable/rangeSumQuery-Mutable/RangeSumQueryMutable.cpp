// Source : https://leetcode.com/problems/range-sum-query-mutable/
// Author : Hao Chen
// Date   : 2015-11-24

/*************************************************************************************** 
 *
 * Given an integer array nums, find the sum of the elements between indices i and j (i 
 * ≤ j), inclusive.
 * 
 * The update(i, val) function modifies nums by updating the element at index i to val.
 * 
 * Example:
 * 
 * Given nums = [1, 3, 5]
 * 
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 * 
 * Note:
 * 
 * The array is only modifiable by the update function.
 * You may assume the number of calls to update and sumRange function is distributed 
 * evenly.
 *
 ***************************************************************************************/


// The following idea is using `Binary Index Tree`
// There are two articles explaine this technique quite well:
// 1) http://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
// 2) http://cs.stackexchange.com/questions/10538/bit-what-is-the-intuition-behind-a-binary-indexed-tree-and-how-was-it-thought-a

class NumArray {
private:
    int _sz;
    vector<int> _nums;
    vector<int> _sums;    
public:
    NumArray(vector<int> &nums)  {
        _sz = nums.size();
        _nums.resize(_sz+1, 0);
        _sums.resize(_sz+1, 0);
        for(int i=0; i< _sz; i++) {
            update(i, nums[i]);          
        }
    }

    void update(int i, int val) {
        int oldv = _nums[i+1];
        for(int idx = i+1; idx <= _sz; idx += (idx & (-idx))  ) {
            _sums[idx] = _sums[idx] - oldv + val;
        }
        _nums[i+1] = val;
    }

    int sumRange(int i, int j) {
        return sumRange(j+1) - sumRange(i);
    }
    
    int sumRange(int i) {
        int ret = 0;
        for(int idx=i; idx>0; idx -= (idx & (-idx)) ) {
            ret += _sums[idx];
        }
        return ret;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
