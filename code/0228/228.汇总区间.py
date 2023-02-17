class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if not nums:
            return []
        res = []
        
        l, r = -1, -1
        for i in range(len(nums)):
            if i == 0:
                l = r = nums[i]
            else:
                if nums[i - 1] + 1 == nums[i]:
                    r = nums[i]
                else:
                    if l == r:
                        res.append(str(l))
                    else:
                        res.append(str(l) + "->" + str(r))
                    l = r = nums[i]
        if l == r:
            res.append(str(l))
        else:
            res.append(str(l) + "->" + str(r))
        
        return res
