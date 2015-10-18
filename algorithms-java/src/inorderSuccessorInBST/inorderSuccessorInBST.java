// Source : http://www.lintcode.com/en/problem/inorder-successor-in-bst/
//          https://leetcode.com/problems/inorder-successor-in-bst/
// Inspired by : http://www.jiuzhang.com/solutions/inorder-successor-in-bst/
// Author : Lei Cao
// Date   : 2015-10-06

/**********************************************************************************
 *
 * Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
 *
 * Example
 * Given tree = [2,1] and node = 1:
 *
 *    2
 *   /
 *  1
 * return node 2.
 *
 * Given tree = [2,1,3] and node = 2:
 *
 *    2
 *   / \
 *  1  3
 *
 * return node 3.
 *
 * Note
 * If the given node has no in-order successor in the tree, return null.
 *
 * Challenge
 * O(h), where h is the height of the BST.
 **********************************************************************************/

package inorderSuccessorInBST;

public class inorderSuccessorInBST {
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        TreeNode successor = null;
        if (root == null) {
            return null;
        }
        while (root != null && root.val != p.val) {
            if (root.val > p.val) {
                successor = root;
                root = root.left;
            } else {
                root = root.right;
            }
        }

        if (root == null) {
            return null;
        }

        if (root.right == null) {
            return successor;
        }

        root = root.right;
        while (root.left != null) {
            root = root.left;
        }
        return root;
    }
}
