/*
 * @lc app=leetcode.cn id=1247 lang=cpp
 * @lcpr version=21704
 *
 * [1247] 交换字符使得字符串相同
 */

// @lc code=start
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int cnt[2]{};
        for (int i = 0; i < s1.size(); i++)
            if (s1[i] != s2[i])
                cnt[s1[i] % 2]++;

        int d = cnt[0] + cnt[1];
        return d % 2 ? -1 : d / 2 + cnt[1] % 2;
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
// "xx"\n"yy"\n
// @lcpr case=end

// @lcpr case=start
// "xy"\n"yx"\n
// @lcpr case=end

// @lcpr case=start
// "xx"\n"xy"\n
// @lcpr case=end

// @lcpr case=start
// "xxyyxyxyxx"\n"xyyxyxxxyx"\n
// @lcpr case=end

 */


