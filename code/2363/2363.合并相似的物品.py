#
# @lc app=leetcode.cn id=2363 lang=python3
# @lcpr version=21706
#
# [2363] 合并相似的物品
#

# @lc code=start
class Solution:
    def mergeSimilarItems(self, items1: List[List[int]], items2: List[List[int]]) -> List[List[int]]:
        map = Counter()
        for a, b in items1:
            map[a] += b
        
        for a, b in items2:
            map[a] += b
        
        return sorted([a, b] for a, b in map.items())
# @lc code=end

# @lcpr-div-debug-arg-start
# funName=
# paramTypes= []
# returnType=
# @lcpr-div-debug-arg-end


#
# @lcpr case=start
# [[1,1],[4,5],[3,8]]\n[[3,1],[1,5]]\n
# @lcpr case=end

# @lcpr case=start
# [[1,1],[3,2],[2,3]]\n[[2,1],[3,2],[1,3]]\n
# @lcpr case=end

# @lcpr case=start
# [[1,3],[2,2]]\n[[7,1],[2,2],[1,4]]\n
# @lcpr case=end

#


