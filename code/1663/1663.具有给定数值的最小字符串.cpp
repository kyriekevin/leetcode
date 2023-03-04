/*
 * @lc app=leetcode.cn id=1663 lang=cpp
 * @lcpr version=21115
 *
 * [1663] 具有给定数值的最小字符串
 */

// @lc code=start
class Solution {
public:
    string getSmallestString(int n, int k) {
        string res;
        for (int i = 0, s = 0; i < n; i++) {
            for (int j = 1; j <= 26; j++) {
                int last = k - s - j, m = n - i - 1;
                if (last >= m && last <= 26 * m) {
                    res += j + 'a' - 1;
                    s += j;
                    break;
                }
            }
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n27\n
// @lcpr case=end

// @lcpr case=start
// 5\n73\n
// @lcpr case=end

 */


