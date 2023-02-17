#
# @lc app=leetcode.cn id=480 lang=python3
# @lcpr version=21401
#
# [480] 滑动窗口中位数
#

# @lc code=start
import bisect

class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        median = lambda a: (a[(len(a) - 1) // 2] + a[len(a) // 2]) / 2
        a = sorted(nums[: k])
        res = [median(a)]
        for i, j in zip(nums[: -k], nums[k:]):
            a.pop(bisect.bisect_left(a, i))
            bisect.insort_left(a, j)
            res.append(median(a))
        return res

# @lc code=end




