# @leet start
class Solution:
    def checkMove(
        self, board: List[List[str]], rMove: int, cMove: int, color: str
    ) -> bool:
        n, m = len(board), len(board[0])
        dx = [-1, 0, 1, 1, 1, 0, -1, -1]
        dy = [-1, -1, -1, 0, 1, 1, 1, 0]

        for x, y in zip(dx, dy):
            a, b = rMove + x, cMove + y
            if a < 0 or a >= n or b < 0 or b >= m:
                continue
            if board[a][b] == color or board[a][b] == ".":
                continue

            while True:
                a += x
                b += y
                if a < 0 or a >= n or b < 0 or b >= m or board[a][b] == ".":
                    break
                if board[a][b] == color:
                    return True

        return False


# @leet end
