#
# @lc app=leetcode.cn id=1247 lang=python3
# @lcpr version=21704
#
# [1247] 交换字符使得字符串相同
#

# @lc code=start
class Solution:
    def minimumSwap(self, s1: str, s2: str) -> int:
        cnt = Counter(x for x, y in zip(s1, s2) if x != y)
        d = cnt['x'] + cnt['y']
        return -1 if d % 2 else d // 2 + cnt['x'] % 2
# @lc code=end

# @lcpr-div-debug-arg-start
# funName=
# paramTypes= []
# returnType=
# @lcpr-div-debug-arg-end


#
# @lcpr case=start
# "xx"\n"yy"\n
# @lcpr case=end

# @lcpr case=start
# "xy"\n"yx"\n
# @lcpr case=end

# @lcpr case=start
# "xx"\n"xy"\n
# @lcpr case=end

# @lcpr case=start
# "xxyyxyxyxx"\n"xyyxyxxxyx"\n
# @lcpr case=end

#


