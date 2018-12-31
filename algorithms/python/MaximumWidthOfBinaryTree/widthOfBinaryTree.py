def widthOfBinaryTree(self, root):
    if not root: return 0
    stack = [[(root, 0)]]
    res = 1
    while True:
        children = []
        for node, value in stack[-1]:
            if node.left: children.append((node.left, value * 2))
            if node.right: children.append((node.right, value * 2 + 1))
        if not children: break
        stack.append(children)
        res = max(res, children[-1][1] - children[0][1] + 1)
    return res