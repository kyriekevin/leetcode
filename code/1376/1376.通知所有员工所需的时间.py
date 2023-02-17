#
# @lc app=leetcode.cn id=1376 lang=python3
# @lcpr version=21907
#
# [1376] 通知所有员工所需的时间
#

# @lc code=start
import queue
import collections

class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        g = collections.defaultdict(list)
        for i in range(n):
            g[manager[i]].append(i)
        
        q = queue.Queue()
        q.put((headID, 0))
        
        ans = 0
        while not q.empty():
            idx, val = q.get()
            for i in range(len(g[idx])):
                t = val + informTime[idx]
                q.put((g[idx][i], t))
                ans = max(t, ans)
        
        return ans
        
# @lc code=end



#
# @lcpr case=start
# 1\n0\n[-1]\n[0]\n
# @lcpr case=end

# @lcpr case=start
# 6\n2\n[2,2,-1,2,2,2]\n[0,0,1,0,0,0]\n
# @lcpr case=end

#

