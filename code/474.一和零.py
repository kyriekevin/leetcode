#
# @lc app=leetcode.cn id=474 lang=python3
# @lcpr version=21401
#
# [474] 一和零
#

# @lc code=start
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for str in strs:
            ones = str.count('1')
            zeros = str.count('0')
            for i in range(m, zeros - 1, -1):
                for j in range(n, ones - 1, -1):
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1)
        return dp[m][n]

# @lc code=end



#
# @lcpr case=start
# ["10", "0001", "111001", "1", "0"]\n5\n3\n
# @lcpr case=end

# @lcpr case=start
# ["10", "0", "1"]\n1\n1\n
# @lcpr case=end

#


