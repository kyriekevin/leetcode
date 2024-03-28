#
# @lc app=leetcode.cn id=1997 lang=python3
# @lcpr version=30121
#
# [1997] 访问完所有房间的第一天
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def firstDayBeenInAllRooms(self, nextVisit: List[int]) -> int:
        s = [0] * len(nextVisit)
        for i, j in enumerate(nextVisit[:-1]):
            s[i + 1] = (s[i] * 2 - s[j] + 2) % 1000000007
        return s[-1]
# @lc code=end



#
# @lcpr case=start
# [0,0]\n
# @lcpr case=end

# @lcpr case=start
# [0,0,2]\n
# @lcpr case=end

# @lcpr case=start
# [0,1,2,0]\n
# @lcpr case=end

#

