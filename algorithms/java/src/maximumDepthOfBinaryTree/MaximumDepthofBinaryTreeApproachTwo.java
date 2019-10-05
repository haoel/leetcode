/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int maxDepth(TreeNode root) {
        if (root==null)
            return 0;
        return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
    }
}


// BFS

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int maxDepth(TreeNode root) {

        List<List<Integer>> resList = new ArrayList<>();
        
        if (root==null)
            return 0;
        //BFS
        Queue<TreeNode> q1 = new LinkedList<>();
        Queue<TreeNode> q2 = new LinkedList<>();
        q1.add(root);
        
        while (!q1.isEmpty() || !q2.isEmpty())
        {
            resList.add(getListPerLevel(q1,q2));
        }
        return resList.size();
    }
    
    public static List getListPerLevel(Queue<TreeNode> q1, Queue<TreeNode> q2)
    {
        List<Integer> r1=new ArrayList<>();
        while(!q1.isEmpty())
            {
                TreeNode tempNode=q1.remove();
                if(tempNode.left !=null)
                    q2.add(tempNode.left);
                if(tempNode.right != null)
                    q2.add(tempNode.right);
                r1.add(tempNode.val);
            }
        if(!r1.isEmpty())
            return r1;
        while (!q2.isEmpty())
            {
                TreeNode tempNode=q2.remove();
                if(tempNode.left !=null)
                    q1.add(tempNode.left);
                if(tempNode.right != null)
                    q1.add(tempNode.right);
                r1.add(tempNode.val);
            }
            return r1;
    }
}




// BFS Approach 2

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int maxDepth(TreeNode root) {
        
        if (root==null)
            return 0;
        //BFS
        
        Queue<TreeNode> q = new LinkedList<>();
        int depth=0;
        q.add(root);
        while(!q.isEmpty())
        {
            depth++;
            int fsize = q.size();
            for (int i=0;i<fsize;i++)
            {
                TreeNode curr = q.poll();
                if (curr.left != null)
                    q.add(curr.left);
                if(curr.right!=null)
                    q.add(curr.right);
            }
        }
        return depth;
    }
}

