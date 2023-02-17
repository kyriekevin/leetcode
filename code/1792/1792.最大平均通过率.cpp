/*
 * @lc app=leetcode.cn id=1792 lang=cpp
 * @lcpr version=21703
 *
 * [1792] 最大平均通过率
 */

// @lc code=start
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<tuple<double, int, int>> pq;
        for (auto &e : classes) {
            int a = e[0], b = e[1];
            double x = (double)(a + 1) / (b + 1) - (double)a / b;
            pq.push({x, a, b});
        }

        while (extraStudents--) {
            auto [_, a, b] = pq.top();
            pq.pop();
            a++;
            b++;
            double x = (double)(a + 1) / (b + 1) - (double)a / b;
            pq.push({x, a, b});
        }

        double ans = 0;
        while (pq.size()) {
            auto [_, a, b] = pq.top();
            pq.pop();
            ans += (double)a / b;
        }
        return ans / classes.size();
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
// [[1,2],[3,5],[2,2]]\n2\n
// @lcpr case=end

// @lcpr case=start
// [[2,4],[3,9],[4,5],[2,10]]\n4\n
// @lcpr case=end

 */


