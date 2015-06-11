/****
 * Solution of https://leetcode.com/problems/path-sum-ii/
 * @author: Jerry Zou
 * @date: 2015.6.9
 **/

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} sum
 * @return {number[][]}
 */
var pathSum = function(root, sum) {
    var result = [],
        target = sum,
        path = [];

    function simpleClone(arr) {
        var clone = [];
        for (var i = 0; i < arr.length; i++) clone.push(arr[i]);
        return clone;
    }

    function partialPathSum(root, current) {
        if (!root) {
            return;
        }

        current += root.val;

        if (current === target && !(root.left || root.right)) {
            path.push(root.val);
            result.push(simpleClone(path));
            path.pop();
        } else if (root.left || root.right){
            path.push(root.val);
            partialPathSum(root.left, current);
            partialPathSum(root.right, current);
            path.pop();
        } 
    }

    partialPathSum(root, 0);
    return result;
};