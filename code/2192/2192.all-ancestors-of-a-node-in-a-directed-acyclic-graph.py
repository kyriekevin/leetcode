#
# @lc app=leetcode.cn id=2192 lang=python3
# @lcpr version=30121
#
# [2192] 有向无环图中一个节点的所有祖先
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        g = [[] for _ in range(n)]
        for x, y in edges:
            g[y].append(x)

        def dfs(x: int) -> None:
            st[x] = True
            for y in g[x]:
                if not st[y]:
                    dfs(y)

        res = [None] * n
        for i in range(n):
            st = [False] * n
            dfs(i)
            st[i] = False
            res[i] = [idx for idx, vis in enumerate(st) if vis]

        return res


# @lc code=end


#
# @lcpr case=start
# 8\n[[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]\n
# @lcpr case=end

# @lcpr case=start
# 5\n[[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]\n
# @lcpr case=end

#
