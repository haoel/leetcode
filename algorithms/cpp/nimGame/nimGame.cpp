// Source : https://leetcode.com/problems/nim-game/
// Author : Calinescu Valentin
// Date   : 2015-10-19

/*************************************************************************************** 
 *
 * You are playing the following Nim Game with your friend: There is a heap of stones 
 * on the table, each time one of you take turns to remove 1 to 3 stones. The one who 
 * removes the last stone will be the winner. You will take the first turn to remove 
 * the stones.
 * 
 * Both of you are very clever and have optimal strategies for the game. Write a 
 * function to determine whether you can win the game given the number of stones in the 
 * heap.
 * 
 * For example, if there are 4 stones in the heap, then you will never win the game: no 
 * matter 1, 2, or 3 stones you remove, the last stone will always be removed by your 
 * friend.
 * 
 *   If there are 5 stones in the heap, could you figure out a way to remove the stones 
 * such that you will always be the winner? 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating 
 * all test cases.
 *               
 ***************************************************************************************/



/* 
 * Solutions
 * =========
 *
 * Let's look at the example:
 * 
 *    0 stones - false
 *    1 stone - true
 *    2 stones - true
 *    3 stones - true
 *    4 stones - false
 * 
 * We notice that all we need for a position to be true is to get the opponent in a position 
 * that is false. With 1, 2 and 3 you can take 1, 2 and 3 stones respectively to force your 
 * opponent into having 0 stones, a position where he cannot win. No matter how many stones 
 * we take from 4 we cannot 
 *
 * force the opponent into a losing positon, so position 4 becomes a losing position. 
 * Let's take a look at the next 4 positions:
 * 
 *     5 stones - true
 *     6 stones - true
 *     7 stones - true
 *     8 stones - false
 * 
 * With 5, 6 and 7 stones we can take 1, 2 and 3 stones respectively to force the opponent into 
 * position 4. Position 8 is a losing one because we can only force the opponent into winning 
 * positions. We notice that this group of 4 positions can repeat itself indefinitely, because 
 * we only need the previous 3 positions to judge whether a position is winning or losing. 
 *
 * Thus we can see the pattern:
 * 
 *     n % 4 == 0 - false
 *     n % 4 != 0 - true
 * 
 */

class Solution {
public:
    bool canWinNim(int n) {
        return !(n % 4 == 0);
    }
};
