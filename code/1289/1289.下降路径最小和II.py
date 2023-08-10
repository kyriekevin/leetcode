class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        n = len(grid)
        f = [[float('inf') for _ in range(n)] for _ in range(n)]

        f[0] = grid[0]

        for i in range(n):
            for j in range(n):
                for k in range(n):
                    if j == k:
                        continue
                    f[i][j] = min(f[i][j], f[i - 1][k] + grid[i][j])
        
        return min(f[n - 1])
