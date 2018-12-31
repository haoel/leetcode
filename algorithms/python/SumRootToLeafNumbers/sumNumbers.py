"""
Method 1: dfs
"""
def sumNumbers(self, root):
    if not root: return 0
    stack, res = [(root, root.val)], 0
    while stack:
        node, value = stack.pop()
        if not node.left and not node.right:
            res += value
        if node.right:
            stack.append((node.right, value * 10 + node.right.val))
        if node.left:
            stack.append((node.left, value * 10 + node.left.val))
    return res
    
    
    
"""
Method 2: recursive solution
"""
def sumNumbers(self, root):
    return self.helper(root, 0)

def helper(self, node, s):
    if not node: return 0
    if not node.left and not node.right: return s * 10 + node.val
    return self.helper(node.left, s * 10 + node.val) + \
            self.helper(node.right, s * 10 + node.val)