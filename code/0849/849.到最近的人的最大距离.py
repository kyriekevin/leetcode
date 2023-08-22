class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        res, l, n = 0, 0, len(seats)

        while l < n and seats[l] == 0:
            l += 1
        res = max(res, l)

        while l < n:
            r = l + 1
            while r < n and seats[r] == 0:
                r += 1
            
            if r == len(seats):
                res = max(res, r - l - 1)
            else:
                res = max(res, (r - l) // 2)
            
            l = r
        
        return res
