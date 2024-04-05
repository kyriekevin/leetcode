# @leet start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        res = 0

        def dfs(node: Optional[TreeNode], minv: int, maxv: int) -> None:
            if node is None:
                nonlocal res
                res = max(res, maxv - minv)
                return

            maxv = max(maxv, node.val)
            minv = min(minv, node.val)
            dfs(node.left, minv, maxv)
            dfs(node.right, minv, maxv)

        dfs(root, root.val, root.val)

        return res


# @leet end
