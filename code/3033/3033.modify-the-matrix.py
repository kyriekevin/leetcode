# @leet start
class Solution:
    def modifiedMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        for i in range(len(matrix[0])):
            mx = max(row[i] for row in matrix)
            for row in matrix:
                if row[i] == -1:
                    row[i] = mx
        return matrix


# @leet end

