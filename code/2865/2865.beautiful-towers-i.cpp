/*
 * @lc app=leetcode.cn id=2865 lang=cpp
 * @lcpr version=30113
 *
 * [2865] 美丽塔 I
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
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        stack<int> stk;
        vector<int> left(n, -1), right(n, n);

        for (int i = 0; i < n; i++) {
            int x = maxHeights[i];
            while (stk.size() && maxHeights[stk.top()] > x)
                stk.pop();
            
            if (stk.size()) left[i] = stk.top();
            stk.push(i);
        }

        stk = stack<int>();
        for (int i = n - 1; ~i; i--) {
            int x = maxHeights[i];
            while (stk.size() && maxHeights[stk.top()] >= x)
                stk.pop();
            
            if (stk.size()) right[i] = stk.top();
            stk.push(i);
        }

        ll f[n], g[n];
        for (int i = 0; i < n; i++) {
            int x = maxHeights[i];
            if (i && x >= maxHeights[i - 1])
                f[i] = f[i - 1] + x;
            else {
                int j = left[i];
                f[i] = 1ll * x * (i - j) + (j != -1 ? f[j] : 0);
            }
        }

        for (int i = n - 1; ~i; i--) {
            int x = maxHeights[i];
            if (i < n - 1 && x >= maxHeights[i + 1])
                g[i] = g[i + 1] + x;
            else {
                int j = right[i];
                g[i] = 1ll * x * (j - i) + (j != n ? g[j] : 0);
            }
        }

        ll res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, f[i] + g[i] - maxHeights[i]);
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,3,4,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [6,5,3,9,2,7]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,5,5,2,3]\n
// @lcpr case=end

 */

