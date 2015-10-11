// Source : https://oj.leetcode.com/problems/balanced-binary-tree/
// Inspired by : http://www.jiuzhang.com/solutions/binary-search-tree-iterator/
// Author : Lei Cao
// Date   : 2015-10-07

/********************************************************************************** 
 * 
 * Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
 * 
 * Calling next() will return the next smallest number in the BST.
 * 
 * Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree. 
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *               
 **********************************************************************************/

package binarySearchTreeIterator;

import java.util.Stack;

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
 * Example of iterate a tree:
 * Solution iterator = new Solution(root);
 * while (iterator.hasNext()) {
 *    TreeNode node = iterator.next();
 *    do something for node
 * }
 */
public class binarySearchTreeIterator {
    private TreeNode currentNode = null;
    private Stack<TreeNode> stack = new Stack<TreeNode>();
    //@param root: The root of binary tree.
    public binarySearchTreeIterator(TreeNode root) {
        if (root != null) {
            currentNode = root;
        }
    }

    //@return: True if there has next node, or false
    public boolean hasNext() {
        // write your code here
        return currentNode != null || !stack.isEmpty();
    }

    //@return: return next node
    public TreeNode next() {
        // write your code here
        while (currentNode != null) {
            stack.push(currentNode);
            currentNode = currentNode.left;
        }

        currentNode = stack.pop();
        TreeNode node = currentNode;
        currentNode = currentNode.right;

        return node;
    }
}

