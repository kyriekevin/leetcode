#
# @lc app=leetcode.cn id=2972 lang=python3
#
# [2972] 统计移除递增子数组的数目 II
#

# @lc code=start
class Solution:
    def incremovableSubarrayCount(self, nums: List[int]) -> int:
        n = len(nums)
        i, j = 0, n - 1
        while i + 1 < n and nums[i] < nums[i + 1]:
            i += 1
        
        if i == n - 1:
            return n * (n + 1) // 2

        res = i + 2
        while j == n - 1 or nums[j] < nums[j + 1]:
            while i >= 0 and nums[i] >= nums[j]:
                i -= 1
            res += i + 2
            j -= 1

        return res
            
# @lc code=end

