#
# @lc app=leetcode.cn id=3132 lang=python3
#
# [3132] 找出与数组相加的整数 II
#

# @lc code=start
class Solution:
    def minimumAddedInteger(self, nums1: List[int], nums2: List[int]) -> int:
        nums1.sort()
        nums2.sort()
        
        for i in range(2, 0, -1):
            x = nums2[0] - nums1[i]
            j = 0
            for v in nums1[i:]:
                if v + x == nums2[j]:
                    j += 1
                    if j == len(nums2):
                        return x
        return nums2[0] - nums1[0]
# @lc code=end

