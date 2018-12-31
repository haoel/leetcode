class Codec:

    def serialize(self, root):
        preorder = []
        
        def helper(node):
            if node:
                preorder.append(node.val)
                helper(node.left)
                helper(node.right)
        helper(root)
        return ' '.join(map(str, preorder))
        

    def deserialize(self, data):
        vals = collections.deque(int(val) for val in data.split())
        
        def build(minval, maxval):
            if vals and minval < vals[0] < maxval:
                val = vals.popleft()
                node = TreeNode(val)
                node.left = build(minval, val)
                node.right = build(val, maxval)
                return node

        return build(float('-infinity'), float('infinity'))