/*
 * @lc app=leetcode.cn id=674 lang=cpp
 * @lcpr version=30112
 *
 * [674] 最长连续递增序列
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
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 0, cur = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1])
                cur += 1;
            else {
                res = max(res, cur);
                cur = 1;
            }
        }

        return max(cur, res);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,5,4,7]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n
// @lcpr case=end

 */

