/*
 * @lc app=leetcode.cn id=1376 lang=cpp
 * @lcpr version=21907
 *
 * [1376] 通知所有员工所需的时间
 */

// @lc code=start
typedef pair<int, int> PII;
#define x first
#define y second

class Solution
{
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        unordered_map<int, vector<int>> g;
        for (int i = 0; i < n; i++)
            g[manager[i]].emplace_back(i);

        queue<PII> q;
        q.push({headID, 0});

        int ans = 0;
        while (q.size())
        {
            auto t = q.front();
            q.pop();

            for (int i = 0; i < g[t.x].size(); i++)
            {
                int val = t.y + informTime[t.x];
                q.push({g[t.x][i], val});
                ans = max(ans, val);
            }
        }

        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 1\n0\n[-1]\n[0]\n
// @lcpr case=end

// @lcpr case=start
// 6\n2\n[2,2,-1,2,2,2]\n[0,0,1,0,0,0]\n
// @lcpr case=end

 */
