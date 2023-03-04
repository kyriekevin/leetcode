/*
 * @lc app=leetcode.cn id=1664 lang=cpp
 * @lcpr version=21202
 *
 * [1664] 生成平衡数组的方案数
 */

// @lc code=start
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        vector<int> s1(n + 1), s2(n + 1);
        for (int i = 1; i <= n; i++) {
            s1[i] = s1[i - 1];
            s2[i] = s2[i - 1];
            if (i % 2)
                s2[i] += nums[i - 1];
            else
                s1[i] += nums[i - 1];
        }

        int res = 0;
        for (int i = 1; i <= n; i++) {
            int odd = s1[i - 1] + s2[n] - s2[i];
            int even = s2[i - 1] + s1[n] - s1[i];
            if (odd == even)
                res++;
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */


