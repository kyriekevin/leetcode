/*
 * @lc app=leetcode.cn id=2735 lang=cpp
 * @lcpr version=30112
 *
 * [2735] 收集巧克力
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
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        int f[n][n];
        
        for (int i = 0; i < n; i++) {
            f[i][0] = nums[i];
            for (int j = 1; j < n; j++)
                f[i][j] = min(f[i][j - 1], nums[(i + j) % n]);
        }

        long long res = LONG_LONG_MAX;
        for (int j = 0; j < n; j++) {
            long long cost = 1LL * x * j;
            for (int i = 0; i < n; i++)
                cost += f[i][j];
            res = min(res, cost);
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [20,1,15]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n4\n
// @lcpr case=end

 */

