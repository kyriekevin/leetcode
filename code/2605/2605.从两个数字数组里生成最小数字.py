class Solution:
    def minNumber(self, nums1: List[int], nums2: List[int]) -> int:
        def same():
            s = set(nums1) & set(nums2)
            return -1 if not s else min(s)
        
        if (x := same()) != -1:
            return x
        
        x, y = min(nums1), min(nums2)

        return min(10 * x + y, 10 * y + x)
