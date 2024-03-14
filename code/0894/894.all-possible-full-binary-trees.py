#
# @lc app=leetcode.cn id=894 lang=python3
# @lcpr version=30121
#
# [894] 所有可能的真二叉树
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
N = 11
f = [[] for _ in range(N)]
f[1] = [TreeNode(0)]
for i in range(2, N):
    f[i] = [
        TreeNode(0, left, right)
        for j in range(1, i)
        for left in f[j]
        for right in f[i - j]
    ]


class Solution:
    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:
        return f[(n + 1) // 2] if n % 2 else []


# @lc code=end


#
# @lcpr case=start
# 7\n
# @lcpr case=end

# @lcpr case=start
# 3\n
# @lcpr case=end

#
