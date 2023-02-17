#
# @lc app=leetcode.cn id=982 lang=python3
# @lcpr version=21708
#
# [982] 按位与为零的三元组
#

# @lc code=start
class Solution:
    def countTriplets(self, nums: List[int]) -> int:
        cnt = Counter((x & y) for x in nums for y in nums)
        
        res = 0
        for x in nums:
            for y, k in cnt.items():
                if x & y == 0:
                    res += k
        
        return res
# @lc code=end

# @lcpr-div-debug-arg-start
# funName=
# paramTypes= []
# returnType=
# @lcpr-div-debug-arg-end


#
# @lcpr case=start
# [2,1,3]\n
# @lcpr case=end

# @lcpr case=start
# [0,0,0]\n
# @lcpr case=end

#


