#
# @lc app=leetcode.cn id=299 lang=python3
# @lcpr version=30118
#
# [299] 猜数字游戏
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        a = sum(x == y for x, y in zip(secret, guess))
        b = sum((Counter(secret) & Counter(guess)).values()) - a
        return f"{a}A{b}B"
# @lc code=end



#
# @lcpr case=start
# "1807"\n"7810"\n
# @lcpr case=end

# @lcpr case=start
# "1123"\n"0111"\n
# @lcpr case=end

#

