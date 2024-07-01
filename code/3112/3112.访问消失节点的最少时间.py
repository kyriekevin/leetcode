#
# @lc app=leetcode.cn id=3112 lang=python3
#
# [3112] 访问消失节点的最少时间
#

# @lc code=start
class Solution:
    def minimumTime(self, n: int, edges: List[List[int]], disappear: List[int]) -> List[int]:
        g = [[] for _ in range(n)]
        for u, v, w in edges:
            g[u].append((v, w))
            g[v].append((u, w))
        
        q = [[0, 0]]
        res = [-1] * n
        res[0] = 0

        while q:
            t, u = heappop(q)
            if t != res[u]:
                continue
            for v, length in g[u]:
                if t + length < disappear[v] and (res[v] == -1 or t + length < res[v]):
                    res[v] = t + length
                    heappush(q, (res[v], v))

        return res
# @lc code=end

