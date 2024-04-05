# @leet start
N = 55
coprime = [[j for j in range(1, N) if gcd(i, j) == 1] for i in range(N)]


class Solution:
    def getCoprimes(self, nums: List[int], edges: List[List[int]]) -> List[int]:
        n = len(nums)
        g = [[] for _ in range(n)]
        for x, y in edges:
            g[x].append(y)
            g[y].append(x)

        res = [0] * n
        dep = [(-1, -1)] * N

        def dfs(x: int, fa: int, depth: int) -> None:
            val = nums[x]
            res[x] = max(dep[i] for i in coprime[val])[1]
            tmp = dep[val]
            dep[val] = (depth, x)
            for y in g[x]:
                if y != fa:
                    dfs(y, x, depth + 1)
            dep[val] = tmp

        dfs(0, -1, 0)

        return res


# @leet end

