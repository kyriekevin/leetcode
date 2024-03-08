/*
 * @lc app=leetcode.cn id=2917 lang=cpp
 * @lcpr version=30118
 *
 * [2917] 找出数组中的 K-or 值
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
    int findKOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(32, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 32; j++) {
                if (nums[i] & (1 << j))
                    cnt[j]++;
            }
        }

        int res = 0;
        for (int i = 0; i < 32; i++) 
            if (cnt[i] >= k)
                res |= (1 << i);
        
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [7,12,9,8,9,15]\n4\n
// @lcpr case=end

// @lcpr case=start
// [2,12,1,11,4,5]\n6\n
// @lcpr case=end

// @lcpr case=start
// [10,8,5,9,11,6,8]\n1\n
// @lcpr case=end

 */

