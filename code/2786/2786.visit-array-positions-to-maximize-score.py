# @leet start
class Solution:
    def maxScore(self, nums: List[int], x: int) -> int:
        res = nums[0]
        f = [-inf, -inf]
        f[nums[0] % 2] = nums[0]
        for i in range(1, len(nums)):
            p = nums[i] % 2
            cur = max(f[p], f[1 - p] - x) + nums[i]
            res = max(res, cur)
            f[p] = max(f[p], cur)

        return res


# @leet end

