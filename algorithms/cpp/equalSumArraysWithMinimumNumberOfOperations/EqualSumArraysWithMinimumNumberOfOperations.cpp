// Source : https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/
// Author : Hao Chen
// Date   : 2021-03-24

/***************************************************************************************************** 
 *
 * You are given two arrays of integers nums1 and nums2, possibly of different lengths. The values in 
 * the arrays are between 1 and 6, inclusive.
 * 
 * In one operation, you can change any integer's value in any of the arrays to any value between 1 
 * and 6, inclusive.
 * 
 * Return the minimum number of operations required to make the sum of values in nums1 equal to the 
 * sum of values in nums2. Return -1​​​​​ if it is not possible to make the sum of the two arrays 
 * equal.
 * 
 * Example 1:
 * 
 * Input: nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
 * Output: 3
 * Explanation: You can make the sums of nums1 and nums2 equal with 3 operations. All indices are 
 * 0-indexed.
 * - Change nums2[0] to 6. nums1 = [1,2,3,4,5,6], nums2 = [6,1,2,2,2,2].
 * - Change nums1[5] to 1. nums1 = [1,2,3,4,5,1], nums2 = [6,1,2,2,2,2].
 * - Change nums1[2] to 2. nums1 = [1,2,2,4,5,1], nums2 = [6,1,2,2,2,2].
 * 
 * Example 2:
 * 
 * Input: nums1 = [1,1,1,1,1,1,1], nums2 = [6]
 * Output: -1
 * Explanation: There is no way to decrease the sum of nums1 or to increase the sum of nums2 to make 
 * them equal.
 * 
 * Example 3:
 * 
 * Input: nums1 = [6,6], nums2 = [1]
 * Output: 3
 * Explanation: You can make the sums of nums1 and nums2 equal with 3 operations. All indices are 
 * 0-indexed. 
 * - Change nums1[0] to 2. nums1 = [2,6], nums2 = [1].
 * - Change nums1[1] to 2. nums1 = [2,2], nums2 = [1].
 * - Change nums2[0] to 4. nums1 = [2,2], nums2 = [4].
 * 
 * Constraints:
 * 
 * 	1 <= nums1.length, nums2.length <= 10^5
 * 	1 <= nums1[i], nums2[i] <= 6
 ******************************************************************************************************/

class Solution { 
private:
    void print(vector<int>& n) {
        cout <<"[";
        for(int i=0; i< n.size() - 1; i++) {
            cout << n[i] << ",";
        }
        cout << n[n.size()-1] << "]" <<endl;
    }
private:
    int minOpsBySort(int gaps, vector<int>& small, vector<int>& big) {
        
        sort(small.begin(), small.end());
        sort(big.begin(), big.end());
        
        int op = 0;
        int left = 0, right = big.size() -1;
        while (gaps >0) {
            
            int small_gaps = left < small.size() ? 6 - small[left] : 0;
            int big_gaps = right >= 0 ? big[right] - 1 : 0;
            
            if (small_gaps > big_gaps) {
                gaps -= small_gaps;
                left++;
            }else{
                gaps -= big_gaps;
                right--;
            }
            op++;
        }
        return op;
    }
    
    int minOpsByCnt1(int gaps, vector<int>& small, vector<int>& big) {
        int small_cnt[6] = {0} , big_cnt[6] = {0};
        for (auto& n : small) small_cnt[n-1]++;
        for (auto& n : big) big_cnt[n-1]++;
        
        int op = 0;
        int left = 0, right = 5; 
        
        while( gaps > 0 ) {
            while (left < 6 && small_cnt[left] == 0 ) left++;
            while ( right >=0 && big_cnt[right] == 0 ) right--;
            int small_gaps = left < 6 ? 6 - (left + 1) : 0;
            int big_gaps = right >= 0 ? right : 0;
            
            if (small_gaps > big_gaps) {
                gaps -= small_gaps;
                small_cnt[left]--;
            }else{
                gaps -= big_gaps;
                big_cnt[right]--;
            }
            op++;
        }
        return op;
    }
    
    int minOpsByCnt2(int gaps, vector<int>& small, vector<int>& big) {
        int cnt[6] = {0};
        for (auto& n : small) cnt[6-n]++;
        for (auto& n : big) cnt[n-1]++;
        
        int ops = 0;
        for (int i=5 ; i >= 0 && gaps > 0; i--) {
            if (cnt[i] == 0) continue;
            if (cnt[i] * i > gaps) {
                ops +=  (gaps / i  + (gaps % i ? 1:0) ) ;
                break;
            }
            gaps -= cnt[i] * i;
            ops += cnt[i];
        }
 
        return ops;
    }
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        if ( len1 > 6*len2 || len2 > 6*len1) return -1;
        
        int sum1 = 0 , sum2 = 0;
        for (auto& n : nums1) sum1 += n;
        for (auto& n : nums2) sum2 += n;
        
        if (sum1 > sum2) {
            swap(sum1, sum2);
            swap(nums1, nums2);
        }
        int gaps = sum2 - sum1;
        if (gaps == 0) return 0;
        return minOpsByCnt2(gaps, nums1, nums2); //104ms
        return minOpsByCnt1(gaps, nums1, nums2); //108ms
        return minOpsBySort(gaps, nums1, nums2); //140ms
    }
};
