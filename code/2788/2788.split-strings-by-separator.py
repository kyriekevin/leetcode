#
# @lc app=leetcode.cn id=2788 lang=python3
# @lcpr version=30113
#
# [2788] 按分隔符拆分字符串
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def splitWordsBySeparator(self, words: List[str], separator: str) -> List[str]:
        return [x for x in separator.join(words).split(separator) if x]
# @lc code=end



#
# @lcpr case=start
# ["one.two.three","four.five","six"]\n"."\n
# @lcpr case=end

# @lcpr case=start
# ["$easy$","$problem$"]\n"$"\n
# @lcpr case=end

# @lcpr case=start
# ["|||"]\n"|"\n
# @lcpr case=end

#

