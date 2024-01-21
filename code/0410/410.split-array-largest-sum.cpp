/*
 * @lc app=leetcode.cn id=410 lang=cpp
 * @lcpr version=30113
 *
 * [410] 分割数组的最大值
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
    bool check(vector<int>& nums, int k, int x) {
        int sum = 0, cnt = 0;
        for (auto n: nums) {
            if (n > x) return false;
            if (sum + n > x) {
                cnt++;
                sum = n;
            }
            else sum += n;
        }
        if (sum) cnt++;

        return cnt <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int l = 0, r = INT_MAX;
        while (l < r) {
            int mid = (long long)(l + r) / 2;
            if (check(nums, k, mid)) r = mid;
            else l = mid + 1;
        }

        return l;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [7,2,5,10,8]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,4,4]\n3\n
// @lcpr case=end

 */

