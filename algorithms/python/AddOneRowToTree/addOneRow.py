# get the nodes at (d - 1) layer:

def addOneRow(self, root, v, d):
    dummy, dummy.left = TreeNode(v), root
    row = [dummy]
    for _ in range(d - 1):
        row = [kid for node in row for kid in (node.left, node.right) if kid]
    
    for node in row:
        node.left, node.left.left = TreeNode(v), node.left
        node.right, node.right.right = TreeNode(v), node.right
    return dummy.left