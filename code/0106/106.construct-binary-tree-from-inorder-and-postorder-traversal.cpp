/*
 * @lc app=leetcode.cn id=106 lang=cpp
 * @lcpr version=30117
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    unordered_map<int, int> pos;

    TreeNode* dfs(vector<int>& in, vector<int>& post, int il, int ir, int pl, int pr) {
        if (il > ir || pl > pr) return nullptr;
        TreeNode* root = new TreeNode(post[pr]);
        int k = pos[post[pr]] - il;

        root->left = dfs(in, post, il, il + k - 1, pl, pl + k - 1);
        root->right = dfs(in, post, il + k + 1, ir, pl + k, pr - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++)
            pos[inorder[i]] = i;
        
        return dfs(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [9,3,15,20,7]\n[9,15,7,20,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */

