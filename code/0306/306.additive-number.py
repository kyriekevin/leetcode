# @leet start
class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        n = len(num)
        for i in range(n):
            for j in range(i + 1, n - 1):
                a, b, c = -1, i, j
                x, y = num[a + 1 : b + 1], num[b + 1 : c + 1]
                if (len(x) > 1 and x[0] == "0") or (len(y) > 1 and y[0] == "0"):
                    continue
                while c < n:
                    z = str(int(x) + int(y))
                    if num[c + 1 : c + 1 + len(z)] != z:
                        break
                    a, b, c = b, c, c + len(z)
                    x, y = y, z
                if c + 1 == n:
                    return True
        return False


# @leet end
