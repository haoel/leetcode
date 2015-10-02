// Source : https://oj.leetcode.com/problems/implement-strstr/
// Author : Lei Cao
// Date   : 2014-07-19

/**********************************************************************************
 *
 * Implement strStr().
 *
 * Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
 *
 *
 **********************************************************************************/

package strStr;

/**
 * Created by leicao on 2/10/15.
 */
public class strStr {
    public int strStr(String haystack, String needle) {
        if (haystack == null || needle == null) {
            return -1;
        }
        int i, j = 0;
        for (i = 0; i < haystack.length() - needle.length() + 1; i++) {
            for (j = 0; j < needle.length(); j++) {
                if (haystack.charAt(i + j) != needle.charAt(j)) {
                    break;
                }
            }
            if (j == needle.length()) {
                return i;
            }
        }
        return -1;
    }
}
