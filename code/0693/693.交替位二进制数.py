#
# @lc app=leetcode.cn id=693 lang=python3
# @lcpr version=21401
#
# [693] 交替位二进制数
#

# @lc code=start
class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        x = n ^ (n >> 1)
        return (x & (x + 1)) == 0
# @lc code=end



#
# @lcpr case=start
# 5\n
# @lcpr case=end

# @lcpr case=start
# 7\n
# @lcpr case=end

# @lcpr case=start
# 11\n
# @lcpr case=end

#


