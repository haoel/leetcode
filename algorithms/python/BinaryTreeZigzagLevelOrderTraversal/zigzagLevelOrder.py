"""
simple bfs
"""

def zigzagLevelOrder(self, root):
    if not root: return []
    stack = [[root]]
    res = [[root.val]]
    level = 0
    while True:
        level += 1
        children = [child for node in stack[-1] for child in (node.left, node.right) if child]
        if not children: break
        temp = [node.val for node in children]
        if level % 2 == 1: temp.reverse()
        res.append(temp)
        stack.append(children)
    return res