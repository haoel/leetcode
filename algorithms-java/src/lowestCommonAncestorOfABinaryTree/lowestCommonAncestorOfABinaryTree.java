// Source : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Inspired by : http://www.jiuzhang.com/solutions/lowest-common-ancestor/
// Author : Lei Cao
// Date   : 2015-10-07

/**********************************************************************************
 *
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the
 * tree.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor is
 * defined between two nodes v and w as the lowest node in T that has both v and w as
 * descendants (where we allow a node to be a descendant of itself).”
 *
 *         _______3______
 *        /              \
 *     ___5__          ___1__
 *    /      \        /      \
 *    6      _2       0       8
 *          /  \
 *          7   4
 *
 * For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example
 * is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according
 * to the LCA definition.
 *
 *
 *
 **********************************************************************************/

package lowestCommonAncestorOfABinaryTree;

import java.util.ArrayList;
import java.util.Arrays;

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
public class lowestCommonAncestorOfABinaryTree {
    /**
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode A, TreeNode B) {
        if (root == null || root == A || root == B) {
            return root;
        }
        TreeNode left = lowestCommonAncestor(root.left, A, B);
        TreeNode right = lowestCommonAncestor(root.right, A, B);
        if (left != null && right != null) {
            return root;
        }

        if (left != null) {
            return left;
        }

        if (right != null) {
            return right;
        }
        return null;
    }
}



