"""
simple union find with path compression:
at first, each vertices are disjoint, there are N connected components at the begining,
after add each edge, we unify those two connected components, if two vertices are already 
in the same connected component, then this edge will form a circle, just return this edge
"""

def findRedundantConnection(self, edges):
    id = list(range(len(edges) + 1))
    
    def find(u):
        root = u
        while root != id[root]: root = id[root]
        
        # path compression:
        while u != root:
            next = id[u]
            id[u] = root
            u = next
        
        return root
    
    for u, v in edges:
        root1, root2 = find(u), find(v)
        if root1 == root2: return [u, v]
        
        # else, unify these two components:
        id[root1] = root2