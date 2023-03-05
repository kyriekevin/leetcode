/*
 * @lc app=leetcode.cn id=1599 lang=cpp
 * @lcpr version=21801
 *
 * [1599] 经营摩天轮的最大利润
 */

// @lc code=start
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int wait = 0, i = 0;
        int mx = 0, t = 0;
        int res = -1;

        while (wait || i < customers.size()) {
            wait += i < customers.size() ? customers[i] : 0;
            int up = min(wait, 4);
            wait -= up;
            i++;
            t += up * boardingCost - runningCost;
            if (t > mx) {
                mx = t;
                res = i;
            }
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
// [8,3]\n5\n6\n
// @lcpr case=end

// @lcpr case=start
// [10,9,6]\n6\n4\n
// @lcpr case=end

// @lcpr case=start
// [3,4,0,5,1]\n1\n92\n
// @lcpr case=end

 */


