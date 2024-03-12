#
# @lc app=leetcode.cn id=2129 lang=python3
# @lcpr version=30119
#
# [2129] 将标题首字母大写
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def capitalizeTitle(self, title: str) -> str:
        return ' '.join(w.lower() if len(w) < 3 else w.title() for w in title.split())
# @lc code=end



#
# @lcpr case=start
# "capiTalIze tHe titLe"\n
# @lcpr case=end

# @lcpr case=start
# "First leTTeR of EACH Word"\n
# @lcpr case=end

# @lcpr case=start
# "i lOve leetcode"\n
# @lcpr case=end

#

