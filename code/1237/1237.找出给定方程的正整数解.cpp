/*
 * @lc app=leetcode.cn id=1237 lang=cpp
 * @lcpr version=21505
 *
 * [1237] 找出给定方程的正整数解
 */

// @lc code=start
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& c, int z) {
        vector<vector<int>> res;
        int x = 1, y = 1000;
        while (x <= 1000 && y >=1)
        {
            int t = c.f(x, y);
            if (t > z)
                y--;
            else if (t < z)
                x++;
            else {
                res.push_back({x, y});
                y--, x++;
            }
        }

        return res;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=
// paramTypes= []
// returnType=
// @lcpr-div-debug-arg-end


/*
// @lcpr case=start
// 1\n5\n
// @lcpr case=end

// @lcpr case=start
// 2\n5\n
// @lcpr case=end

 */


