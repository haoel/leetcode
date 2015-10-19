// Source : https://leetcode.com/problems/first-bad-version/
// Author : Hao Chen
// Date   : 2015-10-19

/*************************************************************************************** 
 *
 * You are a product manager and currently leading a team to develop a new product. 
 * Unfortunately, the latest version of your product fails the quality check. Since 
 * each version is developed based on the previous version, all the versions after a 
 * bad version are also bad. 
 * 
 * Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad 
 * one, which causes all the following ones to be bad.
 * 
 * You are given an API bool isBadVersion(version) which will return whether version is 
 * bad. Implement a function to find the first bad version. You should minimize the 
 * number of calls to the API.
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating 
 * all test cases.
 *               
 ***************************************************************************************/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    //Binary search
    int firstBadVersion(int n) {
        int low=1, high=n;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if (isBadVersion(mid) && !isBadVersion(mid-1)){
                return mid;
            }
            if (isBadVersion(mid)) {
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return -1;
    }
};
