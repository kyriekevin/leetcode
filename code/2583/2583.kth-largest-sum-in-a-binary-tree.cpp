/*
 * @lc app=leetcode.cn id=2583 lang=cpp
 * @lcpr version=30117
 *
 * [2583] 二叉树中的第 K 大层和
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
typedef long long ll;

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<ll> s;
        queue<TreeNode*> q;
        q.push(root);

        while (q.size()) {
            int sz = q.size();
            ll tot = 0;
            for (int i = 0; i < sz; i++) {
                auto t = q.front();
                q.pop();
                tot += t->val;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            s.push_back(tot);
        }

        if (s.size() < k) return -1;
        sort(s.begin(), s.end(), greater<ll>());
        return s[k - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,8,9,2,1,3,7,4,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,null,3]\n1\n
// @lcpr case=end

 */

