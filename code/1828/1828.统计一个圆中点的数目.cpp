/*
 * @lc app=leetcode.cn id=1828 lang=cpp
 * @lcpr version=21115
 *
 * [1828] 统计一个圆中点的数目
 */

// @lc code=start
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res;
        for (auto& q: queries) {
            int X = q[0], Y = q[1], R = q[2];
            int cnt = 0;
            for (auto& p: points) {
                int x = p[0], y = p[1];
                if ((X - x) * (X - x) + (Y - y) * (Y - y) <= R * R)
                    cnt++;
            }
            res.push_back(cnt);
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3],[3,3],[5,3],[2,2]]\n[[2,3,1],[4,3,1],[1,1,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[2,2],[3,3],[4,4],[5,5]]\n[[1,2,2],[2,2,2],[4,3,2],[4,3,3]]\n
// @lcpr case=end

 */


