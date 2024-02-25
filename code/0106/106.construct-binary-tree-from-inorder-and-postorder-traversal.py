#
# @lc app=leetcode.cn id=106 lang=python3
# @lcpr version=30117
#
# [106] 从中序与后序遍历序列构造二叉树
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
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        root = TreeNode(postorder[-1])
        stk = [root]
        inIdx = len(inorder) - 1
        
        for i in range(len(postorder) - 2, -1, -1):
            postVal = postorder[i]
            node = stk[-1]
            if node.val != inorder[inIdx]:
                node.right = TreeNode(postVal)
                stk.append(node.right)
            else:
                while stk and stk[-1].val == inorder[inIdx]:
                    node = stk.pop()
                    inIdx -= 1
                node.left = TreeNode(postVal)
                stk.append(node.left)
        
        return root
                    
# @lc code=end



#
# @lcpr case=start
# [9,3,15,20,7]\n[9,15,7,20,3]\n
# @lcpr case=end

# @lcpr case=start
# [-1]\n[-1]\n
# @lcpr case=end

#

