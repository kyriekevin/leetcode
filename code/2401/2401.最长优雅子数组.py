#
# @lc app=leetcode.cn id=2401 lang=python3
# @lcpr version=21705
#
# [2401] 最长优雅子数组
#

# @lc code=start
class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        res = 0
        for i in range(len(nums)):
            j, x = i, 0
            while j >= 0 and (x & nums[j]) == 0:
                x |= nums[j]
                j -= 1
            res = max(res, i - j)
        
        return res
# @lc code=end

# @lcpr-div-debug-arg-start
# funName=
# paramTypes= []
# returnType=
# @lcpr-div-debug-arg-end


#
# @lcpr case=start
# [1,3,8,48,10]\n
# @lcpr case=end

# @lcpr case=start
# [3,1,5,11,13]\n
# @lcpr case=end

#


