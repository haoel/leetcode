# Method 1: recursive in-order traversal
def kthSmallest1(self, root, k):
    inorder = []
    def helper(root):
        if root:
            helper(root.left)
            inorder.append(root.val)
            helper(root.right)
    
    helper(root)
    return inorder[k-1]

# Method 2: iterative in-order traversal
def kthSmallest2(self, root, k):
    stack = []
    while root or stack:
        while root:
            stack.append(root)
            root = root.left
        root = stack.pop()
        k -= 1
        if k == 0: return root.val
        root = root.right