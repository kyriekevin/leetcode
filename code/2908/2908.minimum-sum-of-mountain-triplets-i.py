#
# @lc app=leetcode.cn id=2908 lang=python3
# @lcpr version=30121
#
# [2908] 元素和最小的山形三元组 I
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def minimumSum(self, nums: List[int]) -> int:
        n = len(nums)
        suf = [0] * n
        suf[-1] = nums[-1]
        for i in range(n - 2, 1, -1):
            suf[i] = min(suf[i + 1], nums[i])

        res = inf
        pre = nums[0]
        for i in range(1, n - 1):
            if pre < nums[i] > suf[i + 1]:
                res = min(res, pre + nums[i] + suf[i + 1])
            pre = min(pre, nums[i])
        return res if res < inf else -1
# @lc code=end



#
# @lcpr case=start
# [8,6,1,5,3]\n
# @lcpr case=end

# @lcpr case=start
# [5,4,8,7,10,2]\n
# @lcpr case=end

# @lcpr case=start
# [6,5,4,3,4,5]\n
# @lcpr case=end

#

