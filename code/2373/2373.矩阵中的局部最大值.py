#
# @lc app=leetcode.cn id=2373 lang=python3
# @lcpr version=21707
#
# [2373] 矩阵中的局部最大值
#

# @lc code=start
class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)
        res = [[0] * (n - 2) for _ in range(n - 2)]
        for i in range(n - 2):
            for j in range(n - 2):
                res[i][j] = max(grid[x][y] for x in range(i, i + 3) for y in range(j, j + 3))

        return res
# @lc code=end

# @lcpr-div-debug-arg-start
# funName=
# paramTypes= []
# returnType=
# @lcpr-div-debug-arg-end


#
# @lcpr case=start
# [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]\n
# @lcpr case=end

# @lcpr case=start
# [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]\n
# @lcpr case=end

#


