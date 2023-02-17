#
# @lc app=leetcode.cn id=2319 lang=python3
# @lcpr version=21304
#
# [2319] 判断矩阵是否是一个 X 矩阵
#

# @lc code=start
class Solution:
    def checkXMatrix(self, grid: List[List[int]]) -> bool:
        n = len(grid)
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                if i == j or i + j == n - 1:
                    if x == 0:
                        return False
                elif x:
                    return False
        return True
                    
# @lc code=end



#
# @lcpr case=start
# [[2,0,0,1],[0,3,1,0],[0,5,2,0],[4,0,0,2]]\n
# @lcpr case=end

# @lcpr case=start
# [[5,7,0],[0,3,1],[0,5,0]]\n
# @lcpr case=end

#


