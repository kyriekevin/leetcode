#
# @lc app=leetcode.cn id=1696 lang=python3
# @lcpr version=30115
#
# [1696] 跳跃游戏 VI
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def maxResult(self, nums: List[int], k: int) -> int:
        n = len(nums)
        f = [0] * n
        f[0] = nums[0]
        q = deque([0])
        
        for i in range(1, n):
            while q and q[0] < i - k:
                q.popleft()
            f[i] = f[q[0]] + nums[i]
            while q and f[i] >= f[q[-1]]:
                q.pop()
            q.append(i) 
        return f[-1]
# @lc code=end



#
# @lcpr case=start
# [1,-1,-2,4,-7,3]\n2\n
# @lcpr case=end

# @lcpr case=start
# [10,-5,-2,4,0,3]\n3\n
# @lcpr case=end

# @lcpr case=start
# [1,-5,-20,4,-1,3,-6,-3]\n2\n
# @lcpr case=end

#

