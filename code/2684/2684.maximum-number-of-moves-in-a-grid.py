#
# @lc app=leetcode.cn id=2684 lang=python3
# @lcpr version=30119
#
# [2684] 矩阵中移动的最大次数
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        st = [-1] * n
        q = range(n)
        for j in range(m - 1):
            tmp = q
            q = []
            for i in tmp:
                for k in i - 1, i, i + 1:
                    if 0 <= k < n and st[k] != j and grid[k][j + 1] > grid[i][j]:
                        st[k] = j
                        q.append(k)
            if not q:
                return j
        return m - 1
# @lc code=end



#
# @lcpr case=start
# [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]\n
# @lcpr case=end

# @lcpr case=start
# [[3,2,4],[2,1,9],[1,1,7]]\n
# @lcpr case=end

#

