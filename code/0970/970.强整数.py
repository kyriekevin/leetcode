#
# @lc app=leetcode.cn id=970 lang=python3
# @lcpr version=21907
#
# [970] 强整数
#

# @lc code=start
class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        return list(set([x**i + y**j for i in range(20) for j in range(20) if x**i + y**j <= bound]))
# @lc code=end



#
# @lcpr case=start
# 2\n3\n10\n
# @lcpr case=end

# @lcpr case=start
# 3\n5\n15\n
# @lcpr case=end

#

