def isSubtree(self, s, t):
    stack = [s]
    while stack:
        node = stack.pop(0)
        if node.val == t.val:
            if self.check(node, t): return True
        stack += [child for child in [node.left, node.right] if child]
    return False

def check(self, first, second):
    if not first and not second:
        return True
    if first and second:
        return first.val == second.val and self.check(first.left, second.left) and self.check(first.right, second.right)
    return False