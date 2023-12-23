/*
 * @lc app=leetcode.cn id=1962 lang=cpp
 * @lcpr version=30112
 *
 * [1962] 移除石子使总数最小
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
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q(piles.begin(), piles.end());
        for (int i = 0; i < k; i++) {
            int t = q.top();
            q.pop();
            t -= t / 2;
            q.push(t);
        }

        int res = 0;
        while (q.size()) {
            res += q.top();
            q.pop();
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,4,9]\n2\n
// @lcpr case=end

// @lcpr case=start
// [4,3,6,7]\n3\n
// @lcpr case=end

 */

