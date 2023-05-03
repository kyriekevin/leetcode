/*
 * @lc app=leetcode.cn id=1003 lang=cpp
 * @lcpr version=21907
 *
 * [1003] 检查替换后的词是否有效
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        string stk = "";
        for (auto ch : s)
        {
            stk += ch;
            if (stk.size() >= 3 && stk.substr(stk.size() - 3, 3) == "abc")
                stk = stk.substr(0, stk.size() - 3);
        }

        return stk.empty();
    }
};
// @lc code=end

/*
// @lcpr case=start
// "aabcbc"\n
// @lcpr case=end

// @lcpr case=start
// "abcabcababcc"\n
// @lcpr case=end

// @lcpr case=start
// "abccba"\n
// @lcpr case=end

 */
