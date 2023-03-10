#
# @lc app=leetcode.cn id=1590 lang=python3
# @lcpr version=21801
#
# [1590] 使数组和能被 P 整除
#

# @lc code=start
class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        s = list(accumulate(nums, initial=0))
        x = s[-1] % p
        if x % p == 0:
            return 0
        
        res, n = len(nums), len(nums)
        h = {}
        for i, v in enumerate(s):
            h[v % p] = i
            j = h.get((v - x) % p, -n)
            res = min(res, i - j)
        
        return res if res < n else -1
# @lc code=end

# @lcpr-div-debug-arg-start
# funName=
# paramTypes= []
# returnType=
# @lcpr-div-debug-arg-end


#
# @lcpr case=start
# [3,1,4,2]\n6\n
# @lcpr case=end

# @lcpr case=start
# [6,3,5,2]\n9\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3]\n3\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3]\n7\n
# @lcpr case=end

# @lcpr case=start
# [1000000000,1000000000,1000000000]\n3\n
# @lcpr case=end

#


