class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> visit(n, false);
        for (int i = k, j = 0; !visit[j]; i += k) {
            visit[j] = true;
            j = (j + i) % n;
        }

        vector<int> res;
        for (int i = 0; i < n; i++)
            if (!visit[i])
                res.emplace_back(i + 1);
        
        return res;
    }
};
