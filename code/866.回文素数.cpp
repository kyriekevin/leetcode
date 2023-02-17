/*
 * @lc app=leetcode.cn id=866 lang=cpp
 * @lcpr version=21401
 *
 * [866] 回文素数
 */

// @lc code=start
class Solution {
public:
    bool check(int n) {
        if (n < 2) return false;
        for (int i = 2; i <= n / i; i++)
            if (n % i == 0) return false;
        
        int t = 0, x = n;
        while (x) {
            t = 10 * t + x % 10;
            x /= 10;
        }
        return t == n;
    }

    int primePalindrome(int n) {
        while (true) {
            if (check(n)) return n;
            n++;
            if (1e7 < n && n < 1e8) n = 1e8;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// 
// @lcpr case=end

// @lcpr case=start
// 
// @lcpr case=end

// @lcpr case=start
// 
// @lcpr case=end

 */


