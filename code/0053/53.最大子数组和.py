class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        pre, res = 0, nums[0]
        for x in nums:
            pre = max(pre + x, x)
            res = max(pre, res)
        return res

