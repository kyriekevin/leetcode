/*
 * @lc app=leetcode.cn id=1276 lang=cpp
 * @lcpr version=30112
 *
 * [1276] 不浪费原料的汉堡制作方案
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
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int x = tomatoSlices - 2 * cheeseSlices;
        if (x < 0 || x % 2) return {};
        int y = x / 2;
        if (y > cheeseSlices) return {};

        return {y, cheeseSlices - y};
    }
};
// @lc code=end



/*
// @lcpr case=start
// 16\n7\n
// @lcpr case=end

// @lcpr case=start
// 17\n4\n
// @lcpr case=end

// @lcpr case=start
// 4\n17\n
// @lcpr case=end

// @lcpr case=start
// 0\n0\n
// @lcpr case=end

// @lcpr case=start
// 2\n1\n
// @lcpr case=end

 */

