#
# @lc app=leetcode.cn id=2171 lang=python3
# @lcpr version=30113
#
# [2171] 拿出最少数目的魔法豆
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def minimumRemoval(self, beans: List[int]) -> int:
        beans.sort()
        return sum(beans) - max((len(beans) - i) * v for i, v in enumerate(beans))
# @lc code=end



#
# @lcpr case=start
# [4,1,6,5]\n
# @lcpr case=end

# @lcpr case=start
# [2,10,3,2]\n
# @lcpr case=end

#

