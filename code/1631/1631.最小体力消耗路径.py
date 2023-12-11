class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        n, m = len(heights), len(heights[0])
        q = [(0, 0, 0)]
        dist = [0] + [float("inf")] * (m * n - 1)
        st = set()

        while q:
            d, x, y = heapq.heappop(q)
            idx = x * m + y

            if idx in st:
                continue
            if (x, y) == (n - 1, m - 1):
                break

            st.add(idx)
            for a, b in [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)]:
                if (
                    0 <= a < n
                    and 0 <= b < m
                    and max(d, abs(heights[x][y] - heights[a][b])) <= dist[a * m + b]
                ):
                    dist[a * m + b] = max(d, abs(heights[x][y] - heights[a][b]))
                    heapq.heappush(q, (dist[a * m + b], a, b))

        return dist[m * n - 1]
