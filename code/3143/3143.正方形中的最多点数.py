#
# @lc app=leetcode.cn id=3143 lang=python3
#
# [3143] 正方形中的最多点数
#

# @lc code=start
class Solution:
    def maxPointsInsideSquare(self, points: List[List[int]], s: str) -> int:
        res = 0
        def check(sz):
            st = set()
            for (x, y), ch in zip(points, s):
                if abs(x) <= sz and abs(y) <= sz:
                    if ch in st:
                        return False
                    st.add(ch)
            nonlocal res
            res = max(res, len(st))
            return True

        l, r = -1, int(1e9) + 1
        while l < r:
            mid = l + r + 1 >> 1
            if check(mid):
                l = mid
            else:
                r = mid - 1
        return res
                
# @lc code=end

