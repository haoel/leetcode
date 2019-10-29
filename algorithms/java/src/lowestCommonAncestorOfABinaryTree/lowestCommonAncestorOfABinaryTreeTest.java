package lowestCommonAncestorOfABinaryTree;

import org.junit.Test;

import java.util.ArrayList;

import static org.junit.Assert.*;

/**
 * Created by leicao on 7/10/15.
 */
public class lowestCommonAncestorOfABinaryTreeTest {

    @Test
    public void testLowestCommonAncestor() throws Exception {
        ArrayList<TreeNode> inputeRoots = new ArrayList<>();
        ArrayList<TreeNode> inputeAs = new ArrayList<>();
        ArrayList<TreeNode> inputeBs = new ArrayList<>();
        ArrayList<TreeNode> results = new ArrayList<>();

        TreeNode n0 = new TreeNode(0);
        TreeNode n1 = new TreeNode(1);
        TreeNode n2 = new TreeNode(2);
        n0.left = n1;
        n0.right = n2;
        inputeRoots.add(n0);
        inputeAs.add(n1);
        inputeBs.add(n2);
        results.add(n0);

        for (int i = 0; i < results.size(); i++) {
            lowestCommonAncestorOfABinaryTree l = new lowestCommonAncestorOfABinaryTree();
            TreeNode r = l.lowestCommonAncestor(inputeRoots.get(i), inputeAs.get(i), inputeBs.get(i));
            assertEquals(results.get(i).val, r.val);
        }

    }
}