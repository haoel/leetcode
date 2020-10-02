// Source : https://leetcode.com/problems/find-the-winner-of-an-array-game/
// Author : Hao Chen
// Date   : 2020-10-02

/***************************************************************************************************** 
 *
 * Given an integer array arr of distinct integers and an integer k.
 * 
 * A game will be played between the first two elements of the array (i.e. arr[0] and arr[1]). In each 
 * round of the game, we compare arr[0] with arr[1], the larger integer wins and remains at position 0 
 * and the smaller integer moves to the end of the array. The game ends when an integer wins k 
 * consecutive rounds.
 * 
 * Return the integer which will win the game.
 * 
 * It is guaranteed that there will be a winner of the game.
 * 
 * Example 1:
 * 
 * Input: arr = [2,1,3,5,4,6,7], k = 2
 * Output: 5
 * Explanation: Let's see the rounds of the game:
 * Round |       arr       | winner | win_count
 *   1   | [2,1,3,5,4,6,7] | 2      | 1
 *   2   | [2,3,5,4,6,7,1] | 3      | 1
 *   3   | [3,5,4,6,7,1,2] | 5      | 1
 *   4   | [5,4,6,7,1,2,3] | 5      | 2
 * So we can see that 4 rounds will be played and 5 is the winner because it wins 2 consecutive games.
 * 
 * Example 2:
 * 
 * Input: arr = [3,2,1], k = 10
 * Output: 3
 * Explanation: 3 will win the first 10 rounds consecutively.
 * 
 * Example 3:
 * 
 * Input: arr = [1,9,8,2,3,7,6,4,5], k = 7
 * Output: 9
 * 
 * Example 4:
 * 
 * Input: arr = [1,11,22,33,44,55,66,77,88,99], k = 1000000000
 * Output: 99
 * 
 * Constraints:
 * 
 * 	2 <= arr.length <= 10^5
 * 	1 <= arr[i] <= 10^6
 * 	arr contains distinct integers.
 * 	1 <= k <= 10^9
 ******************************************************************************************************/
class Solution {
public:
    int getWinner(vector<int>& arr, int k) { 
        
        int left=0, right=1;
        
        int max = arr[left] > arr[right] ? arr[left] : arr[right];
        int winner; 
        int win_times = 0;
        
        while( right < arr.size())  {

            //if left < right,  the move the `left` to the `right`
            if ( arr[left] < arr[right] ) {
                left = right;
            }
            // move the `right` to next element
            right++;
            //record current round winner.
            int w = arr[left];            
            
            if (w == winner) {
                //if winner is same, count++
                win_times++; 
            }else{
                // if winner is new number, reset the count.
                winner = w;
                win_times = 1;
            }
            
            // if the time of win equal K, return winner. 
            if (win_times >= k) return winner;
            
            // find the max element of this array, if k > arr.size() then return this
            if (max < arr[right]) max = arr[right];
        }
        
        return max;
    }
};
