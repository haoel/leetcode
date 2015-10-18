package binarySearchTreeIterator;

import org.junit.Test;

import java.util.ArrayList;

import static org.junit.Assert.*;

/**
 * Created by leicao on 11/10/15.
 */
public class binarySearchTreeIteratorTest {
    @Test
    public void testIterator() throws Exception {
        ArrayList<TreeNode> inputs = new ArrayList<TreeNode>();
        TreeNode t0 = new TreeNode(10);
        TreeNode t1 = new TreeNode(1);
        TreeNode t2 = new TreeNode(11);
        TreeNode t3 = new TreeNode(6);
        TreeNode t4 = new TreeNode(12);
        t0.left = t1;
        t0.right = t2;
        t1.right = t3;
        t2.right = t4;

        inputs.add(t0);

        int[][] results = {
                {1,6,10,11,12}
        };

        for (int i = 0; i < results.length; i++) {
            binarySearchTreeIterator it = new binarySearchTreeIterator(inputs.get(i));
            int j = 0;
            while (it.hasNext()) {
                TreeNode r = it.next();
                assertEquals(results[i][j], r.val);
                j++;
            }
        }

    }

}