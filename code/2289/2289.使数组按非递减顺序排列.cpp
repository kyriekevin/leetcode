/*
 * @lc app=leetcode.cn id=2289 lang=cpp
 * @lcpr version=21705
 *
 * [2289] 使数组按非递减顺序排列
 */

// @lc code=start
typedef pair<int, int> PII;
#define x first
#define y second

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<PII> stk;
        int n = nums.size(), res = 0;
        for (int i = n - 1; i >= 0; i--) {
            int cnt = 0;
            while (stk.size() && stk.top().x < nums[i]) {
                cnt = max(cnt + 1, stk.top().y);
                stk.pop();
            }
            stk.emplace(nums[i], cnt);
            res = max(res, cnt);
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
// [5,3,4,4,7,3,6,11,8,5,11]\n
// @lcpr case=end

// @lcpr case=start
// [4,5,7,7,13]\n
// @lcpr case=end

 */


