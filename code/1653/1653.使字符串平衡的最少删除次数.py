#
# @lc app=leetcode.cn id=1653 lang=python3
# @lcpr version=21801
#
# [1653] 使字符串平衡的最少删除次数
#

# @lc code=start
class Solution:
    def minimumDeletions(self, s: str) -> int:
        f, cnt_b = 0, 0
        for ch in s:
            if ch == 'b':
                cnt_b += 1
            else:
                f = min(f + 1, cnt_b)
        
        return f
# @lc code=end

# @lcpr-div-debug-arg-start
# funName=
# paramTypes= []
# returnType=
# @lcpr-div-debug-arg-end


#
# @lcpr case=start
# "aababbab"\n
# @lcpr case=end

# @lcpr case=start
# "bbaaaaabb"\n
# @lcpr case=end

#


