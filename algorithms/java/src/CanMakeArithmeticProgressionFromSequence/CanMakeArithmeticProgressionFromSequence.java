// Source : https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
// Author : Diego Ruiz Piqueras (Pikeras72)
// Date   : 24-04-2022

/***************************************************************************************************** 
 *
 * A sequence of numbers is called an arithmetic progression if the 
 * difference between any two consecutive elements is the same.
 * 
 * Given an array of numbers arr, return true if the array can be 
 * rearranged to form an arithmetic progression. Otherwise, return false.
 * 
 * Example 1:
 * 
 * Input: arr = [3,5,1]
 * Output: true
 * Explanation: We can reorder the elements as [1,3,5] or [5,3,1] 
 * with differences 2 and -2 respectively, between each consecutive elements.
 * 
 * Example 2:
 *
 * Input: arr = [1,2,4]
 * Output: false
 * Explanation: There is no way to reorder the elements to obtain an arithmetic progression.
 * 
 * Constraints:
 * 
 *  2 <= arr.length <= 1000
 *  -10^6 <= arr[i] <= 10^6
 * 
 * Explanation of the solution:
 * 
 * 1. We sort the array 'arr' to check the distance between the first two numbers.
 * 
 * 2. We analyze the array looking if all the numbers have the exact same distance
 *    between them compared to the two first numbers.
 ******************************************************************************************************/

class Solution {
    public boolean canMakeArithmeticProgression(int[] arr) {
        int dis, disBase = 0;
        boolean yes = true;
        Arrays.sort(arr);
        for(int i = 0; i < arr.length-1; i++){
            if(i == 0){
                disBase = arr[i+1]-arr[i];
            }else{
                dis = arr[i+1]-arr[i];
                if(dis != disBase){
                    yes = false;
                    break;
                }
            }
        }
        return yes;
    }
}
