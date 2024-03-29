class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        res = []
        intervals.sort(key=lambda x: x[0])

        for item in intervals:
            if not res or res[-1][1] < item[0]:
                res.append(item)
            else:
                res[-1][1] = max(res[-1][1], item[1])
        
        return res
