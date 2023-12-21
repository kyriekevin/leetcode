/*
 * @lc app=leetcode.cn id=2866 lang=cpp
 * @lcpr version=30112
 *
 * [2866] 美丽塔 II
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
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<long long> suf(n);
        stack<int> st;
        st.push(n);

        long long sufs = 0;
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() > 1 && maxHeights[i] <= maxHeights[st.top()]) {
                int t = st.top();
                st.pop();
                sufs -= (long long) maxHeights[t] * (st.top() - t);
            }

            sufs += (long long) maxHeights[i] * (st.top() - i);
            suf[i] = sufs;
            st.push(i);
        }

        st = stack<int>();
        st.push(-1);
        long long pres = 0, res = 0;
        for (int i = 0; i < n; i++) {
            while (st.size() > 1 && maxHeights[i] <= maxHeights[st.top()]) {
                int t = st.top();
                st.pop();
                pres -= (long long) maxHeights[t] * (t - st.top());
            }

            pres += (long long) maxHeights[i] * (i - st.top());
            res = max(res, pres + suf[i] - maxHeights[i]);
            st.push(i);
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

