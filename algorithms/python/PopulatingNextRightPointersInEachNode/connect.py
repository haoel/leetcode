def connect(self, root):
    if not root: return
    stack = [[root]]
    while True:
        children = [child for node in stack[-1] for child in (node.left, node.right) if child]
        if not children: break
        stack.append(children)
        for i in range(len(children) - 1):
            children[i].next = children[i+1]