class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());
        int presum = 0, res = 0;
        for (int x: satisfaction) {
            if (presum + x > 0) {
                presum += x;
                res += presum;
            }
            else break;
        }

        return res;
    }
};
