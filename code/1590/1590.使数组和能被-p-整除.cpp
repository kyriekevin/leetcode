/*
 * @lc app=leetcode.cn id=1590 lang=cpp
 * @lcpr version=21801
 *
 * [1590] 使数组和能被 P 整除
 */

// @lc code=start
#define x first
#define y second

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size(), res = n;
        vector<int> sum(n + 10, 0);
        for (int i = 1; i <= n; i++)
            sum[i] = (sum[i - 1] + nums[i - 1]) % p;
        
        if (sum[n] % p == 0)
            return 0;

        unordered_map<int, int> hash;
        for (int i = 0; i <= n; i++) {
            hash[sum[i]] = i;
            auto it = hash.find((sum[i] - sum[n] + p) % p);
            if (it != hash.end()) 
                res = min(res, i - it->y);
        }

        return res < n ? res : -1;
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
// [3,1,4,2]\n6\n
// @lcpr case=end

// @lcpr case=start
// [6,3,5,2]\n9\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n7\n
// @lcpr case=end

// @lcpr case=start
// [1000000000,1000000000,1000000000]\n3\n
// @lcpr case=end

 */


