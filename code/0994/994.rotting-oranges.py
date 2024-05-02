# @leet start
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        res, cnt = 0, 0
        dx, dy = [0, 0, 1, -1], [1, -1, 0, 0]
        q = deque()

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2:
                    q.append((i, j))
                elif grid[i][j] == 1:
                    cnt += 1

        while len(q):
            res += 1
            sz = len(q)
            for _ in range(sz):
                t = q.popleft()
                for i in range(4):
                    a, b = t[0] + dx[i], t[1] + dy[i]
                    if (
                        a < 0
                        or a >= n
                        or b < 0
                        or b >= m
                        or grid[a][b] == 2
                        or grid[a][b] == 0
                    ):
                        continue
                    q.append((a, b))
                    grid[a][b] = 2
                    cnt -= 1

        return max(0, res - 1) if cnt == 0 else -1


# @leet end

