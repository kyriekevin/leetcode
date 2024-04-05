# @leet start
class Solution:
    def minSkips(self, dist: List[int], speed: int, hoursBefore: int) -> int:
        if sum(dist) > speed * hoursBefore:
            return -1

        @cache
        def dfs(i: int, j: int) -> int:
            if j < 0:
                return 0
            res = (dfs(i, j - 1) + dist[j] + speed - 1) // speed * speed
            if i:
                res = min(res, dfs(i - 1, j - 1) + dist[j])
            return res

        for i in count(0):
            if dfs(i, len(dist) - 2) + dist[-1] <= speed * hoursBefore:
                return i


# @leet end
