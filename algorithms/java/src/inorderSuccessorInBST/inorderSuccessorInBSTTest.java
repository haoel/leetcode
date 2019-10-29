package inorderSuccessorInBST;

import org.junit.Test;

import java.util.ArrayList;

import static org.junit.Assert.*;

/**
 * Created by leicao on 7/10/15.
 */
public class inorderSuccessorInBSTTest {

    @Test
    public void testInorderSuccessor() throws Exception {
        ArrayList<TreeNode> inputes = new ArrayList<>();
        ArrayList<TreeNode> targets = new ArrayList<>();

        TreeNode n0 = new TreeNode(2);
        TreeNode n1 = new TreeNode(1);
        TreeNode n2 = new TreeNode(3);
        n0.left = n1;
        n0.right = n2;
        inputes.add(n0);
        targets.add(n2);

        TreeNode nn0 = new TreeNode(2);
        TreeNode nn1 = new TreeNode(1);
        nn0.left = nn1;
        inputes.add(nn0);
        targets.add(nn1);

        TreeNode t0 = new TreeNode(1);
        TreeNode t1 = new TreeNode(2);
        t0.right = t1;
        inputes.add(t0);
        targets.add(t0);


        ArrayList<TreeNode> results = new ArrayList<>();
        results.add(null);
        results.add(nn0);
        results.add(t1);

        for (int i = 0; i < results.size(); i++) {
            inorderSuccessorInBST finder = new inorderSuccessorInBST();
            TreeNode node = finder.inorderSuccessor(inputes.get(i), targets.get(i));
            System.out.println(node);
            boolean result = node == results.get(i)  || node.val == results.get(i).val;
            assertTrue(result);
        }
    }
}