class Solution {
public:
  int maximumSum(vector<int> &nums) {
    int res = -1;
    unordered_map<int, int> h;
    for (auto num : nums) {
      int x = 0;
      for (auto v = num; v; v /= 10)
        x += v % 10;
      if (h[x])
        res = max(res, h[x] + num);
      h[x] = max(h[x], num);
    }

    return res;
  }
};
