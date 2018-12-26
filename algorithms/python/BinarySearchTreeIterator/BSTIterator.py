# straight forward solution: do a inorder traversal

class BSTIterator(object):
    def __init__(self, root):
        self.inorder = []
        def helper(root):
            if root:
                helper(root.left)
                self.inorder.append(root.val)
                helper(root.right)
        helper(root)
        
    def hasNext(self):
        return len(self.inorder) != 0

    def next(self):
        return self.inorder.pop(0)

# Alternative solution:
class BSTIterator(object):
    def __init__(self, root):
        self.stack = []
        while root:
            self.stack.append(root)
            root = root.left
        

    def hasNext(self):
        return len(self.stack) != 0
        

    def next(self):
        node = self.stack.pop()
        x = node.right
        while x:
            self.stack.append(x)
            x = x.left
        return node.val
    