/*
 * @lc app=leetcode.cn id=2706 lang=cpp
 * @lcpr version=30112
 *
 * [2706] 购买两块巧克力
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
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        if (prices[0] + prices[1] > money)
            return money;
        return money - prices[0] - prices[1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [3,2,3]\n3\n
// @lcpr case=end

 */

