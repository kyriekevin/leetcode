/*
 * @lc app=leetcode.cn id=2271 lang=cpp
 * @lcpr version=30117
 *
 * [2271] 毯子覆盖的最多白色砖块数
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
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int n = tiles.size();
        sort(tiles.begin(), tiles.end());
        int res = 0, cnt = 0, r = 0;
        for (int l = 0; l < n; l++) {
            if (l) cnt -= tiles[l - 1][1] - tiles[l - 1][0] + 1;
            while (r < n && tiles[l][0] + carpetLen > tiles[r][1]) {
                cnt += tiles[r][1] - tiles[r][0] + 1;
                r++;
            }

            if (r == n) {
                res = max(res, cnt);
                break;
            }

            int extra = max(0, tiles[l][0] - tiles[r][0] + carpetLen);
            res = max(res, cnt + extra);
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,5],[10,11],[12,18],[20,25],[30,32]]\n10\n
// @lcpr case=end

// @lcpr case=start
// [[10,11],[1,1]]\n2\n
// @lcpr case=end

 */

