/*
 * @lc app=leetcode.cn id=2309 lang=cpp
 * @lcpr version=21201
 *
 * [2309] 兼具大小写的最好英文字母
 */

// @lc code=start
class Solution {
public:
    string greatestLetter(string s) {
        int lower = 0, upper = 0;
        for (auto ch: s) {
            if (islower(ch))
                lower |= 1 << (ch - 'a');
            else upper |= 1 << (ch - 'A');
        }

        for (int i = 25; i >= 0; i--)
            if (lower & upper & (1 << i))
                return string(1, 'A' + i);
        
        return "";
    }
};
// @lc code=end



/*
// @lcpr case=start
// "lEeTcOdE"\n
// @lcpr case=end

// @lcpr case=start
// "arRAzFif"\n
// @lcpr case=end

// @lcpr case=start
// "AbCdEfGhIjK"\n
// @lcpr case=end

 */


