class Solution(object):
    def __init__(self):
        self.prev = None
        
    def flatten(self, root):
        if not root: return None
        self.flatten(root.right)
        self.flatten(root.left)
        root.right = self.prev
        root.left = None
        self.prev = root