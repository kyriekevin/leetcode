#
# @lc app=leetcode.cn id=337 lang=python3
# @lcpr version=21302
#
# [337] 打家劫舍 III
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        def dfs(u):
            if not u:
                return 0, 0
            la, lb = dfs(u.left)
            ra, rb = dfs(u.right)
            return lb + rb + u.val, max(la, lb) + max(ra, rb)
        return max(dfs(root))
# @lc code=end



#
# @lcpr case=start
# [3,2,3,null,3,null,1]\n
# @lcpr case=end

# @lcpr case=start
# [3,4,5,1,3,null,1]\n
# @lcpr case=end

#


