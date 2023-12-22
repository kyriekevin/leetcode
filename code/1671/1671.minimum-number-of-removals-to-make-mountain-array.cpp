/*
 * @lc app=leetcode.cn id=1671 lang=cpp
 * @lcpr version=30112
 *
 * [1671] 得到山形数组的最少删除次数
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
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++)
                if (nums[j] < nums[i])
                    left[i] = max(left[i], left[j] + 1);
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--)
                if (nums[j] < nums[i])
                    right[i] = max(right[i], right[j] + 1);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (left[i] > 1 && right[i] > 1)
                res = max(res, left[i] + right[i] - 1);
        }
        
        return n - res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,1,5,6,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [9,8,1,7,6,5,4,3,2,1]\n
// @lcpr case=end

 */

