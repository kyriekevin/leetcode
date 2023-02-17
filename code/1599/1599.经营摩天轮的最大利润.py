#
# @lc app=leetcode.cn id=1599 lang=python3
# @lcpr version=21801
#
# [1599] 经营摩天轮的最大利润
#

# @lc code=start
class Solution:
    def minOperationsMaxProfit(self, customers: List[int], boardingCost: int, runningCost: int) -> int:
        wait, i = 0, 0
        mx, t = 0, 0
        res = -1

        while wait or i < len(customers):
            wait += customers[i] if i < len(customers) else 0
            up = min(4, wait)
            wait -= up
            t += up * boardingCost - runningCost
            i += 1
            if t > mx:
                mx = t
                res = i
        
        return res
            
# @lc code=end

# @lcpr-div-debug-arg-start
# funName=
# paramTypes= []
# returnType=
# @lcpr-div-debug-arg-end


#
# @lcpr case=start
# [8,3]\n5\n6\n
# @lcpr case=end

# @lcpr case=start
# [10,9,6]\n6\n4\n
# @lcpr case=end

# @lcpr case=start
# [3,4,0,5,1]\n1\n92\n
# @lcpr case=end

#


