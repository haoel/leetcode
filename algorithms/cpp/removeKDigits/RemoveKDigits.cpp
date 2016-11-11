// Source : https://leetcode.com/problems/remove-k-digits/
// Author : Hao Chen
// Date   : 2016-11-11

/*************************************************************************************** 
 *
 * Given a non-negative integer num represented as a string, remove k digits from the 
 * number so that the new number is the smallest possible.
 * 
 * Note:
 * 
 * The length of num is less than 10002 and will be ≥ k.
 * The given num does not contain any leading zero.
 * 
 * Example 1:
 * 
 * Input: num = "1432219", k = 3
 * Output: "1219"
 * Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which 
 * is the smallest.
 * 
 * Example 2:
 * 
 * Input: num = "10200", k = 1
 * Output: "200"
 * Explanation: Remove the leading 1 and the number is 200. Note that the output must 
 * not contain leading zeroes.
 * 
 * Example 3:
 * 
 * Input: num = "10", k = 2
 * Output: "0"
 * Explanation: Remove all the digits from the number and it is left with nothing which 
 * is 0.
 ***************************************************************************************/

class Solution {
public:
    string removeKdigits_pick(string& num, int k) {
        
        int len = num.size();
        string result;
        
        int idx = 0;
        for (int i=0; i < len - k; i++) {
            int min_idx = idx;
            for (int j=min_idx; j<=i+k; j++) {
                if (num[min_idx] > num[j])  min_idx = j;
            }
            
            //don't put zero at the beginning
            if ( !(result.empty() && num[min_idx]=='0') ){
                result.push_back(num[min_idx]);
            }
            
            //select the number started from next one, to make the order correctness.
            idx = min_idx + 1;
        }
        
        if (result.empty()) result = "0";
        return result;
    }
    
    string removeKdigits_remove(string& num, int k) {
        if ( num.size() <= k ) return "0";
        int left_len = num.size() - k;
        int idx = 0;
        for (int i=0; i<k ;i++){
            int len = num.size();
            for (int j=0; j<num.size()-1; j++) {
                //if the current is bigger than next one, then revmoe the current one.
                //In other word, we always pick the smaller one number.
                if ( num[j] > num[j+1] ) {
                    num.erase(j, 1);
                    idx = j;
                    break;
                }
            }
        }
        
        //remove all of ZEROs at the beginning.
        for (int i=0; i<= num.size(); i++) {
            if (num[i] != '0' || i == num.size()) {
                num.erase(0, i);
                break;
            }
        }
        
        // if the digits in the array are sorted, 
        // then, we need remove the digits at the ends.
        if (num.size() > left_len ) {
            num.erase(num.begin() + left_len, num.end());
        }
        
        if (num.empty()) num = "0";
        return num;
    }
    
    string removeKdigits(string num, int k) {
        srand(time(0));
        if (rand() % 2 ) {
            return removeKdigits_pick(num, k);
        } else {
            return removeKdigits_remove(num, k);
        }
    }
};
