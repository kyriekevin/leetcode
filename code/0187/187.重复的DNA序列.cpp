class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> res;
    unordered_map<string, int> cnt;

    int n = s.size();
    for (int i = 0; i <= n - 10; i++) {
      string sub = s.substr(i, 10);
      if (++cnt[sub] == 2)
        res.push_back(sub);
    }

    return res;
  }
};
