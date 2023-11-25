/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  bool check(vector<int> cnt) {
    int c = 0;
    for (auto x : cnt)
      if (x % 2)
        c++;

    return c <= 1;
  }

  int dfs(TreeNode *root, vector<int> &cnt) {
    if (!root)
      return 0;

    cnt[root->val]++;
    int res = 0;
    if (!root->left && !root->right) {
      if (check(cnt))
        res = 1;
    } else
      res = dfs(root->left, cnt) + dfs(root->right, cnt);
    cnt[root->val]--;

    return res;
  }

  int pseudoPalindromicPaths(TreeNode *root) {
    vector<int> cnt(10);
    return dfs(root, cnt);
  }
};
