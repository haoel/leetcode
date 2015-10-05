package binaryTreePreorderTraversal;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

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
