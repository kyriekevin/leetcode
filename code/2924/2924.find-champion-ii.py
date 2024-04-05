# @leet start
class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        weak = [False] * n
        for _, y in edges:
            weak[y] = True

        res = -1
        for i, w in enumerate(weak):
            if w:
                continue
            if res != -1:
                return -1
            res = i

        return res


# @leet end

