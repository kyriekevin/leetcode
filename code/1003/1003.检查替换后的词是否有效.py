#
# @lc app=leetcode.cn id=1003 lang=python3
# @lcpr version=21907
#
# [1003] 检查替换后的词是否有效
#

# @lc code=start
class Solution:
    def isValid(self, s: str) -> bool:
        stk = ""
        for ch in s:
            stk += ch
            if len(stk) >= 3 and stk[-3:] == "abc":
                stk = stk[:-3]
        
        return len(stk) == 0
# @lc code=end



#
# @lcpr case=start
# "aabcbc"\n
# @lcpr case=end

# @lcpr case=start
# "abcabcababcc"\n
# @lcpr case=end

# @lcpr case=start
# "abccba"\n
# @lcpr case=end

#

