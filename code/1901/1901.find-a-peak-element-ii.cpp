/*
 * @lc app=leetcode.cn id=1901 lang=cpp
 * @lcpr version=30112
 *
 * [1901] 寻找峰值 II
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
class Solution {
public:
    int max_idx(vector<int> arr) {
        return max_element(arr.begin(), arr.end()) - arr.begin();
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int left = 0, right = mat.size() - 1;
        while (left < right) {
            int row = (left + right) / 2;
            int col = max_idx(mat[row]);
            
            if (mat[row][col] > mat[row + 1][col])
                right = row;
            else left = row + 1;
        }

        return {left, max_idx(mat[left])};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4],[3,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[10,20,15],[21,30,14],[7,16,32]]\n
// @lcpr case=end

 */

