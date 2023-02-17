class Solution:
    def countPairs(self, nums: List[int], target: int) -> int:
        nums.sort()
        return sum(bisect_left(nums, target - nums[i], 0, i) for i in range(1, len(nums)))
