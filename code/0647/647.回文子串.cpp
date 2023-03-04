/*
 * @lc app=leetcode.cn id=647 lang=cpp
 * @lcpr version=21706
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int res = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            for (int j = i, k = i; j >= 0 && k < n; j--, k++) {
                if (s[j] != s[k])
                    break;
                res++;
            }

            for (int j = i, k = i + 1; j >= 0 && k < n; j--, k++) {
                if (s[j] != s[k])
                    break;
                res++;
            }
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
// "abc"\n
// @lcpr case=end

// @lcpr case=start
// "aaa"\n
// @lcpr case=end

 */


