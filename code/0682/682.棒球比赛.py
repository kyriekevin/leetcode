#
# @lc app=leetcode.cn id=682 lang=python3
#
# [682] 棒球比赛
#

# @lc code=start
class Solution:
    def calPoints(self, operations: List[str]) -> int:
      stk = []
      for op in operations:
        if op == "+":
          stk.append(stk[-1] + stk[-2])
        elif op == "D":
          stk.append(stk[-1] * 2)
        elif op == "C":
          stk.pop()
        else:
          stk.append(int(op))
      return sum(stk)
# @lc code=end

