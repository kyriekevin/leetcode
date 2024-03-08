#
# @lc app=leetcode.cn id=2834 lang=python3
# @lcpr version=30118
#
# [2834] 找出美丽数组的最小和
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def minimumPossibleSum(self, n: int, k: int) -> int:
        m = min(k // 2, n)
        return (m * (m + 1) + (k * 2 + n - m - 1) * (n - m)) // 2 % 1_000_000_007
# @lc code=end



#
# @lcpr case=start
# 2\n3\n
# @lcpr case=end

# @lcpr case=start
# 3\n3\n
# @lcpr case=end

# @lcpr case=start
# 1\n1\n
# @lcpr case=end

#

