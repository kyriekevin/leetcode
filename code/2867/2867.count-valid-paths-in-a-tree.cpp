/*
 * @lc app=leetcode.cn id=2867 lang=cpp
 * @lcpr version=30117
 *
 * [2867] 统计树中的合法路径数目
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
const int N = 1e5 + 10;
typedef long long ll;

bool prime[N];
int init = []() {
    prime[1] = true;
    for (int i = 2; i * i < N; i++) {
        if (prime[i]) continue;
        for (int j = i * i; j < N; j += i) {
            prime[j] = true;
        }
    }

    return 0;
}();

class Solution {
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n + 1);
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<int> nodes;
        function<void(int, int)> dfs = [&](int u, int fa) {
            nodes.push_back(u);
            for (auto v: g[u]) {
                if (v == fa || !prime[v]) continue;
                dfs(v, u);
            }
        };

        vector<int> sz(n + 1);
        long long res = 0;
        for (int i = 1; i <= n; i++) {
            if (prime[i]) continue;

            int tot = 0;
            for (auto v: g[i]) {
                if (!prime[v]) continue;
                if (sz[v] == 0) {
                    nodes.clear();
                    dfs(v, -1);
                    for (auto node: nodes)
                        sz[node] = nodes.size();
                }
                
                res += (ll) sz[v] * tot;
                tot += sz[v];
            }

            res += tot;
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n[[1,2],[1,3],[2,4],[2,5]]\n
// @lcpr case=end

// @lcpr case=start
// 6\n[[1,2],[1,3],[2,4],[3,5],[3,6]]\n
// @lcpr case=end

 */

