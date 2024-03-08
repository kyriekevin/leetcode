/*
 * @lc app=leetcode.cn id=1976 lang=cpp
 * @lcpr version=30118
 *
 * [1976] 到达目的地的方案数
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
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, int> PLI;
const int MOD = 1e9 + 7;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<PII>> g(n);
        for (auto &r: roads) {
            int x = r[0], y = r[1], d = r[2];
            g[x].emplace_back(y, d);
            g[y].emplace_back(x, d);
        }

        vector<ll> dist(n, LLONG_MAX);
        vector<int> f(n);
        priority_queue<PLI, vector<PLI>, greater<>> q;

        dist[0] = 0;
        f[0] = 1; 
        q.emplace(0, 0);

        while (q.size()) {
            auto [dx, x] = q.top();
            q.pop();

            if (x == n - 1) break;
            if (dx > dist[x]) continue;

            for (auto [y, dy]: g[x]) {
                if (dist[y] > dx + dy) {
                    dist[y] = dx + dy;
                    f[y] = f[x];
                    q.emplace(dist[y], y);
                }
                else if (dist[y] == dx + dy)
                    f[y] = (f[y] + f[x]) % MOD;
            }
        }
        
        return f[n - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 7\n[[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[1,0,10]]\n
// @lcpr case=end

 */

