/*
 * @lc app=leetcode.cn id=1129 lang=cpp
 * @lcpr version=21401
 *
 * [1129] 颜色交替的最短路径
 */

// @lc code=start
#define x first
#define y second

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        const int INF = 1e8;
        vector<vector<pair<int, int>>> g(n);
        for (auto& p: redEdges) g[p[0]].push_back({p[1], 0});
        for (auto& p: blueEdges) g[p[0]].push_back({p[1], 1});

        vector<vector<int>> dist(n, vector<int>(2, INF));
        dist[0][0] = dist[0][1] = 0;
        queue<pair<int, int>> q;
        q.push({0, 0}), q.push({0, 1});

        while (q.size()) {
            auto t = q.front();
            q.pop();

            for (auto& p: g[t.x]) {
                if (t.y != p.y && dist[p.x][p.y] > dist[t.x][t.y] + 1) {
                    dist[p.x][p.y] = dist[t.x][t.y] + 1;
                    q.push(p);
                }
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i ++ ) {
            res.push_back(min(dist[i][0], dist[i][1]));
            if (res[i] == INF) res[i] = -1;
        }

        return res;
    }
};

// @lc code=end



/*
// @lcpr case=start
// 3\n[[0,1],[1,2]]\n[]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[0,1]]\n[[2,1]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[1,0]]\n[[2,1]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[0,1]]\n[[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[0,1],[0,2]]\n[[1,0]]\n
// @lcpr case=end

 */


