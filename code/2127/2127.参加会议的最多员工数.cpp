class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> indeg(n);
        for (int i = 0; i < n; i++)
            indeg[favorite[i]]++;
        
        vector<int> st(n), f(n, 1);
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (!indeg[i])
                q.push(i);
        
        while (q.size()) {
            auto t = q.front();
            st[t] = true;
            q.pop();

            int v = favorite[t];
            f[v] = max(f[v], f[t] + 1);
            indeg[v]--;
            if (!indeg[v])
                q.push(v);
        }

        int ring = 0, tot = 0;
        for (int i = 0; i < n; i++) {
            if (!st[i]) {
                int j = favorite[i];
                if (favorite[j] == i) {
                    tot += f[i] + f[j];
                    st[i] = st[j] = true;
                }
                else {
                    int u = i, cnt = 0;
                    while (true) {
                        cnt++;
                        u = favorite[u];
                        st[u] = true;
                        if (u == i)
                            break;
                    }
                    ring = max(ring, cnt);
                }
            }
        }

        return max(ring, tot);
    }
};
