# @leet start
class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        n, m = len(mat), len(mat[0])
        diag = [[] for _ in range(m + n)]
        for i in range(n):
            for j in range(m):
                diag[i - j + m].append(mat[i][j])
        for d in diag:
            d.sort(reverse=True)
        for i in range(n):
            for j in range(m):
                mat[i][j] = diag[i - j + m].pop()
        return mat


# @leet end
