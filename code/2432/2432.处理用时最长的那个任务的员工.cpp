/*
 * @lc app=leetcode.cn id=2432 lang=cpp
 * @lcpr version=21907
 *
 * [2432] 处理用时最长的那个任务的员工
 */

// @lc code=start
class Solution
{
public:
    int hardestWorker(int n, vector<vector<int>> &logs)
    {
        int cur = 0, res = 0, idx = n;
        for (int i = 0; i < logs.size(); i++)
        {
            if (logs[i][1] - cur > res)
            {
                res = logs[i][1] - cur;
                idx = logs[i][0];
            }
            else if (logs[i][1] - cur == res)
                idx = min(idx, logs[i][0]);
            cur = logs[i][1];
        }

        return idx;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 10\n[[0,3],[2,5],[0,9],[1,15]]\n
// @lcpr case=end

// @lcpr case=start
// 26\n[[1,1],[3,7],[2,12],[7,17]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[0,10],[1,20]]\n
// @lcpr case=end

 */
