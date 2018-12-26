"""
Method 1: recursive
"""
def postorderTraversal(self, root):
    res = []
    def helper(root):
        if root:
            helper(root.left)
            helper(root.right)
            res.append(root.val)
    helper(root)
    return res

"""
Method 2: iterative, using two stacks
initialize first stack with root node, do the following if first is not None:
    pop from first stack, append the popped element to second stack,
    add left and right node to first stack if they are not None
return the second stack's value in reverse order
"""
def postorderTraversal(self, root):
    if not root: return []
    first, second = [root], []
    while first:
        node = first.pop()
        second.append(node)
        if node.left: first.append(node.left)
        if node.right: first.append(node.right)
    res = [node.val for node in second]
    res.reverse()
    return res