# @leet start
class Solution:
    def baseNeg2(self, n: int) -> str:
        if n == 0:
            return "0"

        res = []
        while n:
            t = n & 1
            res.append(t)
            n = (n - t) // -2

        return "".join(map(str, res[::-1]))


# @leet end
