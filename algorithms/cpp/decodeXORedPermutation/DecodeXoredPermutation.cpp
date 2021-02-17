// Source : https://leetcode.com/problems/decode-xored-permutation/
// Author : Hao Chen
// Date   : 2021-02-17

/***************************************************************************************************** 
 *
 * There is an integer array perm that is a permutation of the first n positive integers, where n is 
 * always odd.
 * 
 * It was encoded into another integer array encoded of length n - 1, such that encoded[i] = perm[i] 
 * XOR perm[i + 1]. For example, if perm = [1,3,2], then encoded = [2,1].
 * 
 * Given the encoded array, return the original array perm. It is guaranteed that the answer exists 
 * and is unique.
 * 
 * Example 1:
 * 
 * Input: encoded = [3,1]
 * Output: [1,2,3]
 * Explanation: If perm = [1,2,3], then encoded = [1 XOR 2,2 XOR 3] = [3,1]
 * 
 * Example 2:
 * 
 * Input: encoded = [6,5,4,6]
 * Output: [2,4,1,5,3]
 * 
 * Constraints:
 * 
 * 	3 <= n < 105
 * 	n is odd.
 * 	encoded.length == n - 1
 ******************************************************************************************************/

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        
        // f(n)  = 1^2^3^4^5 .... ^n ( n is odd number)
        // then, 
        //   f(3) = 1
        //   f(5) = 0
        //   f(7) = 1
        //   f(9) = 0
        //   ... ...
        // f(n) = [ (n-1)/2 + 1 ] % 2
        int nxor = (encoded.size() / 2 + 1) % 2 ;
        
        // suppose the a[1], a[2], a[3] .... a[n] is the result array.
        // xor the odd index of encoded[] array,
        //    encoded[1] = a[2] ^ a[3];
        //    encoded[3] = a[4] ^ a[5];
        //    encode [5] = a[6] ^ a[7];
        //    ......
        // we can get:  f(m) = a[2] ^ a[3] ^ a[4] ...a[n] 
        int mxor = encoded[1];
        for (int i=3; i< encoded.size(); i+=2) {
            mxor ^= encoded[i];
        }
        
        // a[1] = f(n) ^ f(m) 
        x = nxor ^ mxor;
        
        vector<int> result;
        result.push_back(x);
        
        // we know, encoded[i] = a[i] ^ a[i+1]
        // so, a[i+1] = a[i] ^ encoded[i]
        for (int i=0; i< encoded.size(); i++) {
            x = x ^ encoded[i];
            result.push_back(x);
        }
        
        return result;
    }
};
