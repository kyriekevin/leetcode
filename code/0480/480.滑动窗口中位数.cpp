/*
 * @lc app=leetcode.cn id=480 lang=cpp
 * @lcpr version=21401
 *
 * [480] 滑动窗口中位数
 */

// @lc code=start
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using orderd_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
   public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        orderd_set<pair<int, int>> ms;
        vector<double> res;
        for (int i = 0; i < nums.size(); i++) {
            ms.insert({nums[i], i});
            if (ms.size() == k) {
                double m1 = (*ms.find_by_order(k / 2)).first;
                double m2 = (*ms.find_by_order((k - 1) / 2)).first;
                res.push_back((m1 + m2) / 2.0);
                ms.erase({nums[i - k + 1], i - k + 1});
            }
        }
        return res;
    }
};
// @lc code=end




