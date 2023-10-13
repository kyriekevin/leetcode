class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> res(rains.size(), 1);
        set<int> s;
        unordered_map<int, int> mp;

        for (int i = 0; i < rains.size(); i++) {
            if (rains[i] == 0) s.insert(i);
            else {
                res[i] = -1;
                if (mp.count(rains[i])) {
                    auto it = s.lower_bound(mp[rains[i]]);
                    if (it == s.end()) return {};
                    res[*it] = rains[i];
                    s.erase(it);
                }
                mp[rains[i]] = i;
            }
        }

        return res;
    }
};
