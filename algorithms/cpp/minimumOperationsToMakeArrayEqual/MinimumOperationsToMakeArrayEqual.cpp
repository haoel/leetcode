// Source : https://leetcode.com/problems/minimum-operations-to-make-array-equal/
// Author : Hao Chen
// Date   : 2020-10-03

/***************************************************************************************************** 
 *
 * You have an array arr of length n where arr[i] = (2 * i) + 1 for all valid values of i (i.e. 0 <= i 
 * < n).
 * 
 * In one operation, you can select two indices x and y where 0 <= x, y < n and subtract 1 from arr[x] 
 * and add 1 to arr[y] (i.e. perform arr[x] -=1 and arr[y] += 1). The goal is to make all the elements 
 * of the array equal. It is guaranteed that all the elements of the array can be made equal using 
 * some operations.
 * 
 * Given an integer n, the length of the array. Return the minimum number of operations needed to make 
 * all the elements of arr equal.
 * 
 * Example 1:
 * 
 * Input: n = 3
 * Output: 2
 * Explanation: arr = [1, 3, 5]
 * First operation choose x = 2 and y = 0, this leads arr to be [2, 3, 4]
 * In the second operation choose x = 2 and y = 0 again, thus arr = [3, 3, 3].
 * 
 * Example 2:
 * 
 * Input: n = 6
 * Output: 9
 * 
 * Constraints:
 * 
 * 	1 <= n <= 10^4
 ******************************************************************************************************/

class Solution {
public:
    int minOperations(int n) {
        // the sum of odd number is : n*n
        // the sum of even number is: n*n+n
        /* int sum = n*n; */

        //calculate the average
        /* int average = sum / n;  //actually it is n  */

        //calculate the different between n and all of the odd number which less than `average`
        //  (n - 1) + (n - 3) + (n - 5) + (n - 7) ...
        // = m*n - (1+3+5+7+...m)   where m = n/2
        // = m*n - m*m
        // = (n/2)*n - (n/2)*(n/2)
        // = n*n/2 - n*n/4
        // = n*n/4

        return n*n/4;
    }
};
