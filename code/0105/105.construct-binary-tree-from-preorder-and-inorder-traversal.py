#
# @lc app=leetcode.cn id=105 lang=python3
# @lcpr version=30116
#
# [105] 从前序与中序遍历序列构造二叉树
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
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if not preorder:
            return None

        root = TreeNode(preorder[0])
        stk = [root]
        inIdx = 0
        for i in range(1, len(preorder)):
            preVal = preorder[i]
            node = stk[-1]
            if node.val != inorder[inIdx]:
                node.left = TreeNode(preVal)
                stk.append(node.left)
            else:
                while stk and stk[-1].val == inorder[inIdx]:
                    node = stk.pop()
                    inIdx += 1
                node.right = TreeNode(preVal)
                stk.append(node.right)
        
        return root
# @lc code=end



#
# @lcpr case=start
# [3,9,20,15,7]\n[9,3,15,20,7]\n
# @lcpr case=end

# @lcpr case=start
# [-1]\n[-1]\n
# @lcpr case=end

#

