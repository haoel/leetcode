// Source : https://leetcode.com/problems/combination-sum-iv/
// Author : Calinescu Valentin
// Date   : 2016-08-07

/*************************************************************************************** 
 *
 * Given an integer array with all positive numbers and no duplicates, find the number
 * of possible combinations that add up to a positive integer target.
 * 
 * Example:
 * 
 * nums = [1, 2, 3]
 * target = 4
 * 
 * The possible combination ways are:
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 * 
 * Note that different sequences are counted as different combinations.
 * 
 * Therefore the output is 7.
 * Follow up:
 * What if negative numbers are allowed in the given array?
 * How does it change the problem?
 * What limitation we need to add to the question to allow negative numbers?
 * 
 ***************************************************************************************/
 
 /* Solution
  * --------
  * 1) Dynamic Programming - O(N *  target)
  *
  * We notice that any sum S can be written as S_prev + nums[i], where S_prev is a sum of
  * elements from nums and nums[i] is one element of the array. S_prev is always smaller 
  * than S so we can create the array sol, where sol[i] is the number of ways one can 
  * arrange the elements of the array to obtain sum i, and populate it from 1 to target,
  * as the solution for i is made up of previously computed ones for numbers smaller than
  * i. The final answer is sol[target], which is returned at the end.
  *
  * Follow up:
  * 
  * If the array contains negative numbers as well as positive ones we can run into a cycle
  * where some subset of the elements have sum 0 so they can always be added to an existing
  * sum, leading to an infinite number of solutions. The limitation that we need is a rule
  * to be followed by the input data, that which doesn't allow this type of subsets to exist.
  */
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int sol[target + 1];
        sol[0] = 1;//starting point, only 1 way to obtain 0, that is to have 0 elements
        for(int i = 1; i <= target; i++)
        {
            sol[i] = 0;
            for(int j = 0; j < nums.size(); j++)
            {
                if(i >= nums[j])//if there is a previously calculated sum to add nums[j] to
                    sol[i] += sol[i - nums[j]];
            }
        }
        return sol[target];
    }
};
