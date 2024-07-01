#
# @lc app=leetcode.cn id=2850 lang=python3
#
# [2850] 将石头分散到网格图的最少移动次数
#

# @lc code=start
class Solution:
    def minimumMoves(self, grid: List[List[int]]) -> int:
        fr, to = [], []
        for i, row in enumerate(grid):
            for j, cnt in enumerate(row):
                if cnt > 1:
                    fr.extend([(i, j)] * (cnt - 1))
                elif cnt == 0:
                    to.append((i, j))
        
        res = inf
        for f in permutations(fr):
            tot = 0
            for (x1, y1), (x2, y2) in zip(f, to):
                tot += abs(x1 - x2) + abs(y1 - y2)
            res = min(res, tot)
        return res
# @lc code=end

