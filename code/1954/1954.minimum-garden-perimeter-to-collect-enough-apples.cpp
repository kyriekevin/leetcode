/*
 * @lc app=leetcode.cn id=1954 lang=cpp
 * @lcpr version=30112
 *
 * [1954] 收集足够苹果的最小花园周长
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
    long long minimumPerimeter(long long neededApples) {
        long long n = 1;
        for (; 2 * n * (n + 1) * (2 * n + 1) < neededApples; n++);

        return 8 * n;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 13\n
// @lcpr case=end

// @lcpr case=start
// 1000000000\n
// @lcpr case=end

 */

