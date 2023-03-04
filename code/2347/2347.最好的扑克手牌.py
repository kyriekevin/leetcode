#
# @lc app=leetcode.cn id=2347 lang=python3
# @lcpr version=21704
#
# [2347] 最好的扑克手牌
#

# @lc code=start
class Solution:
    def bestHand(self, ranks: List[int], suits: List[str]) -> str:
        if len(set(suits)) == 1:
            return "Flush"
        
        cnt = Counter(ranks)
        if len(cnt) == 5:
            return "High Card"
        for [_, b] in cnt.items():
            if b > 2:
                return "Three of a Kind"
        
        return "Pair"
# @lc code=end

# @lcpr-div-debug-arg-start
# funName=
# paramTypes= []
# returnType=
# @lcpr-div-debug-arg-end


#
# @lcpr case=start
# [13,2,3,1,9]\n["a","a","a","a","a"]\n
# @lcpr case=end

# @lcpr case=start
# [4,4,2,4,4]\n["d","a","a","b","c"]\n
# @lcpr case=end

# @lcpr case=start
# [10,10,2,12,9]\n["a","b","c","a","d"]\n
# @lcpr case=end

#


