/*
 * @lc app=leetcode.cn id=724 lang=cpp
 * @lcpr version=21801
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, leftsum = 0;
        for (int n: nums)
            sum += n;
        for (int i = 0; i < nums.size(); i++) {
            if (leftsum == sum - leftsum - nums[i])
                return i;
            leftsum += nums[i];
        }

        return -1;
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
// [1, 7, 3, 6, 5, 6]\n
// @lcpr case=end

// @lcpr case=start
// [1, 2, 3]\n
// @lcpr case=end

// @lcpr case=start
// [2, 1, -1]\n
// @lcpr case=end

 */


