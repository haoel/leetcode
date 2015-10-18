// Source : https://oj.leetcode.com/problems/subsets/
// Inspired by : http://www.jiuzhang.com/solutions/subsets/
// Author : Lei Cao
// Date   : 2015-10-02

/**********************************************************************************
 *
 * Given a set of distinct integers, S, return all possible subsets.
 *
 * Note:
 *
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 *
 * For example,
 * If S = [1,2,3], a solution is:
 *
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 *
 *
 **********************************************************************************/

package subsets;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class subsets {
    /**
     * Leetcode version
     * @param nums
     * @return
     */
    public List<List<Integer>> subsets(int [] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if (nums == null || nums.length == 0) {
            return result;
        }
        ArrayList<Integer> list = new ArrayList<Integer>();
        Arrays.sort(nums);
        addSubset(result, list, nums, 0);
        return result;
    }

    private void addSubset(List<List<Integer>> result, ArrayList<Integer> list, int[] nums, int pos) {
        result.add(new ArrayList<Integer>(list));
        for (int i = pos; i < nums.length; i++) {
            list.add(nums[i]);
            addSubset(result, list, nums, i + 1);
            list.remove(list.size()-1);
        }
    }

    /**
     * Lintcode version
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    public ArrayList<ArrayList<Integer>> subsets(ArrayList<Integer> s) {
        // write your code here
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        if (s == null || s.size() == 0) {
            return result;
        }
        ArrayList<Integer> list = new ArrayList<Integer>();
        Collections.sort(s);
        addSubset(s, result, list, 0);
        return result;
    }

    private void addSubset(
            ArrayList<Integer> s,
            ArrayList<ArrayList<Integer>> result,
            ArrayList<Integer> list,
            int pos) {
        result.add(new ArrayList<Integer>(list));
        for (int i = pos; i < s.size(); i++) {
            list.add(s.get(i));
            addSubset(s, result, list, i + 1);
            list.remove(list.size() - 1);
        }
    }
}
