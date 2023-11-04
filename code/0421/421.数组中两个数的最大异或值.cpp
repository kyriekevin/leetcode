class Solution {
public:
  vector<vector<int>> s;

  int query(int x) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--) {
      int u = x >> i & 1;
      if (s[p][!u]) {
        res = 2 * res + !u;
        p = s[p][!u];
      } else {
        res = 2 * res + u;
        p = s[p][u];
      }
    }

    return res ^ x;
  }

  void insert(int x) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
      int u = x >> i & 1;
      if (!s[p][u]) {
        s[p][u] = s.size();
        s.push_back({0, 0});
      }
      p = s[p][u];
    }
  }

  int findMaximumXOR(vector<int> &nums) {
    int res = 0;
    s.push_back({0, 0});

    for (auto x : nums) {
      res = max(res, query(x));
      insert(x);
    }

    return res;
  }
};
