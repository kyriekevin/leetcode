#
# @lc app=leetcode.cn id=647 lang=python3
# @lcpr version=21706
#
# [647] 回文子串
#

# @lc code=start
class Solution:
    def countSubstrings(self, s: str) -> int:
        res, n = 0, len(s)
        for i in range(n):
            j, k = i, i
            while j >= 0 and k < n:
                if s[j] != s[k]:
                    break
                res += 1
                j, k = j - 1, k + 1
            
            j, k = i, i + 1
            while j >= 0 and k < n:
                if s[j] != s[k]:
                    break
                res += 1
                j, k = j - 1, k + 1

        return res
# @lc code=end

# @lcpr-div-debug-arg-start
# funName=
# paramTypes= []
# returnType=
# @lcpr-div-debug-arg-end


#
# @lcpr case=start
# "abc"\n
# @lcpr case=end

# @lcpr case=start
# "aaa"\n
# @lcpr case=end

#


