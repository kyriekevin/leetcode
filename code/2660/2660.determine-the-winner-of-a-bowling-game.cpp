/*
 * @lc app=leetcode.cn id=2660 lang=cpp
 * @lcpr version=30112
 *
 * [2660] 保龄球游戏的获胜者
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
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int res1 = 0, res2 = 0, n = player1.size();
        for (int i = 0; i < n; i++) {
            if (i - 1 >= 0 && player1[i - 1] == 10)
                res1 += player1[i];
            else if (i - 2 >= 0 && player1[i - 2] == 10)
                res1 += player1[i];
            res1 += player1[i];
        }
        for (int i = 0; i < n; i++) {
            if (i - 1 >= 0 && player2[i - 1] == 10)
                res2 += player2[i];
            else if (i - 2 >= 0 && player2[i - 2] == 10)
                res2 += player2[i];
            res2 += player2[i];
        }

        int res = 0;
        if (res1 > res2) res = 1;
        else if (res1 < res2) res = 2;
        else res = 0;

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,10,7,9]\n[6,5,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,5,7,6]\n[8,10,10,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,3]\n[4,1]\n
// @lcpr case=end

 */

