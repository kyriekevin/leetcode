#
# @lc app=leetcode.cn id=2289 lang=python3
# @lcpr version=21705
#
# [2289] 使数组按非递减顺序排列
#

# @lc code=start
class Solution:
    def totalSteps(self, nums: List[int]) -> int:
        st = []
        for x in nums[::-1]:
            cnt = 0
            while st and st[-1][0] < x:
                cnt = max(cnt + 1, st.pop()[1])
            st.append([x, cnt])
        
        return max(res for _, res in st)
# @lc code=end

# @lcpr-div-debug-arg-start
# funName=
# paramTypes= []
# returnType=
# @lcpr-div-debug-arg-end


#
# @lcpr case=start
# [5,3,4,4,7,3,6,11,8,5,11]\n
# @lcpr case=end

# @lcpr case=start
# [4,5,7,7,13]\n
# @lcpr case=end

#


