# @leet start
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        n = len(nums)
        arr = [1 for _ in range(n + 2)]
        for i in range(1, n + 1):
            arr[i] = nums[i - 1]
        f = [[0 for _ in range(n + 2)] for _ in range(n + 2)]
        for lens in range(3, n + 3):
            for l in range(0, n + 3 - lens):
                r = l + lens - 1
                for k in range(l + 1, r):
                    f[l][r] = max(f[l][r], f[l][k] + f[k][r] + arr[l] * arr[k] * arr[r])
        return f[0][n + 1]


# @leet end

