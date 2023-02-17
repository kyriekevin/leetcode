class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        def cal(arr, board):
            res, pre = 0, 0
            for x in arr:
                res = max(x - pre, res)
                pre = x
            return max(res, board - pre)
        
        horizontalCuts.sort()
        verticalCuts.sort()

        return (cal(horizontalCuts, h) * cal(verticalCuts, w)) % (10 ** 9 + 7)
