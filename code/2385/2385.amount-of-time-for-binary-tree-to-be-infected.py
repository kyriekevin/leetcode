# @leet start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        graph = defaultdict(list)

        def dfs(node):
            for child in [node.left, node.right]:
                if child:
                    graph[node.val].append(child.val)
                    graph[child.val].append(node.val)
                    dfs(child)

        dfs(root)
        q = deque([[start, 0]])
        st = {start}
        res = 0

        while len(q):
            node, cnt = q.popleft()
            for child in graph[node]:
                if child not in st:
                    st.add(child)
                    q.append([child, cnt + 1])
            res = max(res, cnt)

        return res


# @leet end
