const int N = 10;

class Solution {
public:
    int countPoints(string rings) {
        vector<int> st(N);
        int n = rings.size();
        for (int i = 0; i < n; i+= 2) {
            auto ch = rings[i];
            int idx = rings[i + 1] - '0';
            if (ch == 'R') st[idx] |= 1;
            else if (ch == 'G') st[idx] |= 2;
            else st[idx] |= 4;
        }

        int res = 0;
        for (int i = 0; i < N; i++)
            res += st[i] == 7;
        
        return res;
    }
};
