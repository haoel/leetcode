// Source : https://leetcode.com/problems/calculate-money-in-leetcode-bank/
// Author : Hao Chen
// Date   : 2021-03-28

/***************************************************************************************************** 
 *
 * Hercy wants to save money for his first car. He puts money in the Leetcode bank every day.
 * 
 * He starts by putting in $1 on Monday, the first day. Every day from Tuesday to Sunday, he will put 
 * in $1 more than the day before. On every subsequent Monday, he will put in $1 more than the 
 * previous Monday. 
 * 
 * Given n, return the total amount of money he will have in the Leetcode bank at the end of the n^th 
 * day.
 * 
 * Example 1:
 * 
 * Input: n = 4
 * Output: 10
 * Explanation: After the 4^th day, the total is 1 + 2 + 3 + 4 = 10.
 * 
 * Example 2:
 * 
 * Input: n = 10
 * Output: 37
 * Explanation: After the 10^th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4) = 37. 
 * Notice that on the 2^nd Monday, Hercy only puts in $2.
 * 
 * Example 3:
 * 
 * Input: n = 20
 * Output: 96
 * Explanation: After the 20^th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4 + 5 + 6 + 7 
 * + 8) + (3 + 4 + 5 + 6 + 7 + 8) = 96.
 * 
 * Constraints:
 * 
 * 	1 <= n <= 1000
 ******************************************************************************************************/

class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;
        
        int m = 1 + 2 + 3 + 4 + 5 + 6 + 7;
        // we know
        //     week1 = 0*7 + m
        //     week2 = 1*7 + m 
        //     week3 = 2*7 + m 
        //     weekn = (n-1)*7 + m
        // So, 
        //     week1 + week2 + week3 + ....+ weekn 
        //   = n*m + 7*(0+1+2+..n-1)
        //   = n*m + 7*(n-1)*n/2
        
        int money = weeks*m + 7 * (weeks-1) * weeks / 2;
        
        // for the rest days
        // every day needs to add  previous `weeks * 1`, it is  days* weeks
        // then add from 1 to days
        money += (days*weeks + days*(days+1)/2);
        
        return money;
    }
};
