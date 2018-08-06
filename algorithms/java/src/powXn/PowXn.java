// Source : https://leetcode.com/problems/powx-n/
// Author : Tianming Cao
// Date   : 2018-02-11

/**********************************************************************************
 * 
 * Implement pow(x, n).
 * 
 * Example 1:
 * 
 *  Input: 2.00000, 10
 *  Output: 1024.00000
 *  
 * Example 2:
 * 
 *  Input: 2.10000, 3
 *  Output: 9.26100
 * 
 **********************************************************************************/
package powXn;

public class PowXn {
	
	/**
	 * Divide-and-Conquer method
	 * For example:
	 * 
	 * 3^9=(3^4)^2*3 
	 *     ↓                          
	 * 3^4=(3^2)^2
	 *     ↓
	 * 3^2=3*3
	 *     ↓
	 * 3=3
	 * 
	 * So, both Space and Time are O(logN)
	 */
	public double recursion(double x, long n) {
		if (n == 1) {
			return x;
		}
		//We'd better use unsigned right shift
		double half = recursion(x, n >>> 1);
		if ((n & 1) == 0) {
			return half * half;
		} else {
			return half * half * x;
		}
	}
	
	public double myPow01(double x, int n) {
		if (n == 0 || x == 1) {
			return 1;
		}
		// Avoid being out of bounds, we should cast int to long
		long m = n;
		double result = recursion(x, Math.abs(m));
		if (n > 0) {
			return result;
		} else {
			return 1 / result;
		}
	}
	
	public double myPow02(double x, int n) {
		if (n == 0 || x == 1) {
			return 1;
		}
		// Avoid being out of bounds, we should cast int to long
		long m = n;
		double result = bitFunction(x, Math.abs(m));
		if (n > 0) {
			return result;
		} else {
			return 1 / result;
		}
	}
	
	/**
	 * Solution with bit-manipulation
	 * For example:
	 * 9=1001
	 * 3^9=(3^1)^1*(3^2)^0*(3^4)^0*(3^8)^1
	 * Space is O(1), Time is O(logN)
	 */
	public double bitFunction(double x, long n) {
		double multy = 1;
		double base = x;
		for (long k = n; k >= 1; k >>>= 1) {
			if ((k & 1) > 0) {
				multy = multy * base;
			}
			base *= base;
		}
		return multy;
	}

}
