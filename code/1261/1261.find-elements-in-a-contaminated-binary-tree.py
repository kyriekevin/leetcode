#
# @lc app=leetcode.cn id=1261 lang=python3
# @lcpr version=30119
#
# [1261] 在受污染的二叉树中查找元素
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
class FindElements:

    def __init__(self, root: Optional[TreeNode]):
        self.root = root
        self.root.val = 0
        self.set = set()
        self.set.add(0)
        self.recover(self.root)

    def find(self, target: int) -> bool:
        return target in self.set
    
    def recover(self, root):
        if root.left:
            root.left.val = 2 * root.val + 1
            self.set.add(root.left.val)
            self.recover(root.left)
        if root.right:
            root.right.val = 2 * root.val + 2
            self.set.add(root.right.val)
            self.recover(root.right)

# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)
# @lc code=end



#
# @lcpr case=start
# ["FindElements","find","find"][[[-1,null,-1]],[1],[2]]\n
# @lcpr case=end

# @lcpr case=start
# ["FindElements","find","find","find"][[[-1,-1,-1,-1,-1]],[1],[3],[5]]\n
# @lcpr case=end

# @lcpr case=start
# ["FindElements","find","find","find","find"][[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]\n
# @lcpr case=end

#

