class Solution {
public:
    bool check(vector<int>& citations, int mid) {
        int cnt = 0;
        for (int x: citations)
            if (x >= mid)
                cnt++;
        return cnt >= mid;
    }

    int hIndex(vector<int>& citations) {
        int l = 0, r = citations.size();
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(citations, mid))
                l = mid;
            else r = mid - 1;
        }

        return l;
    }
};
