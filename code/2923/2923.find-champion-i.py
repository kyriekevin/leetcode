# @leet start
class Solution:
    def findChampion(self, grid: List[List[int]]) -> int:
        res = 0
        for i, row in enumerate(grid):
            if row[res]:
                res = i
        return res


# @leet end

