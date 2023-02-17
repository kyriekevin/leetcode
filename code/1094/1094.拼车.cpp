class Solution {
public:
  bool carPooling(vector<vector<int>> &trips, int capacity) {
    vector<int> b(1001);
    for (auto t : trips) {
      b[t[1]] += t[0];
      b[t[2]] -= t[0];
    }

    int sum = 0;
    for (int i = 0; i <= 1000; i++) {
      sum += b[i];
      if (sum > capacity)
        return false;
    }

    return true;
  }
};
