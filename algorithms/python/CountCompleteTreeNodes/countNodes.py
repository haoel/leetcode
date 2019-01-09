def countNodes(self, root):
    if not root: return 0
    hl, hr = 0, 0
    l, r = root, root
    while l:
        hl += 1
        l = l.left
    while r:
        hr += 1
        r = r.right
    if hl == hr: return pow(2, hl) - 1
    return 1 + self.countNodes(root.left) + self.countNodes(root.right)