// Source : https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/
// Inspired by : http://www.jiuzhang.com/solutions/binary-tree-maximum-path-sum/
// Author : Lei Cao
// Date   : 2015-10-08

/**********************************************************************************
 *
 * Given a binary tree, find the maximum path sum.
 *
 * For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections.
 * The path does not need to go through the root.
 *
 *
 *
 * For example:
 * Given the below binary tree,
 *
 *        1
 *       / \
 *      2   3
 *
 * Return 6.
 *
 *
 **********************************************************************************/

package binaryTreeMaximumPathSum;

import java.util.Arrays;
import java.util.Collections;

/**
 * Definition of TreeNode:
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left, right;
 *     public TreeNode(int val) {
 *         this.val = val;
 *         this.left = this.right = null;
 *     }
 * }
 */
public class binaryTreeMaximumPathSum {
    /**
     * @param root: The root of binary tree.
     * @return: An integer.
     */
    public int maxPathSum(TreeNode root) {
        Result r = helper(root);
        return r.sumToLeaf;
    }

    private class Result {
        int sumToRoot = 0;
        int sumToLeaf = 0;
        Result(int sumToRoot, int sumToLeaf) {
            this.sumToRoot = sumToRoot;
            this.sumToLeaf = sumToLeaf;
        }
    }

    // [9,6,-3,null,null,-6,2,null,null,2,null,-6,-6,-6]
    private Result helper(TreeNode root) {
        if (root == null) {
            return new Result(0, Integer.MIN_VALUE);
        }

        if (root.left == null && root.right == null) {
            return new Result(root.val, root.val);
        }

        Result left = helper(root.left);
        Result right = helper(root.right);

        // @todo refactor the logic below
        int sumToRoot = root.val;
        int sumsOfSTR = Math.max(left.sumToRoot, right.sumToRoot);
        if (sumsOfSTR > 0) {
            sumToRoot = root.val + sumsOfSTR;
        }


        int sumOfTree = root.val + left.sumToRoot + right.sumToRoot;
        int sumToLeft = root.val + left.sumToRoot;
        int sumToRight = root.val + right.sumToRoot;

        int max1 = Math.max(root.val, sumOfTree);
        int max2 = Math.max(sumToLeft, sumToRight);
        int max3 = Math.max(left.sumToLeaf, right.sumToLeaf);
        int max4 = Math.max(max1, max2);
        int max = Math.max(max3, max4);

        return new Result(sumToRoot, max);
    }
}
