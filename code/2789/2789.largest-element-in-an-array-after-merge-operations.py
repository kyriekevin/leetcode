#
# @lc app=leetcode.cn id=2789 lang=python3
# @lcpr version=30119
#
# [2789] 合并后数组中的最大元素
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def maxArrayValue(self, nums: List[int]) -> int:
        n, res = len(nums), 0
        if n == 1:
            return nums[0]
        
        for i in range(n - 2, -1, -1):
            if nums[i] <= nums[i + 1]:
                nums[i] = nums[i] + nums[i + 1]
            res = max(res, nums[i])
        
        return res
                
# @lc code=end



#
# @lcpr case=start
# [2,3,7,9,3]\n
# @lcpr case=end

# @lcpr case=start
# [5,3,3]\n
# @lcpr case=end

#

