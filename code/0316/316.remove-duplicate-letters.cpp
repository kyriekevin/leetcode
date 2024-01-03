/*
 * @lc app=leetcode.cn id=316 lang=cpp
 * @lcpr version=30112
 *
 * [316] 去除重复字母
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26, -1);
        vector<char> stk;
        vector<bool> st(26, false);
        int n = s.size();

        for (int i = 0; i < n; i++)
            last[s[i] - 'a'] = i;
        
        for (int i = 0; i < n; i++) {
            if (st[s[i] - 'a'])
                continue;
            
            while (stk.size() && stk.back() > s[i]) {
                if (last[stk.back() - 'a'] < i)
                    break;
                st[stk.back() - 'a'] = false;
                stk.pop_back();
            }

            stk.push_back(s[i]);
            st[s[i] - 'a'] = true;
        }

        string res;
        for (auto ch: stk)
            res += ch;

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "bcabc"\n
// @lcpr case=end

// @lcpr case=start
// "cbacdcbc"\n
// @lcpr case=end

 */

