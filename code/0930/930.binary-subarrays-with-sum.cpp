/*
 * @lc app=leetcode.cn id=930 lang=cpp
 * @lcpr version=30113
 *
 * [930] 和相同的二元子数组
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
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> s(n + 1, 0), f(n + 1, 0);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
        f[0] = 1;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int cur = s[i];
            if (cur >= goal) res += f[cur - goal];
            f[cur]++;
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,1,0,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0,0,0]\n0\n
// @lcpr case=end

 */

