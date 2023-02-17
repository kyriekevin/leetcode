class Solution:
    def captureForts(self, forts: List[int]) -> int:
        res, s, cnt = 0, 0, 0
        for x in forts:
            if x != 0:
                if s + x == 0:
                    res = max(res, cnt)
                s = x
                cnt = 0
            else:
                cnt += 1
        
        return res
