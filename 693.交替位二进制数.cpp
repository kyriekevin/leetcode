/*
 * @lc app=leetcode.cn id=693 lang=cpp
 * @lcpr version=21401
 *
 * [693] 交替位二进制数
 */

// @lc code=start
class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long x = n ^ (n >> 1);
        return (x & (x + 1)) == 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 7\n
// @lcpr case=end

// @lcpr case=start
// 11\n
// @lcpr case=end

 */


