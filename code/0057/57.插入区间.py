class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        res = []
        i, n = 0, len(intervals)
        l, r = newInterval[0], newInterval[1]

        while i < n and l > intervals[i][1]:
            res.append(intervals[i])
            i += 1
        
        while i < n and r >= intervals[i][0]:
            l = min(l, intervals[i][0])
            r = max(r, intervals[i][1])
            i += 1
        res.append([l, r])

        res += intervals[i:]

        return res
                
