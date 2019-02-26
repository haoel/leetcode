def isCompleteTree(self, root):
    stack = [[(root, 0)]]
    layer = 0
    while True:
        children = []
        for node, value in stack[-1]:
            if node.left: children.append((node.left, 2 * value))
            if node.right: children.append((node.right, 2 * value + 1))
            if node.right and not node.left: return False
        if not children: break
        if len(stack[-1]) != pow(2, layer): return False
        stack.append(children)
        layer += 1
    return len(stack[-1]) == stack[-1][-1][1] + 1