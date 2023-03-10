/*
 * @lc app=leetcode.cn id=2379 lang=cpp
 * @lcpr version=21801
 *
 * [2379] 得到 K 个黑块的最少涂色次数
 */

// @lc code=start
class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int res = k, n = blocks.size();
        for (int i = 0; i + k <= n; i++)
        {
            int cnt = 0;
            for (int j = i; j < i + k; j++)
                if (blocks[j] == 'W')
                    cnt++;
            res = min(cnt, res);
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
// "WBBWWBBWBW"\n7\n
// @lcpr case=end

// @lcpr case=start
// "WBWBBBW"\n2\n
// @lcpr case=end

 */
