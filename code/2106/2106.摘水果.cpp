/*
 * @lc app=leetcode.cn id=2106 lang=cpp
 * @lcpr version=21907
 *
 * [2106] 摘水果
 */

// @lc code=start
class Solution
{
public:
    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k)
    {
        int n = fruits.size();
        int m = n;

        for (int i = 0; i < n; i++)
        {
            if (fruits[i][0] > startPos)
            {
                m = i;
                break;
            }
        }

        int lcnt = 0, rcnt = 0;
        for (int i = m; i < n; i++)
            rcnt += fruits[i][1];

        int ans = 0;
        for (int i = m - 1, j = n - 1; i >= 0; i--)
        {
            int lp = startPos - fruits[i][0];
            if (lp > k)
                break;
            lcnt += fruits[i][1];

            while (j >= m && fruits[j][0] - fruits[i][0] > k - lp)
            {
                rcnt -= fruits[j][1];
                j--;
            }

            ans = max(ans, lcnt + rcnt);
        }

        lcnt = 0, rcnt = 0;
        for (int i = 0; i < m; i++)
            lcnt += fruits[i][1];

        for (int i = 0, j = m; j < n; j++)
        {
            int rp = fruits[j][0] - startPos;
            if (rp > k)
                break;
            rcnt += fruits[j][1];

            while (i < m && fruits[j][0] - fruits[i][0] > k - rp)
            {
                lcnt -= fruits[i][1];
                i++;
            }

            ans = max(ans, lcnt + rcnt);
        }

        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[2,8],[6,3],[8,6]]\n5\n4\n
// @lcpr case=end

// @lcpr case=start
// [[0,9],[4,1],[5,7],[6,2],[7,4],[10,9]]\n5\n4\n
// @lcpr case=end

// @lcpr case=start
// [[0,3],[6,4],[8,5]]\n3\n2\n
// @lcpr case=end

 */
