"""
Answe inspired by the post from here: 
https://leetcode.com/problems/house-robber-iii/discuss/79330/Step-by-step-tackling-of-the-problem
"""
# Method 1: dynamic programming solution:
def rob1(self, root):
        lookup = {}
        def helper(root):
            if not root: return 0
            if root in lookup: return lookup[root]
            val = 0
        
            if root.left:
                val += helper(root.left.left) + helper(root.left.right)
            if root.right:
                val += helper(root.right.left) + helper(root.right.right)
            val = max(val + root.val, helper(root.left) + helper(root.right))
            lookup[root] = val
            return val
        return helper(root)

# Method 2: Greedy approach:
def rob2(self, root):
    def helper(root):
        if not root: return [0, 0]
        left, right = helper(root.left), helper(root.right)
        not_robbed = max(left) + max(right)
        robbed = root.val + left[0] + right[0]
        return [not_robbed, robbed]
    return max(helper(root))