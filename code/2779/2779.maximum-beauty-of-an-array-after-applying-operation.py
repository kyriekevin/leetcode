# @leet start
class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        nums.sort()
        res = left = 0
        for right, x in enumerate(nums):
            while x - nums[left] > 2 * k:
                left += 1
            res = max(res, right - left + 1)
        return res


# @leet end

