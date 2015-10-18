package balancedBinaryTree;

import org.junit.Test;

import java.util.ArrayList;

import static org.junit.Assert.*;
/**
 * Created by leicao on 7/10/15.
 */
public class balancedBinaryTreeTest {

    @Test
    public void testIsBalanced() throws Exception {
        ArrayList<TreeNode> inputes = new ArrayList<TreeNode>();
        boolean[] results = {false, false};
        TreeNode n0 = new TreeNode(0);
        TreeNode n1 = new TreeNode(1);
        TreeNode n2 = new TreeNode(2);
        TreeNode n3 = new TreeNode(3);

        n0.left = n1;
        n1.left = n2;
        n2.left = n3;

        TreeNode nn0 = new TreeNode(0);
        TreeNode nn1 = new TreeNode(1);
        TreeNode nn2 = new TreeNode(2);
        TreeNode nn3 = new TreeNode(3);
        nn0.right = nn1;
        nn1.left = nn2;
        nn2.left = nn3;

        inputes.add(n0);
        inputes.add(nn0);

        for (int i = 0; i < results.length; i++) {
            balancedBinaryTree b = new balancedBinaryTree();
            assertEquals(results[i], b.isBalanced(inputes.get(i)));
        }

    }
}