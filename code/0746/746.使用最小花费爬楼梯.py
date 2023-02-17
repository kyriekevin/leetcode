class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        f = [float("inf")] * n
        f[0], f[1] = cost[0], cost[1]

        for i in range(2, n):
            f[i] = min(f[i - 1], f[i - 2]) + cost[i]

        return min(f[n - 1], f[n - 2])
