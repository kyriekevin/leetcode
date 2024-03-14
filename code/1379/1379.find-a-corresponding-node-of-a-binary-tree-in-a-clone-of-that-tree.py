#
# @lc app=leetcode.cn id=1379 lang=python3
# @lcpr version=30121
#
# [1379] 找出克隆二叉树中的相同节点
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def getTargetCopy(
        self, original: TreeNode, cloned: TreeNode, target: TreeNode
    ) -> TreeNode:
        if original is None or original is target:
            return cloned

        return self.getTargetCopy(
            original.left, cloned.left, target
        ) or self.getTargetCopy(original.right, cloned.right, target)


# @lc code=end


#
# @lcpr case=start
# [7,4,3,null,null,6,19]\n3\n
# @lcpr case=end

# @lcpr case=start
# [7]\n7\n
# @lcpr case=end

# @lcpr case=start
# [8,null,6,null,5,null,4,null,3,null,2,null,1]\n4\n
# @lcpr case=end

#
