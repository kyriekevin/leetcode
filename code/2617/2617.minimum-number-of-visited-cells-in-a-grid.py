#
# @lc app=leetcode.cn id=2617 lang=python3
# @lcpr version=30119
#
# [2617] 网格图中最少访问的格子数
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def minimumVisitedCells(self, grid: List[List[int]]) -> int:
        col_heaps = [[] for _ in grid[0]]
        for i, row in enumerate(grid):
            row_h = []
            for j, (g, col_h) in enumerate(zip(row, col_heaps)):
                while row_h and row_h[0][1] < j:
                    heappop(row_h)
                while col_h and col_h[0][1] < i:
                    heappop(col_h)
                f = inf if i or j else 1
                if row_h:
                    f = row_h[0][0] + 1
                if col_h:
                    f = min(f, col_h[0][0] + 1)
                if g and f < inf:
                    heappush(row_h, (f, g + j))
                    heappush(col_h, (f, g + i))
        return f if f < inf else  -1
# @lc code=end



#
# @lcpr case=start
# [[3,4,2,1],[4,2,3,1],[2,1,0,0],[2,4,0,0]]\n
# @lcpr case=end

# @lcpr case=start
# [[3,4,2,1],[4,2,1,1],[2,1,1,0],[3,4,1,0]]\n
# @lcpr case=end

# @lcpr case=start
# [[2,1,0],[1,0,0]]\n
# @lcpr case=end

#

