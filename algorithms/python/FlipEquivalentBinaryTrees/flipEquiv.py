"""
Method 1: 
    naive recursive solution, divide the original problem into four subproblems,
    time complexity and space complexity are both O(n^2)
"""
def flipEquiv1(self, root1, root2):
    if not root1 or not root2:
        return root1 == root2
    if root1.val != root2.val:
        return False
    return self.flipEquiv(root1.left, root2.left) and \
            self.flipEquiv(root1.right, root2.right) or \
            self.flipEquiv(root1.left, root2.right) and \
            self.flipEquiv(root1.right, root2.left)

"""
Method 2: 
    Step 1: first preprocessing these two trees, sort them in the following order:
    if node.left.val > node.right.val, then swap them, make the smaller one to be left node
    if the left node is None, then also swap them, make the non-None node to be left node

    Step 2: compare the swapped trees

    After preprocessing, the original problem is divided into two subproblems, time complexity: O(n)
"""
def flipEquiv2(self, root1, root2):
    def flip(root):
        if root:
            if root.left and root.right and root.left.val > root.right.val:
                root.left, root.right = root.right, root.left
            if not root.left:
                root.left, root.right = root.right, root.left
            flip(root.left)
            flip(root.right)
    
    def is_equal(root1, root2):
        if not root1 or not root2:
            return root1 == root2
        return root1.val == root2.val and \
                is_equal(root1.left, root2.left) and \
                is_equal(root1.right, root2.right)
    
    flip(root1)
    flip(root2)
    return is_equal(root1, root2)