/*
 * @lc app=leetcode.cn id=2401 lang=cpp
 * @lcpr version=21705
 *
 * [2401] 最长优雅子数组
 */

// @lc code=start
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int j = i, x = 0;
            while (j >= 0 && (x & nums[j]) == 0)
                x |= nums[j--];
            res = max(res, i - j);
        }

        return res;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=
// paramTypes= []
// returnType=
// @lcpr-div-debug-arg-end


/*
// @lcpr case=start
// [1,3,8,48,10]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,5,11,13]\n
// @lcpr case=end

 */


