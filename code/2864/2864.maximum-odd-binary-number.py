#
# @lc app=leetcode.cn id=2864 lang=python3
# @lcpr version=30119
#
# [2864] 最大二进制奇数
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        cnt, n = 0, len(s)
        for ch in s:
            if ch == "1":
                cnt += 1

        if cnt == 1:
            s = "0" * (n - 1) + "1"
        else:
            s = "1" * (cnt - 1) + "0" * (n - cnt) + "1"

        return s


# @lc code=end


#
# @lcpr case=start
# "010"\n
# @lcpr case=end

# @lcpr case=start
# "0101"\n
# @lcpr case=end

#
