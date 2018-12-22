# recursive solution: takes O(n) time
# first get the height of the tree, then recusivly update the value

def printTree(self, root):
    def get_height(root):
        if not root: return 0
        return 1 + max(get_height(root.left), get_height(root.right))
    
    def update(res, node, row, left, right):
        if not node: return
        mid = (left + right) // 2
        res[row][mid] = str(node.val)
        update(res, node.left, row + 1, left, mid - 1)
        update(res, node.right, row + 1, mid + 1, right)
    
    height = get_height(root)
    width = 2 ** height - 1
    res = [['' for _ in range(width)] for _ in range(height)]
    update(res, root, 0, 0, width - 1)
    return res