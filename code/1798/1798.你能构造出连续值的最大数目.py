#
# @lc app=leetcode.cn id=1798 lang=python3
# @lcpr version=21401
#
# [1798] 你能构造出连续值的最大数目
#

# @lc code=start
class Solution:
    def getMaximumConsecutive(self, coins: List[int]) -> int:
        coins.sort()
        x = 0
        for y in coins:
            if y > x + 1:
                break
            x += y
        return x + 1
# @lc code=end



#
# @lcpr case=start
# [1,3]\n
# @lcpr case=end

# @lcpr case=start
# [1,1,1,4]\n
# @lcpr case=end

# @lcpr case=start
# [1,4,10,3,1]\n
# @lcpr case=end

#


