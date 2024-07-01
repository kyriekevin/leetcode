# @leet start
class Solution:
    def sumOfTheDigitsOfHarshadNumber(self, x: int) -> int:
        s = 0
        v = x
        while v:
            v, d = divmod(v, 10)
            s += d
        return -1 if x % s else s


# @leet end

