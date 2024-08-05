#
# @lc app=leetcode.cn id=600 lang=python3
#
# [600] 不含连续1的非负整数
#

# @lc code=start
class Solution:
    def findIntegers(self, n: int) -> int:
        num = []
        while n:
            num.append(n % 2)
            n >>= 1
        f = [[0] * 2 for _ in range(len(num) + 1)]
        f[1][0] = f[1][1] = 1
        for i in range(2, len(num) + 1):
            f[i][0] = f[i - 1][0] + f[i - 1][1]
            f[i][1] = f[i - 1][0]
        
        res, last = 0, 0
        for i in range(len(num), 0, -1):
            t = num[i - 1]
            if t:
                res += f[i][0]
                if last:
                    return res
            last = t
        return res + 1
        
# @lc code=end

