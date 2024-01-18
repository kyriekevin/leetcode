#
# @lc app=leetcode.cn id=2744 lang=python3
# @lcpr version=30113
#
# [2744] 最大字符串配对数目
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def maximumNumberOfStringPairs(self, words: List[str]) -> int:
        s = set()
        cnt = 0
        for w in words:
            if w in s:
                cnt += 1
            else:
                s.add(w[::-1])
        return cnt
# @lc code=end



#
# @lcpr case=start
# ["cd","ac","dc","ca","zz"]\n
# @lcpr case=end

# @lcpr case=start
# ["ab","ba","cc"]\n
# @lcpr case=end

# @lcpr case=start
# ["aa","ab"]\n
# @lcpr case=end

#

