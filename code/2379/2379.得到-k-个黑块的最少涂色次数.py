#
# @lc app=leetcode.cn id=2379 lang=python3
# @lcpr version=21801
#
# [2379] 得到 K 个黑块的最少涂色次数
#

# @lc code=start
class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        res, cnt = k, 0
        for i, ch in enumerate(blocks):
            if ch == 'W':
                cnt += 1
            if i >= k and blocks[i - k] == 'W':
                cnt -= 1
            if i >= k - 1:
                res = min(res, cnt)
        
        return res
# @lc code=end

# @lcpr-div-debug-arg-start
# funName=
# paramTypes= []
# returnType=
# @lcpr-div-debug-arg-end


#
# @lcpr case=start
# "WBBWWBBWBW"\n7\n
# @lcpr case=end

# @lcpr case=start
# "WBWBBBW"\n2\n
# @lcpr case=end

#


