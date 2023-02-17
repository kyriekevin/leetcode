#
# @lc app=leetcode.cn id=1144 lang=python3
# @lcpr version=21705
#
# [1144] 递减元素使数组呈锯齿状
#

# @lc code=start
class Solution:
    def movesToMakeZigzag(self, nums: List[int]) -> int:
        def work(nums, s):
            res = 0
            for i in range(s, len(nums), 2):
                t = nums[i]
                if i - 1 >= 0:
                    t = min(t, nums[i - 1] - 1)
                if i + 1 < len(nums):
                    t = min(t, nums[i + 1] - 1)
                res += nums[i] - t
            return res
        
        return min(work(nums, 0), work(nums, 1))
# @lc code=end

# @lcpr-div-debug-arg-start
# funName=
# paramTypes= []
# returnType=
# @lcpr-div-debug-arg-end


#
# @lcpr case=start
# [1,2,3]\n
# @lcpr case=end

# @lcpr case=start
# [9,6,1,6,2]\n
# @lcpr case=end

#


