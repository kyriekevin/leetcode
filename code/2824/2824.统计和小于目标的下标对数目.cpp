class Solution {
public:
  int countPairs(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int res = 0;
    for (int i = 0, j = nums.size() - 1; i < j; i++) {
      while (i < j && nums[i] + nums[j] >= target)
        j--;
      res += j - i;
    }

    return res;
  }
};
