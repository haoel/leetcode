// Source : https://leetcode.com/problems/additive-number/
// Author : Hao Chen
// Date   : 2015-11-22

/*************************************************************************************** 
 *
 * Additive number is a positive integer whose digits can form additive sequence.
 * 
 * A valid additive sequence should contain at least three numbers. Except for the 
 * first two numbers, each subsequent number in the sequence must be the sum of the 
 * preceding two.
 * 
 * For example:
 * "112358" is an additive number because the digits can form an additive sequence: 1, 
 * 1, 2, 3, 5, 8.
 * 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
 * "199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
 * 1 + 99 = 100, 99 + 100 = 199
 * 
 * Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 
 * 03 or 1, 02, 3 is invalid.
 * 
 * Given a string represents an integer, write a function to determine if it's an 
 * additive number.
 * 
 * Follow up:
 * How would you handle overflow for very large input integers?
 * 
 * Credits:Special thanks to @jeantimex for adding this problem and creating all test 
 * cases.
 *               
 ***************************************************************************************/


class Solution {
public:
    bool isAdditiveNumber(string num) {
        int len = num.size();
        
        for(int i=1; i<len/2+1; i++) {
            string n1 = num.substr(0, i);
            if ( n1.size()>1 && n1[0] == '0') break;
            for(int j=i+1; j<len; j++) {
                string n2 = num.substr(i, j-i);
                if ( n2.size()>1 && n2[0] == '0') break;
                string n3 = num.substr(j);
                if (isAdditiveNumberHelper(n1, n2, n3)) return true;
            }
        }
        return false;
    }
    
private:
    bool isAdditiveNumberHelper(string& n1, string& n2, string& n3){
        string add = StringAdd(n1, n2);
        
        if (add.size() > n3.size()) return false;
        
        if (add == n3 ) return true;
        
        //split the n3 to 2 parts, and keep going.
        string cut = n3.substr(0, add.size());
        if (add == cut) {
            string rest = n3.substr(add.size());
            return isAdditiveNumberHelper(n2, add, rest);
        }
        return false;
    }


    string StringAdd(string n1, string n2) {
        
        if (n1.size() < n2.size()) {
            string tmp = n1;
            n1 = n2;
            n2 = tmp;
        }
        
        int carry=0;
        string result;
        for (int i=n1.size()-1, j=n2.size()-1; i>=0; i--, j--) {

            int n = n1[i] - '0' + carry;
            if ( j >= 0) {
                n += n2[j] - '0';
            } 
            char ch = n % 10 + '0';
            carry = n/10;
            result = ch + result;
        }
        if (carry>0) result = (char)(carry+'0') + result;
        return result;
        
    }
};
