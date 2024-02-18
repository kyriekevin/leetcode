/*
 * @lc app=leetcode.cn id=LCP 30 lang=cpp
 * @lcpr version=30116
 *
 * [LCP 30] 魔塔游戏
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
    int magicTower(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int res = 0;
        long long s = 1, delay = 0;
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
            if (nums[i] < 0) pq.push(nums[i]);
            if (s <= 0) {
                if (pq.empty()) return -1;
                s -= pq.top();
                delay += pq.top();
                pq.pop();
                res++;
            }
        }

        s += delay;

        return s > 0 ? res : -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [100,100,100,-250,-60,-140,-50,-50,100,150]`>\n
// @lcpr case=end

// @lcpr case=start
// [-200,-300,400,0]`>\n
// @lcpr case=end

 */

