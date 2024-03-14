#
# @lc app=leetcode.cn id=2642 lang=python3
# @lcpr version=30120
#
# [2642] 设计可以求最短路径的图类
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Graph:

    def __init__(self, n: int, edges: List[List[int]]):
        f = [[inf] * n for _ in range(n)]
        for i in range(n):
            f[i][i] = 0
        for x, y, w in edges:
            f[x][y] = w
        for k in range(n):
            for i in range(n):
                if f[i][k] == inf:
                    continue
                for j in range(n):
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j])
        self.f = f

    def addEdge(self, edge: List[int]) -> None:
        f = self.f
        x, y, w = edge
        if f[x][y] < w:
            return

        n = len(f)
        for i in range(n):
            for j in range(n):
                f[i][j] = min(f[i][j], f[i][x] + w + f[y][j])

    def shortestPath(self, node1: int, node2: int) -> int:
        res = self.f[node1][node2]
        return res if res < inf else -1

# Your Graph object will be instantiated and called as such:
# obj = Graph(n, edges)
# obj.addEdge(edge)
# param_2 = obj.shortestPath(node1,node2)
# @lc code=end



#
# @lcpr case=start
# ["Graph", "shortestPath", "shortestPath", "addEdge", "shortestPath"][[4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]], [3, 2], [0, 3], [[1, 3, 4]], [0, 3]]\n
# @lcpr case=end

#

