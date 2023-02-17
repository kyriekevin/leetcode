class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        graph = [[] for _ in range(n)]
        for x, y in edges:
            graph[x].append(y)
            graph[y].append(x)
        
        visited = [False] * n
        def dfs(x):
            visited[x] = True
            cnt = 1
            for y in graph[x]:
                if not visited[y]:
                    cnt += dfs(y)
            return cnt
        
        res = 0
        for i in range(n):
            if not visited[i]:
                cnt = dfs(i)
                res += cnt * (n - cnt)
        
        return res // 2
