#
# @lc app=leetcode.cn id=322 lang=python3
# @lcpr version=30119
#
# [322] 零钱兑换
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        f = [float('inf')] * (amount + 1)
        f[0] = 0
        for coin in coins:
            for j in range(coin, amount + 1):
                f[j] = min(f[j], f[j - coin] + 1)
        return f[amount] if f[amount] != float('inf') else -1
# @lc code=end



#
# @lcpr case=start
# [1, 2, 5]\n11\n
# @lcpr case=end

# @lcpr case=start
# [2]\n3\n
# @lcpr case=end

# @lcpr case=start
# [1]\n0\n
# @lcpr case=end

#

