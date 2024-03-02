/*
 * @lc app=leetcode.cn id=2368 lang=cpp
 * @lcpr version=30117
 *
 * [2368] 受限条件下可到达节点的数目
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
class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> st(n);
        for (auto x: restricted)
            st[x] = 1;
        
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int cnt = 0;
        function<void(int, int)> dfs = [&](int u, int fa) {
            cnt++;
            for (auto &v: g[u]) {
                if (v == fa || st[v]) continue;
                dfs(v, u);
            }
        };

        dfs(0, -1);

        return cnt;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 7\n[[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]]\n[4,5]\n
// @lcpr case=end

// @lcpr case=start
// 7\n[[0,1],[0,2],[0,5],[0,4],[3,2],[6,5]]\n[4,2,1]\n
// @lcpr case=end

 */

