package binaryTreeMaximumPathSum;

import org.junit.Test;

import java.util.ArrayList;

import static org.junit.Assert.*;

/**
 * Created by leicao on 8/10/15.
 */
public class binaryTreeMaximumPathSumTest {

    @Test
    public void testMaxPathSum() throws Exception {
        ArrayList<TreeNode> inputs = new ArrayList<TreeNode>();

        TreeNode t0 = new TreeNode(-15);
        TreeNode t1 = new TreeNode(5);
        TreeNode t2 = new TreeNode(6);
        TreeNode t3 = new TreeNode(-8);
        TreeNode t4 = new TreeNode(1);
        TreeNode t5 = new TreeNode(3);
        TreeNode t6 = new TreeNode(9);
        TreeNode t7 = new TreeNode(2);
        TreeNode t8 = new TreeNode(6);
        TreeNode t9 = new TreeNode(0);
        TreeNode t10 = new TreeNode(4);
        TreeNode t11 = new TreeNode(-1);
        TreeNode t12 = new TreeNode(10);

        t0.left = t1;
        t0.right = t2;

        t1.left = t3;
        t1.right = t4;

        t2.left = t5;
        t2.right = t6;

        t3.left = t7;
        t3.right = t8;

        t6.right = t9;

        t9.left = t10;
        t9.right = t11;

        t11.left = t12;


        TreeNode n1 = new TreeNode(9);
        TreeNode n2 = new TreeNode(6);
        TreeNode n3 = new TreeNode(-3);
        TreeNode n4 = new TreeNode(-6);
        TreeNode n5 = new TreeNode(2);
        TreeNode n6 = new TreeNode(2);
        TreeNode n7 = new TreeNode(-6);
        TreeNode n8 = new TreeNode(-6);
        TreeNode n9 = new TreeNode(-6);

        n1.left = n2;
        n1.right = n3;

        n3.left = n4;
        n3.right = n5;

        n5.left = n6;

        n6.left = n7;
        n6.right = n8;

        n7.left = n9;



//        inputs.add(t0);
        inputs.add(n1);
        int[] results = {
//                27,
                16
        };

        for (int i = 0; i < results.length; i++) {
            binaryTreeMaximumPathSum b = new binaryTreeMaximumPathSum();
            int r = b.maxPathSum(inputs.get(i));
            System.out.println(r);
            assertEquals(results[i], r);
        }

    }
}