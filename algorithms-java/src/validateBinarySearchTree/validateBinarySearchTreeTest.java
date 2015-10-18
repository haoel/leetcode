package validateBinarySearchTree;

import org.junit.Test;
import java.util.ArrayList;
import static org.junit.Assert.*;

/**
 * Created by leicao on 6/10/15.
 */
public class validateBinarySearchTreeTest {

    @Test
    public void testIsValidBST() throws Exception {
        // [10,5,15,null,null,6,20]
        TreeNode t0 = new TreeNode(0);

        TreeNode n0 = new TreeNode(10);
        TreeNode n1 = new TreeNode(5);
        TreeNode n2 = new TreeNode(15);
        TreeNode n3 = null;
        TreeNode n4 = null;
        TreeNode n5 = new TreeNode(6);
        TreeNode n6 = new TreeNode(20);

        n0.left = n1;
        n0.right = n2;

        n1.left = n3;
        n1.right = n4;

        n2.left = n5;
        n2.right = n6;

        TreeNode tt0 = new TreeNode(1);
        TreeNode tt1 = new TreeNode(1);
        tt0.left = tt1;

        TreeNode ttt0 = new TreeNode(2147483647);

        //[-2147483648,null,2147483647]
        TreeNode nn0 = new TreeNode(-2147483648);
        TreeNode nn1 = new TreeNode(2147483647);
        nn0.left = null;
        nn0.right = nn1;

        ArrayList<TreeNode> inputes = new ArrayList<TreeNode>();
        inputes.add(t0);
        inputes.add(n0);
        inputes.add(tt0);
        inputes.add(ttt0);
        inputes.add(nn0);

        boolean[] results = {
                true,
                false,
                false,
                true,
                true
        };

        for (int i = 0; i < results.length; i++) {
            validateBinarySearchTree v = new validateBinarySearchTree();
            boolean r = v.isValidBST(inputes.get(i));
            assertEquals(results[i], r);
        }
    }
}