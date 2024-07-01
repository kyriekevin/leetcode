/*
 * @lc app=leetcode.cn id=2065 lang=cpp
 * @lcpr version=30204
 *
 * [2065] 最大化一张图中的路径价值
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
typedef pair<int, int> PII;
#define x first
#define y second

class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<vector<PII>> g(n);
        for (auto &e: edges) {
            int a = e[0], b = e[1], c = e[2];
            g[a].emplace_back(b, c);
            g[b].emplace_back(a, c);
        }        

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        priority_queue<PII, vector<PII>, greater<>> pq;
        pq.emplace(0, 0);

        while (pq.size()) {
            auto [dx, u] = pq.top();
            pq.pop();

            if (dx > dist[u]) continue;

            for (auto &[y, d]: g[u]) {
                if (dist[y] > dist[u] + d) {
                    dist[y] = dist[u] + d;
                    pq.emplace(dist[y], y);
                }
            }
        }

        int res = 0;
        vector<bool> st(n);
        st[0] = true;

        auto dfs = [&](auto &&dfs, int x, int sum_t, int sum_v) -> void {
            if (x == 0)
                res = max(res, sum_v);
            
            for (auto &[y, t]: g[x]) {
                if (sum_t + t + dist[y] > maxTime) continue;

                if (st[y])
                    dfs(dfs, y, sum_t + t, sum_v);
                else {
                    st[y] = true;
                    dfs(dfs, y, sum_t + t, sum_v + values[y]);
                    st[y] = false;
                }
            }
        };

        dfs(dfs, 0, 0, values[0]);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,32,10,43]\n[[0,1,10],[1,2,15],[0,3,10]]\n49\n
// @lcpr case=end

// @lcpr case=start
// [5,10,15,20]\n[[0,1,10],[1,2,10],[0,3,10]]\n30\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n[[0,1,10],[1,2,11],[2,3,12],[1,3,13]]\n50\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2]\n[[1,2,10]]\n10\n
// @lcpr case=end

 */

