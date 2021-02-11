// Source : https://leetcode.com/problems/maximum-score-from-removing-stones/
// Author : Hao Chen
// Date   : 2021-02-11

/***************************************************************************************************** 
 *
 * You are playing a solitaire game with three piles of stones of sizes a​​​​​​, b,​​​​​​ and c​​​​​​ 
 * respectively. Each turn you choose two different non-empty piles, take one stone from each, and add 
 * 1 point to your score. The game stops when there are fewer than two non-empty piles (meaning there 
 * are no more available moves).
 * 
 * Given three integers a​​​​​, b,​​​​​ and c​​​​​, return the maximum score you can get.
 * 
 * Example 1:
 * 
 * Input: a = 2, b = 4, c = 6
 * Output: 6
 * Explanation: The starting state is (2, 4, 6). One optimal set of moves is:
 * - Take from 1st and 3rd piles, state is now (1, 4, 5)
 * - Take from 1st and 3rd piles, state is now (0, 4, 4)
 * - Take from 2nd and 3rd piles, state is now (0, 3, 3)
 * - Take from 2nd and 3rd piles, state is now (0, 2, 2)
 * - Take from 2nd and 3rd piles, state is now (0, 1, 1)
 * - Take from 2nd and 3rd piles, state is now (0, 0, 0)
 * There are fewer than two non-empty piles, so the game ends. Total: 6 points.
 * 
 * Example 2:
 * 
 * Input: a = 4, b = 4, c = 6
 * Output: 7
 * Explanation: The starting state is (4, 4, 6). One optimal set of moves is:
 * - Take from 1st and 2nd piles, state is now (3, 3, 6)
 * - Take from 1st and 3rd piles, state is now (2, 3, 5)
 * - Take from 1st and 3rd piles, state is now (1, 3, 4)
 * - Take from 1st and 3rd piles, state is now (0, 3, 3)
 * - Take from 2nd and 3rd piles, state is now (0, 2, 2)
 * - Take from 2nd and 3rd piles, state is now (0, 1, 1)
 * - Take from 2nd and 3rd piles, state is now (0, 0, 0)
 * There are fewer than two non-empty piles, so the game ends. Total: 7 points.
 * 
 * Example 3:
 * 
 * Input: a = 1, b = 8, c = 8
 * Output: 8
 * Explanation: One optimal set of moves is to take from the 2nd and 3rd piles for 8 turns until they 
 * are empty.
 * After that, there are fewer than two non-empty piles, so the game ends.
 * 
 * Constraints:
 * 
 * 	1 <= a, b, c <= 105
 ******************************************************************************************************/


class Solution {
private:
    bool can_move(int a, int b, int c) {
        int cnt = 0 ;
        if ( a > 0 ) cnt++;
        if ( b > 0 ) cnt++;
        if ( c > 0 ) cnt++;
        return cnt >= 2;
    }

    void swap(int& x, int& y){
        int t = x;
        x = y;
        y = t;
    }

    void sort(int& a, int& b, int& c) {

        if (a < b) swap(a, b);
        if (b < c) swap(b, c);
        if (a < b) swap(a, b);

    }
public:
    int maximumScore(int a, int b, int c) {
        return maximumScore_math(a, b, c); //0
        return maximumScore_loop(a, b, c); //20ms
    }
    int maximumScore_loop(int a, int b, int c) {
        //the optimal way it always remove one stone from the biggest 2 piles
        int score = 0;
        while ( can_move(a, b ,c) ) {
            score++;
            sort(a, b ,c);
             a--; b--;
        }
        return score;

    }

    int maximumScore_math(int a, int b, int c) {
        // sort a > b > c
        sort(a, b, c);

        // if `a` is large enough which always has stone for `b` and `c`
        if ( b+c <= a ) return b+c;

        //if b+c > a, which means we always can find two stones, so the score is (a+b+c)/2
        return (a+b+c)/2;

    }
};
