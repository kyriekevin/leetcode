#
# @lc app=leetcode.cn id=2961 lang=python3
#
# [2961] 双模幂运算
#

# @lc code=start
class Solution:
    def getGoodIndices(self, variables: List[List[int]], target: int) -> List[int]:
        def qmi(a, b, p):
            res = 1
            while b:
                if b & 1:
                    res = res * a % p
                a = a * a % p
                b >>= 1
            return res

        return [i for i, (a, b, c, m) in enumerate(variables) if qmi(qmi(a, b, 10), c, m) == target]
# @lc code=end

