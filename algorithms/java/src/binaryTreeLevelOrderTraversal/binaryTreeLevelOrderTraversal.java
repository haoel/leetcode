// Source : https://oj.leetcode.com/problems/binary-tree-level-order-traversal/
// Inspired by : http://www.jiuzhang.com/solutions/binary-tree-level-order-traversal/
// Author : Lei Cao
// Date   : 2015-10-08

/**********************************************************************************
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 *
 * return its level order traversal as:
 *
 * [
 *   [3],
 *   [9,20],
 *   [15,7]
 * ]
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

package binaryTreeLevelOrderTraversal;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class binaryTreeLevelOrderTraversal {
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> results = new ArrayList<>();
        if (root == null) {
            return results;
        }

        ArrayList<Integer> values = new ArrayList<Integer>();
        Queue<TreeNode> q = new LinkedList<>();

        q.offer(root);
        q.offer(null);

        while (q.size() > 0) {
            TreeNode node = q.poll();
            // null node used as a separator of every level
            if (node == null) {
                results.add(new ArrayList<>(values));
                values.clear();
                if (q.size() == 0) {
                    break;
                }
                q.offer(null);
                continue;
            }
            values.add(node.val);
            if (node.left != null) {
                q.offer(node.left);
            }
            if (node.right != null) {
                q.offer(node.right);
            }
        }

        return results;
    }
}
