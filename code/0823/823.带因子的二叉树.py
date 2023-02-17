class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        @cache
        def dfs(num):
            res = 1
            for i in range(len(arr)):
                if arr[i] >= num:
                    break
                
                div = num / arr[i]
                if div in s:
                    res += dfs(div) * dfs(arr[i]) % (10 ** 9 + 7)
            
            return res
        
        arr = sorted(arr)
        s = set(arr)

        res = 0
        for x in arr:
            res += dfs(x)
        
        return res % (10 ** 9 + 7)
