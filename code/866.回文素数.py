#
# @lc app=leetcode.cn id=866 lang=python3
# @lcpr version=21401
#
# [866] 回文素数
#

# @lc code=start
class Solution:
    def primePalindrome(self, n: int) -> int:
        def is_prime(n):
            return n > 1 and all(n % x for x in range(2, int(n ** 0.5) + 1))
        
        def reverse(x):
            res = 0
            while x:
                res = 10 * res + x % 10
                x //= 10
            
            return res
        
        while True:
            if n == reverse(n) and is_prime(n):
                return n
            n += 1
            if 10 ** 7 < n < 10 ** 8:
                n = 10 ** 8
# @lc code=end



#
# @lcpr case=start
# 
# @lcpr case=end

# @lcpr case=start
# 
# @lcpr case=end

# @lcpr case=start
# 
# @lcpr case=end

#


