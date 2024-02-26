/*
 * @lc app=leetcode.cn id=938 lang=cpp
 * @lcpr version=30117
 *
 * [938] 二叉搜索树的范围和
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int res = 0;
        stack<TreeNode*> stk;
        stk.push(root);

        while (stk.size()) {
            auto t = stk.top();
            stk.pop();
            if (low <= t->val && t->val <= high)
                res += t->val;
            if (t->left && t->val > low)
                stk.push(t->left);
            if (t->right && t->val < high)
                stk.push(t->right);
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,5,15,3,7,null,18]\n7\n15\n
// @lcpr case=end

// @lcpr case=start
// [10,5,15,3,7,13,18,1,null,6]\n6\n10\n
// @lcpr case=end

 */

