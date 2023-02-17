#
# @lc app=leetcode.cn id=2315 lang=python3
# @lcpr version=21301
#
# [2315] 统计星号
#

# @lc code=start
class Solution:
    def countAsterisks(self, s: str) -> int:
        valid = True
        res = 0
        for ch in s:
            if ch == '|':
                valid = not valid
            elif ch == '*' and valid:
                res += 1
        return res
# @lc code=end



#
# @lcpr case=start
# "l|*e*et|c**o|*de|"\n
# @lcpr case=end

# @lcpr case=start
# "iamprogrammer"\n
# @lcpr case=end

# @lcpr case=start
# "yo|uar|e**|b|e***au|tifu|l"\n
# @lcpr case=end

#


