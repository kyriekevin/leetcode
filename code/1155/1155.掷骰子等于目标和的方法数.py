class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        mod = 10**9 + 7
        f = [[0] * (target + 1) for _ in range(n + 1)]
        f[0][0] = 1

        for i in range(1, n + 1):
            for j in range(target + 1):
                for x in range(1, k + 1):
                    if j >= x:
                        f[i][j] = (f[i][j] + f[i - 1][j - x]) % mod
        
        return f[n][target]
