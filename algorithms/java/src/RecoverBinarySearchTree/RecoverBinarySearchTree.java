// Source : https://leetcode.com/problems/recover-binary-search-tree/
// Author : Diego Ruiz Piqueras (Pikeras72)
// Date   : 23-04-2022

/***************************************************************************************************** 
 *
 * You are given the root of a binary search tree (BST), where the values of
 * exactly two nodes of the tree were swapped by mistake. Recover the tree
 * without changing its structure.
 * 
 * Example 1:
 * 
 * Input: root = [1,3,null,null,2]
 * Output: [3,1,null,null,2]
 * Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
 * 
 * Example 2:
 *
 * Input: root = [3,1,4,null,null,2]
 * Output: [2,1,4,null,null,3]
 * Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
 * 
 * Constraints:
 * 
 *  The number of nodes in the tree is in the range [2, 1000].
 *  -2^31 <= Node.val <= 2^31 - 1
 * 
 * Explanation of the solution:
 * 
 * 1. Firstly we apply the 'ordenCentralRec(root, new ArrayList<>(), aux1, aux2)' method to extract the
 *    nodes of the tree in an ArrayList<Integer>. We read the tree InOrder traversal. 
 *    Note that both aux1 and aux2 value's is Integer.MIN_VALUE so the nodo.val doesn't change.
 * 
 * 2. We check the values obtained in the ArrayList to see which are the changed numbers.
 * 
 * 3. Finally we apply the 'ordenCentralRec(root, new ArrayList<>(), aux1, aux2)' method to extract the
 *    final version of the binary search tree HAVING changed aux1 and aux2. The method will change the
 *    nodes values and return the the binary search tree changed.
 ******************************************************************************************************/

class Solution {
    public void recoverTree(TreeNode root) {
        int aux1 = Integer.MIN_VALUE, aux2 = Integer.MIN_VALUE;
        List<Integer> nums = ordenCentralRec(root, new ArrayList<>(), aux1, aux2);
        for (int i = 0; i < nums.size()-1;i++){
            if (nums.get(i) > nums.get(i+1)){
                if (aux1 == Integer.MIN_VALUE){
                    aux1 = nums.get(i);
                }
                aux2 = nums.get(i+1);
            }
        }
        nums.clear();
        ordenCentralRec(root, nums, aux1, aux2);
    }
    private List<Integer> ordenCentralRec(TreeNode nodo, List<Integer> nums, int aux1, int aux2) {
        if (nodo != null) {
            if (aux1 == nodo.val){
                nodo.val = aux2;
            }else if (aux2 == nodo.val){
                nodo.val = aux1;
            }
            nums = ordenCentralRec(nodo.left, nums, aux1, aux2);
            nums.add(nodo.val);
            nums = ordenCentralRec(nodo.right, nums, aux1, aux2);
        }
        return nums;
    }
}
