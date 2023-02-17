class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());
        long long res = 0;
        while(k--) {
            int x = q.top();
            q.pop();
            res += x;
            q.push((x + 2) / 3);
        }

        return res;
    }
};
