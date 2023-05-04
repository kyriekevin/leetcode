#
# @lc app=leetcode.cn id=2106 lang=python3
# @lcpr version=21907
#
# [2106] 摘水果
#

# @lc code=start
class Solution:
    def maxTotalFruits(self, fruits: List[List[int]], startPos: int, k: int) -> int:
        n = len(fruits)
        m = n
        for i in range(n):
            if fruits[i][0] >= startPos:
                m = i
                break
        
        lcnt, rcnt = 0, 0
        for i in range(m, n):
            rcnt += fruits[i][1]
        
        i, j = m - 1, n - 1
        res = 0
        while i >= 0:
            lp = startPos - fruits[i][0]
            if lp > k:
                break
            lcnt += fruits[i][1]
            
            while j >= m and fruits[j][0] - fruits[i][0] > k - lp:
                rcnt -= fruits[j][1]
                j -= 1
            
            res = max(res, lcnt + rcnt)
            i -= 1
        
        lcnt, rcnt = 0, 0
        for i in range(m):
            lcnt += fruits[i][1]
        
        i, j = 0, m
        while j < n:
            rp = fruits[j][0] - startPos
            if rp > k:
                break
            rcnt += fruits[j][1]
            
            while i < m and fruits[j][0] - fruits[i][0] > k - rp:
                lcnt -= fruits[i][1]
                i += 1
            
            res = max(res, lcnt + rcnt)
            j += 1
        
        return res
            
# @lc code=end



#
# @lcpr case=start
# [[2,8],[6,3],[8,6]]\n5\n4\n
# @lcpr case=end

# @lcpr case=start
# [[0,9],[4,1],[5,7],[6,2],[7,4],[10,9]]\n5\n4\n
# @lcpr case=end

# @lcpr case=start
# [[0,3],[6,4],[8,5]]\n3\n2\n
# @lcpr case=end

#

