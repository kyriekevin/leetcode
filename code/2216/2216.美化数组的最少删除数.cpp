class Solution {
public:
  int minDeletion(vector<int> &nums) {
    int n = nums.size(), res = 0;
    for (int i = 0; i + 1 < n; i++)
      if (nums[i] == nums[i + 1])
        res++;
      else
        i++;

    if ((n - res) % 2)
      res++;

    return res;
  }
};
