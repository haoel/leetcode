// Source : https://leetcode.com/problems/wiggle-subsequence/
// Author : Calinescu Valentin
// Date   : 2016-08-08

/*************************************************************************************** 
 *
 * A sequence of numbers is called a wiggle sequence if the differences between
 * successive numbers strictly alternate between positive and negative. The first
 * difference (if one exists) may be either positive or negative. A sequence with fewer
 * than two elements is trivially a wiggle sequence.
 * 
 * For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3)
 * are alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are
 * not wiggle sequences, the first because its first two differences are positive and
 * the second because its last difference is zero.
 * 
 * Given a sequence of integers, return the length of the longest subsequence that is a
 * wiggle sequence. A subsequence is obtained by deleting some number of elements
 * (eventually, also zero) from the original sequence, leaving the remaining elements in
 * their original order.
 * 
 * Examples:
 * Input: [1,7,4,9,2,5]
 * Output: 6
 * The entire sequence is a wiggle sequence.
 * 
 * Input: [1,17,5,10,13,15,10,5,16,8]
 * Output: 7
 * There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].
 * 
 * Input: [1,2,3,4,5,6,7,8,9]
 * Output: 2
 * 
 * Follow up:
 * Can you do it in O(n) time?
 * 
 ***************************************************************************************/
 
 /* Solution
  * --------
  * 1) O(N)
  * 
  * We notice that adding a new number to an existing subsequence means finding one that
  * is smaller or bigger than the previous number, according to the difference between the
  * previous number and the number before that as we always need to alternate between increasing
  * and decreasing subsequences. If we encounter increasing or decreasing sequences of 2 or 
  * more consecutive numbers we can treat the entire subsequence as a number, because that way 
  * we can always be sure we don't miss any solution, as finding a number smaller than any 
  * number of an increasing subsequence is guaranteed to be smaller than the biggest number 
  * in the subsequence. Thus, we can only check the difference between consecutive numbers.
  * 
  * Follow up:
  * 
  * The time complexity is already O(N).
  */
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int solution = 0;//if we have an empty vector the solution is 0
        if(nums.size())
        {
            solution = 1;
            int bigger = 0;//0 is the starting point to be followed by either an increasing or decreasing sequence
            for(int i = 1; i < nums.size(); i++)
            {
                if(nums[i] == nums[i - 1])
                    continue;//we can ignore duplicates as they can always be omitted
                else if(nums[i] > nums[i - 1])
                {
                    if(bigger == 0 || bigger == 2)
                    {
                        bigger = 1;//1 means we now have an increasing sequence
                        solution++;
                    }
                }
                else //if(nums[i] < nums[i - 1])
                {
                    if(bigger == 0 || bigger == 1)
                    {
                        bigger = 2;//2 means we now have a decreasing sequence
                        solution++;
                    }
                }
            }
        }
        return solution;
    }
};
