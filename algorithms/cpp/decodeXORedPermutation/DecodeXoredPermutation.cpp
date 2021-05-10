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
/*
    XOR Basic Rules
    ---------------
    At first, we need understand the following XOR rules

    x^x = 0
    0^x = x
    with the rule 1 and 2 , we can have: x^x^y = y . the element ocurrs twice would be removed.
    if x^y = z , then x = y^z and y = x^z
   
    XOR from 1 to n
    ---------------
    Secondly, suppose the f(n) is XOR from 1 to n , f(n) = 1^2^3^4^5 .... ^n .
    if the n is odd number, then we can observse the following things:

    f(1) = 1
    f(3) = 1^2^3 = 0
    f(5) = 1^2^3^4^5 = 1
    f(7) = 1^2^3^4^5^6^7 = 0
    f(9) = 1^2^3^4^5^6^7^8^9 = 1
    ... ...
    so, f(n) = [ (n-1)/2 + 1 ] % 2 - (n is odd number)

    Solution
    --------
    We know,
    encode = { (p1^p2), (p2^p3), (p3^p4), ... } - p is the permutation array

    so, if xor the odd index of encoded[] array,

    encoded[1] = p2 ^ p3;
    encoded[3] = p4 ^ p5;
    encoded[5] = p6 ^ p7;
    ......
    we can get: f(m) = p2 ^ p3 ^ p4 ...pn, without the p1

    with the XOR rule 3, we know

    p1 = f(n) ^ f(m)

    with the XOR rule 4, we know encoded[0] = p1^p2 then
    p2 = p1 ^ enclode[0]

    So,

    p[i+1] = p[i] ^ enclode[i]
*/
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
