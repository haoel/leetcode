// Source : https://leetcode.com/problems/excel-sheet-column-number/
// Author : Diego Ruiz Piqueras (Pikeras72)
// Date   : 24-04-2022

/***************************************************************************************************** 
 * Given a string columnTitle that represents the column title as appear in an
 * Excel sheet, return its corresponding column number.
 * 
 * For example:
 * A -> 1
 * B -> 2
 * C -> 3
 * ...
 * Z -> 26
 * AA -> 27
 * AB -> 28 
 * ...
 * 
 * Example 1:
 * 
 * Input: columnTitle = "A"
 * Output: 1
 * 
 * Example 2:
 *
 * Input: columnTitle = "AB"
 * Output: 28
 * Explanation: 
 * 
 * Example 3:
 * 
 * Input: columnTitle = "ZY"
 * Output: 701
 * 
 *  1 <= columnTitle.length <= 7
 *  columnTitle consists only of uppercase English letters.
 * columnTitle is in the range ["A", "FXSHRXW"].
 * 
 * Explanation of the solution:
 * 
 * 1. While we have given less candies than the ones we had at the beginning (while(total < candies){...})
 * 
 * 2. Use count % num_people == 0 to determine the current index of the people.
 ******************************************************************************************************/

class Solution {
    public int titleToNumber(String columnTitle) {
        int res = 0, cnt = 0;
        String letras = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int exponente = columnTitle.length()-1;
        if(exponente == 0){
            return letras.indexOf(columnTitle)+1;
        }
        while(exponente != -1){
            res += (int) ((letras.indexOf(String.valueOf(columnTitle.charAt(cnt)))+1)*Math.pow(26, exponente));
            exponente--;
            cnt++;
        }
        return res;
    }
}
