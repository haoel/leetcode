// Source : https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/
// Author : Hao Chen
// Date   : 2021-05-03

/***************************************************************************************************** 
 *
 * You are given a string num, representing a large integer, and an integer k.
 * 
 * We call some integer wonderful if it is a permutation of the digits in num and is greater in value 
 * than num. There can be many wonderful integers. However, we only care about the smallest-valued 
 * ones.
 * 
 * 	For example, when num = "5489355142":
 * 
 * 		The 1^st smallest wonderful integer is "5489355214".
 * 		The 2^nd smallest wonderful integer is "5489355241".
 * 		The 3^rd smallest wonderful integer is "5489355412".
 * 		The 4^th smallest wonderful integer is "5489355421".
 * 
 * Return the minimum number of adjacent digit swaps that needs to be applied to num to reach the k^th 
 * smallest wonderful integer.
 * 
 * The tests are generated in such a way that k^th smallest wonderful integer exists.
 * 
 * Example 1:
 * 
 * Input: num = "5489355142", k = 4
 * Output: 2
 * Explanation: The 4^th smallest wonderful number is "5489355421". To get this number:
 * - Swap index 7 with index 8: "5489355142" -> "5489355412"
 * - Swap index 8 with index 9: "5489355412" -> "5489355421"
 * 
 * Example 2:
 * 
 * Input: num = "11112", k = 4
 * Output: 4
 * Explanation: The 4^th smallest wonderful number is "21111". To get this number:
 * - Swap index 3 with index 4: "11112" -> "11121"
 * - Swap index 2 with index 3: "11121" -> "11211"
 * - Swap index 1 with index 2: "11211" -> "12111"
 * - Swap index 0 with index 1: "12111" -> "21111"
 * 
 * Example 3:
 * 
 * Input: num = "00123", k = 1
 * Output: 1
 * Explanation: The 1^st smallest wonderful number is "00132". To get this number:
 * - Swap index 3 with index 4: "00123" -> "00132"
 * 
 * Constraints:
 * 
 * 	2 <= num.length <= 1000
 * 	1 <= k <= 1000
 * 	num only consists of digits.
 ******************************************************************************************************/

class Solution {
private:
    // Refer to:
    // https://leetcode.com/problems/next-permutation/solution/
    void nextPermutation(string& num) {
        int i = num.size() - 2;
        while (i >= 0 && num[i + 1] <= num[i]) {
            i--;
        }
        if (i >= 0) {
            int j = num.size() - 1;
            while (j >= 0 && num[j] <= num[i]) {
                j--;
            }
            swap(num[i], num[j]);
        }
        reverse(num, i + 1);
    }

    void reverse(string& num, int start) {
        int i = start, j = num.size() - 1;
        while (i < j) {
            swap(num[i], num[j]);
            i++;
            j--;
        }
    }


public:
    int getMinSwaps(string num, int k) {
        string pnum = num;
        while(k--) {
            nextPermutation(pnum);
        }
        //cout << num << endl << pnum << endl;
        int result = 0;
        for(int i = 0; i < num.size(); i++) {
            if (num[i] == pnum[i]) continue;
            for(int j = i + 1; j < num.size(); j++) {
                if(num[i] != pnum[j]) continue;
                //cout << "j=" << j << ", i=" << i << endl;
                result += j - i;
                
                //shift the string
                char c = pnum[j];
                for (int k = j; k > i; k--) {
                    pnum[k] = pnum[k-1];
                }
                pnum[i] = c;
                //cout << pnum << endl;
                break;
            }
        }
        //cout << endl;
        return result;
    }
};
