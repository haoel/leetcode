// Source : https://oj.leetcode.com/problems/maximum-depth-of-binary-tree/
// Inspired by : http://www.jiuzhang.com/solutions/maximum-depth-of-binary-tree/
// Author : Lei Cao
// Date   : 2015-10-03

/**********************************************************************************
 *
 * Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path from the root node
 * down to the farthest leaf node.
 *
 **********************************************************************************/


package maximumDepthOfBinaryTree;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class maximumDepthOfBinaryTree {
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return theDepth(root);
    }

    private int theDepth(TreeNode root) {
        int leftDepth = 1;
        int rightDepth = 1;

        if (root.left != null) {
           leftDepth = theDepth(root.left) + 1;
        }
        if (root.right != null) {
            rightDepth = theDepth(root.right) + 1;
        }
        return Math.max(leftDepth, rightDepth);
    }
}
