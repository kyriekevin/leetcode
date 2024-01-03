/*
 * @lc app=leetcode.cn id=697 lang=cpp
 * @lcpr version=30112
 *
 * [697] 数组的度
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
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> cnt, minp, maxp;
        int d = 0;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            d = max(d, ++cnt[x]);
            if (!minp.count(x)) minp[x] = i;
            maxp[x] = i;
        }

        int res = nums.size();
        for (auto x: nums)
            if (cnt[x] == d)
                res = min(res, maxp[x] - minp[x] + 1);
        
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,3,1,4,2]\n
// @lcpr case=end

 */

