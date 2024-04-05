# @leet start
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        f = [0] * (target + 1)
        f[0] = 1

        for i in range(target + 1):
            for num in nums:
                if i >= num:
                    f[i] += f[i - num]
        return f[target]


# @leet end
