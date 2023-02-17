/*
 * @lc app=leetcode.cn id=1653 lang=cpp
 * @lcpr version=21801
 *
 * [1653] 使字符串平衡的最少删除次数
 */

// @lc code=start
class Solution {
public:
    int minimumDeletions(string s) {
        int del = 0;
        for (char ch: s)
            del += 'b' - ch;

        int res = del;
        for (char ch: s) {
            del += (ch - 'a') * 2 - 1;
            res = min(del, res);
        }

        return res;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=
// paramTypes= []
// returnType=
// @lcpr-div-debug-arg-end


/*
// @lcpr case=start
// "aababbab"\n
// @lcpr case=end

// @lcpr case=start
// "bbaaaaabb"\n
// @lcpr case=end

 */


