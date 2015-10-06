// Source : https://oj.leetcode.com/problems/validate-binary-search-tree/
// Author : Lei Cao
// Date   : 2015-10-06

/**********************************************************************************
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 * confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
 *
 * OJ's Binary Tree Serialization:
 *
 * The serialization of a binary tree follows a level order traversal, where '#' signifies
 * a path terminator where no node exists below.
 *
 * Here's an example:
 *
 *    1
 *   / \
 *  2   3
 *     /
 *    4
 *     \
 *      5
 *
 * The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
 *
 *
 **********************************************************************************/

package validateBinarySearchTree;

public class validateBinarySearchTree {
    // Traversal
    private int lastValue = 0; // the value of it doesn't matter.
    private boolean firstNode = true;
    public boolean isValidBST(TreeNode root) {
        if (root == null) {
            return true;
        }

        if (!isValidBST(root.left)) {
            return false;
        }

        if (!firstNode && lastValue >= root.val) {
            return false;
        }

        firstNode = false;
        lastValue = root.val;

        if (!isValidBST(root.right)) {
            return false;
        }

        return true;

    }
}
