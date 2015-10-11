package searchRangeInBinarySearchTree;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Collection;

import static org.junit.Assert.*;

/**
 * Created by leicao on 9/10/15.
 */
public class searchRangeInBinarySearchTreeTest {

    @Test
    public void testSearchRange() throws Exception {
        ArrayList<TreeNode> inputs = new ArrayList<TreeNode>();

        TreeNode t1 = new TreeNode(20);
        TreeNode t2 = new TreeNode(8);
        TreeNode t3 = new TreeNode(22);
        TreeNode t4 = new TreeNode(4);
        TreeNode t5 = new TreeNode(12);

        t1.left = t2;
        t1.right = t3;
        t2.left = t4;
        t2.right = t5;

        inputs.add(t1);

        int[][] ranges = {
            {10,22}
        };

        ArrayList<ArrayList<Integer>> results = new ArrayList<ArrayList<Integer>>(){{
            add(new ArrayList<Integer>(){{
                add(12);
                add(20);
                add(22);
            }});
        }};

        for (int i = 0; i < results.size(); i++) {
            searchRangeInBinarySearchTree s = new searchRangeInBinarySearchTree();
            ArrayList<Integer> r = s.searchRange(inputs.get(i), ranges[i][0], ranges[i][1]);
            assertTrue(r.containsAll(results.get(i)) && r.size() == results.get(i).size());
        }
    }
}