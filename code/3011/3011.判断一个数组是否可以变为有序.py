#
# @lc app=leetcode.cn id=3011 lang=python3
#
# [3011] 判断一个数组是否可以变为有序
#

# @lc code=start
class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        n = len(nums)
        minv, maxv, cnt, last_cnt = 'inf', '-inf', 0, 0
        arr = []

        def bitset(x):
            res = 0
            while x:
                x -= x & -x
                res += 1
            return res

        for i in range(n):
            if i == 0:
                last_cnt = bitset(nums[i])
                cnt = last_cnt
                minv = maxv = nums[i]
            else:
                cnt = bitset(nums[i])
                if cnt == last_cnt:
                    minv = min(minv, nums[i])
                    maxv = max(maxv, nums[i])
                else:
                    if nums[i] < maxv:
                        return False
                    arr.append((minv, maxv))
                    minv = maxv = nums[i]
                last_cnt = cnt
        arr.append((minv, maxv))
        
        for i in range(len(arr)):
            if i == 0:
                minv, maxv = arr[i]
            else:
                l, r = arr[i]
                if l > maxv:
                    maxv = r
                else:
                    return False
        
        return True
# @lc code=end

