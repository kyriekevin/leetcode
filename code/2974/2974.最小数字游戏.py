#
# @lc app=leetcode.cn id=2974 lang=python3
#
# [2974] 最小数字游戏
#

# @lc code=start
class Solution:
    def numberGame(self, nums: List[int]) -> List[int]:
        nums.sort()
        for i in range(1, len(nums), 2):
            nums[i - 1], nums[i] = nums[i], nums[i - 1]
        return nums
# @lc code=end

