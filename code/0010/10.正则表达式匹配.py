#
# @lc app=leetcode.cn id=10 lang=python3
# @lcpr version=21302
#
# [10] 正则表达式匹配
#

# @lc code=start
from functools import lru_cache


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        @lru_cache(None)
        def recur(i, j):
            if j == len(p):
                return i == len(s)
            first_match = (len(s) > i) and (p[j] == s[i] or p[j] == '.')
            if len(p) >= j + 2 and p[j + 1] == '*':
                return recur(i, j + 2) or (first_match and recur(i + 1, j))
            return first_match and recur(i + 1, j + 1)
        return recur(0, 0)
# @lc code=end



#
# @lcpr case=start
# "aa"\n"a"\n
# @lcpr case=end

# @lcpr case=start
# "aa"\n"a*"\n
# @lcpr case=end

# @lcpr case=start
# "ab"\n".*"\n
# @lcpr case=end

#


