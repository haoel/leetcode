def findDuplicateSubtrees(self, root):
    nodes = collections.defaultdict(list)
    
    def helper(root):
        if not root: return 'None'
        struct = '%s,%s,%s' % (str(root.val), helper(root.left), helper(root.right))
        nodes[struct].append(root)
        return struct
    
    helper(root)
    return [nodes[struct][0] for struct in nodes if len(nodes[struct]) > 1]