typedef long long LL;

class Solution {
public:
  long long minimumFuelCost(vector<vector<int>> &roads, int seats) {
    int n = roads.size();
    vector<vector<int>> g(n + 1);

    for (auto &e : roads) {
      g[e[0]].emplace_back(e[1]);
      g[e[1]].emplace_back(e[0]);
    }

    LL res = 0;
    function<int(int, int)> dfs = [&](int cur, int f) -> int {
      int psum = 1;
      for (auto e : g[cur]) {
        if (e == f)
          continue;
        int pcnt = dfs(e, cur);
        psum += pcnt;
        res += (pcnt + seats - 1) / seats;
      }

      return psum;
    };

    dfs(0, -1);

    return res;
  }
};
