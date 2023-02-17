#
# @lc app=leetcode.cn id=1480 lang=python3
# @lcpr version=21801
#
# [1480] 一维数组的动态和
#

# @lc code=start
class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        for i in range(1, len(nums)):
            nums[i] += nums[i - 1]
        
        return nums
# @lc code=end

# @lcpr-div-debug-arg-start
# funName=
# paramTypes= []
# returnType=
# @lcpr-div-debug-arg-end


#
# @lcpr case=start
# [1,2,3,4]\n
# @lcpr case=end

# @lcpr case=start
# [1,1,1,1,1]\n
# @lcpr case=end

# @lcpr case=start
# [3,1,2,10,1]\n
# @lcpr case=end

#


