/*
 * @lc app=leetcode.cn id=337 lang=cpp
 * @lcpr version=21302
 *
 * [337] 打家劫舍 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        auto f = dfs(root);
        return max(f[0], f[1]);
    }

    vector<int> dfs(TreeNode* u) {
        if (!u)
            return {0, 0};
        auto l = dfs(u->left), r = dfs(u->right);
        return {max(l[0], l[1]) + max(r[0], r[1]), l[0] + r[0] + u->val};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,3,null,3,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,5,1,3,null,1]\n
// @lcpr case=end

 */


