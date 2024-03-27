#
# @lc app=leetcode.cn id=2580 lang=python3
# @lcpr version=30120
#
# [2580] 统计将重叠区间合并成组的方案数
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def countWays(self, ranges: List[List[int]]) -> int:
        ranges.sort(key=lambda x: x[0])
        res = 2
        l, r = ranges[0]
        for i in range(1, len(ranges)):
            if ranges[i][0] <= r:
                r = max(r, ranges[i][1])
            else:
                res = res * 2 % 1000000007
                l, r = ranges[i]
        return res
# @lc code=end



#
# @lcpr case=start
# [[6,10],[5,15]]\n
# @lcpr case=end

# @lcpr case=start
# [[1,3],[10,20],[2,5],[4,8]]\n
# @lcpr case=end

#

