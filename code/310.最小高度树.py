#
# @lc app=leetcode.cn id=310 lang=python3
# @lcpr version=21401
#
# [310] 最小高度树
#

# @lc code=start
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        in_degree, connect = [0] * n, defaultdict(list)
        for a, b in edges:
            in_degree[a] += 1
            in_degree[b] += 1
            connect[a].append(b)
            connect[b].append(a)
        nodes = [i for i, v in enumerate(in_degree) if v <= 1]
        while n > 2:
            n -= len(nodes)
            nxt = []
            for node in nodes:
                for other in connect[node]:
                    in_degree[other] -= 1
                    if in_degree[other] == 1:
                        nxt.append(other)
            nodes = nxt
        return nodes

# @lc code=end



#
# @lcpr case=start
# 4\n[[1,0],[1,2],[1,3]]\n
# @lcpr case=end

# @lcpr case=start
# 6\n[[3,0],[3,1],[3,2],[3,4],[5,4]]\n
# @lcpr case=end

#


