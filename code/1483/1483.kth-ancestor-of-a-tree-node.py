# @leet start
class TreeAncestor:

    def __init__(self, n: int, parent: List[int]):
        log = 16
        ancestors = [[-1] * log for _ in range(n)]

        for i in range(n):
            ancestors[i][0] = parent[i]
        for j in range(1, log):
            for i in range(n):
                if ancestors[i][j - 1] != -1:
                    ancestors[i][j] = ancestors[ancestors[i][j - 1]][j - 1]

        self.log = log
        self.ancestors = ancestors

    def getKthAncestor(self, node: int, k: int) -> int:
        for i in range(self.log):
            if k >> i & 1:
                node = self.ancestors[node][i]
                if node == -1:
                    return -1
        return node


# Your TreeAncestor object will be instantiated and called as such:
# obj = TreeAncestor(n, parent)
# param_1 = obj.getKthAncestor(node,k)
# @leet end

