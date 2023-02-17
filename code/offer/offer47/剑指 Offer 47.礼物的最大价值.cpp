/*
 * @lc app=leetcode.cn id=剑指 Offer 47 lang=cpp
 * @lcpr version=21801
 *
 * [剑指 Offer 47] 礼物的最大价值
 */

// @lc code=start
class Solution
{
public:
    int maxValue(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> f(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                    f[i][j] = grid[i][j];
                if (i)
                    f[i][j] = max(f[i][j], f[i - 1][j] + grid[i][j]);
                if (j)
                    f[i][j] = max(f[i][j], f[i][j - 1] + grid[i][j]);
            }
        }

        return f[n - 1][m - 1];
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
// 
// @lcpr case=end

 */


