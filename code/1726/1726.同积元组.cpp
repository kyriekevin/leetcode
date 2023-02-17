class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size(), res = 0;
        unordered_map<int, int> cnt;

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                cnt[nums[i] * nums[j]]++;
        
        for (auto &[k, v]: cnt)
            res += v * (v - 1) * 4;
        
        return res;
    }
};
