/*
 * @lc app=leetcode.cn id=2670 lang=cpp
 * @lcpr version=30114
 *
 * [2670] 找出不同元素数目差数组
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
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        vector<int> suf(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            suf[i] = st.size();
            st.insert(nums[i]);
        }

        vector<int> res(n, 0);
        st.clear();
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
            res[i] = st.size() - suf[i];
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,3,4,2]\n
// @lcpr case=end

 */

