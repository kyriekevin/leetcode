# @leet start
class Solution:
    def maximumPrimeDifference(self, nums: List[int]) -> int:
        primes = lambda n: n >= 2 and all(n % i for i in range(2, isqrt(n) + 1))
        i, j = 0, len(nums) - 1
        while not primes(nums[i]):
            i += 1
        while not primes(nums[j]):
            j -= 1
        return j - i


# @leet end
