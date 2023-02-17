class Solution:
    def countDigits(self, num: int) -> int:
        t, res = num, 0
        while t:
            if num % (t % 10) == 0:
                res += 1
            t //= 10
        
        return res
