class Solution {
public:
  int vowelStrings(vector<string> &words, int left, int right) {
    set<char> s{'a', 'e', 'i', 'o', 'u'};
    int res = 0;
    for (; left <= right; left++)
      res += (s.count(words[left].front()) && s.count(words[left].back()));

    return res;
  }
};
