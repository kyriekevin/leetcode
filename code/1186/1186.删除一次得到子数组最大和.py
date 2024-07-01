#
# @lc app=leetcode.cn id=1186 lang=python3
#
# [1186] 删除一次得到子数组最大和
#

# @lc code=start
class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        dp0, dp1, res = arr[0], 0, arr[0]
        for i in range(1, len(arr)):
            dp1 = max(dp0, dp1 + arr[i])
            dp0 = max(dp0, 0) + arr[i]
            res = max(res, dp0, dp1)
        return res
# @lc code=end

