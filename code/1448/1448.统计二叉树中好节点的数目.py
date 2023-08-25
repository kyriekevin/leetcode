# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        def dfs(root, path_max):
            if root is None:
                return 0
            
            res = 0
            if root.val >= path_max:
                res += 1
                path_max = root.val
            
            res += dfs(root.left, path_max) + dfs(root.right, path_max)
            return res
        
        return dfs(root, -10**9)
