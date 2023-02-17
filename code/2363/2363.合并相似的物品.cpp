/*
 * @lc app=leetcode.cn id=2363 lang=cpp
 * @lcpr version=21706
 *
 * [2363] 合并相似的物品
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> mp;
        for (auto &v: items1)
            mp[v[0]] += v[1];
        
        for (auto &v: items2)
            mp[v[0]] += v[1];
        
        vector<vector<int>> res;
        for (auto &[k, v]: mp)
            res.push_back({k, v});

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
// [[1,1],[4,5],[3,8]]\n[[3,1],[1,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[3,2],[2,3]]\n[[2,1],[3,2],[1,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[2,2]]\n[[7,1],[2,2],[1,4]]\n
// @lcpr case=end

 */


