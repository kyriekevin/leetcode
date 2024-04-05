# @leet start
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        a = sorted(set(nums))
        res, l = 0, 0
        for i, x in enumerate(a):
            while a[l] < x - n + 1:
                l += 1
            res = max(res, i - l + 1)
        return n - res


# @leet end
