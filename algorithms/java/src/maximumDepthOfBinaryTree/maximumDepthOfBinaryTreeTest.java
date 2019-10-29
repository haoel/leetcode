package maximumDepthOfBinaryTree;

import org.junit.Test;

import java.util.ArrayList;

import static org.junit.Assert.*;

/**
 * Created by leicao on 5/10/15.
 */
public class maximumDepthOfBinaryTreeTest {

    @Test
    public void testMaxDepth() throws Exception {
        TreeNode t0 = new TreeNode(0);

        TreeNode n0 = new TreeNode(0);
        TreeNode n1 = new TreeNode(1);
        TreeNode n2 = new TreeNode(2);
        TreeNode n3 = new TreeNode(3);
        TreeNode n4 = new TreeNode(5);
        TreeNode n5 = new TreeNode(6);
        TreeNode n6 = new TreeNode(6);

        n0.left = n1;
        n0.right = n2;
        n1.left = n3;
        n1.right = n4;
        n4.left = n5;
        n2.right = n6;

        ArrayList<TreeNode> inputes = new ArrayList<>();
        inputes.add(t0);
        inputes.add(n0);
        int[] results = {1,3};

        maximumDepthOfBinaryTree m = new maximumDepthOfBinaryTree();
        for (int i = 0; i < results.length; i++) {
            int d = m.maxDepth(inputes.get(i));
            System.out.println(d);
            assertEquals(results[i], d);
        }
    }
}