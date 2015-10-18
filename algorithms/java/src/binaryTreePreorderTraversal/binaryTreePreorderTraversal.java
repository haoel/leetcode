// Source : https://oj.leetcode.com/problems/binary-tree-preorder-traversal/
// Inspired by : http://www.jiuzhang.com/solutions/binary-tree-preorder-traversal/
// Author : Lei Cao
// Date   : 2015-10-05

/**********************************************************************************
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *
 *    1
 *     \
 *      2
 *     /
 *    3
 *
 * return [1,2,3].
 *
 * Note: Recursive solution is trivial, could you do it iteratively?
 *
 **********************************************************************************/

package binaryTreePreorderTraversal;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by leicao on 5/10/15.
 */
public class binaryTreePreorderTraversal {

    //Version 1: Traverse
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer>  results = new ArrayList<Integer>();
        traversal(results, root);
        return results;

    }

    private void traversal(List<Integer> results, TreeNode root) {
        if (results == null || root == null) {
            return;
        }
        results.add(root.val);
        traversal(results, root.left);
        traversal(results, root.right);
    }
}
