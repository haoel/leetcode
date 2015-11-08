// Source : https://leetcode.com/problems/h-index-ii/
// Author : Hao Chen
// Date   : 2015-11-08

/*************************************************************************************** 
 *
 * Follow up for H-Index: What if the citations array is sorted in ascending order?
 * Could you optimize your algorithm?
 *               
 ***************************************************************************************/



class Solution {
public:
    // binary search - O(log(n))
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0, high = n-1;
        
        while( low <= high ) {
            int mid = low + (high-low)/2;
            if (citations[mid] == n - mid) {
                return n - mid;
            }else if (citations[mid] > n-mid){
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }
        return n-low;
    }
};
