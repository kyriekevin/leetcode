#
# @lc app=leetcode.cn id=1237 lang=python3
# @lcpr version=21505
#
# [1237] 找出给定方程的正整数解
#

# @lc code=start
"""
   This is the custom function interface.
   You should not implement it, or speculate about its implementation
   class CustomFunction:
       # Returns f(x, y) for any given positive integers x and y.
       # Note that f(x, y) is increasing with respect to both x and y.
       # i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
       def f(self, x, y):
  
"""

class Solution:
    def findSolution(self, customfunction: 'CustomFunction', z: int) -> List[List[int]]:
        x, y = 1, 1000
        res = []
        while x <= 1000 and y >= 1:
            t = customfunction.f(x, y)
            if t > z:
                y -= 1
            elif t < z:
                x += 1
            else:
                res.append([x, y])
                y -= 1
                x += 1
        return res
        
# @lc code=end

# @lcpr-div-debug-arg-start
# funName=
# paramTypes= []
# returnType=
# @lcpr-div-debug-arg-end


#
# @lcpr case=start
# 1\n5\n
# @lcpr case=end

# @lcpr case=start
# 2\n5\n
# @lcpr case=end

#


