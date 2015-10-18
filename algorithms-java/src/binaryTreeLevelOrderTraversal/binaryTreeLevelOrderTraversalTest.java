package binaryTreeLevelOrderTraversal;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import static org.junit.Assert.*;

/**
 * Created by leicao on 8/10/15.
 */
public class binaryTreeLevelOrderTraversalTest {

    @Test
    public void testLevelOrder() throws Exception {
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

        t0.left = t1;
        t0.right = t2;

        t1.left = t3;
        t1.right = t4;

        t2.left = t5;
        t2.right = t6;

        t3.left = t7;
        t3.right = t8;

        inputs.add(t0);

        ArrayList<ArrayList<ArrayList<Integer>>> results = new ArrayList<ArrayList<ArrayList<Integer>>>(){{
            add(new ArrayList<ArrayList<Integer>>(){{
                add(new ArrayList<Integer>(){{
                   add(-15);
                }});
                add(new ArrayList<Integer>(){{
                    add(5);
                    add(6);
                }});
                add(new ArrayList<Integer>(){{
                    add(-8);
                    add(1);
                    add(3);
                    add(9);
                }});
                add(new ArrayList<Integer>(){{
                    add(2);
                    add(6);
                }});
            }});
        }};

        for (int i = 0; i < results.size(); i++) {
            binaryTreeLevelOrderTraversal b = new binaryTreeLevelOrderTraversal();
            List<List<Integer>> r = b.levelOrder(inputs.get(i));
            System.out.println(r.size());
            for (int j = 0; j < r.size(); j++) {
                System.out.println(Arrays.toString(r.toArray()));
            }
            assertTrue(r.containsAll(results.get(i)) && r.size() == results.get(i).size());
        }
    }
}