#
# @lc app=leetcode.cn id=572 lang=python3
#
# [572] 另一棵树的子树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getHeight(self, root):
        if not root:
            return 0
        return max(self.getHeight(root.left), self.getHeight(root.right)) + 1
    
    def isSameTree(self, p, q):
        if not p and not q:
            return True
        if not p or not q:
            return False
        return p.val == q.val and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)

    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        hs = self.getHeight(subRoot)
        
        def dfs(node):
            if not node:
                return 0, False
            left_h, left_f = dfs(node.left)
            right_h, right_f = dfs(node.right)
            if left_f or right_f:
                return 0, True
            node_h = max(left_h, right_h) + 1
            return node_h, node_h == hs and self.isSameTree(node, subRoot)
        
        return dfs(root)[1]
            
# @lc code=end

