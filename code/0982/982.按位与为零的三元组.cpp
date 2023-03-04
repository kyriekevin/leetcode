/*
 * @lc app=leetcode.cn id=982 lang=cpp
 * @lcpr version=21708
 *
 * [982] 按位与为零的三元组
 */

// @lc code=start
class Solution {
public:
    int countTriplets(vector<int>& nums) {
        vector<int> cnt(1 << 16);
        for (int x: nums)
            for (int y: nums)
                cnt[x & y]++;

        int res = 0;
        for (int x: nums) {
            for (int y = 0; y < 1 << 16; y++)
                if (!(x & y))
                    res += cnt[y];
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
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n
// @lcpr case=end

 */


