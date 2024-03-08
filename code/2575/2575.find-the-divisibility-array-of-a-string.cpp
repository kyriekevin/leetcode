/*
 * @lc app=leetcode.cn id=2575 lang=cpp
 * @lcpr version=30118
 *
 * [2575] 找出字符串的可整除数组
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
typedef long long ll;
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> res;
        ll cur = 0;
        for (auto ch: word) {
            cur = (cur * 10 + ch - '0') % m;
            res.push_back(cur == 0 ? 1 : 0);
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "998244353"\n3\n
// @lcpr case=end

// @lcpr case=start
// "1010"\n10\n
// @lcpr case=end

 */

