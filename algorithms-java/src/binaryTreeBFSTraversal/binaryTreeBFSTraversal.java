package binaryTreeBFSTraversal;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**
 * Created by leicao on 5/10/15.
 */
public class binaryTreeBFSTraversal {
    public List<Integer> bfsTraversal(TreeNode root) {
        List<Integer>  results = new ArrayList<Integer>();
        if (root == null) {
            return results;
        }

        Queue<TreeNode> q = new LinkedList<TreeNode>();

        q.offer(root);
        while (q.size() != 0) {
            TreeNode n = q.remove();
            results.add(n.val);
            if (n.left != null) {
                q.offer(n.left);
            }
            if (n.right != null) {
                q.offer(n.right);
            }
        }

        return results;

    }
}
