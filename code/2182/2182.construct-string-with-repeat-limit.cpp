/*
 * @lc app=leetcode.cn id=2182 lang=cpp
 * @lcpr version=30113
 *
 * [2182] 构造限制重复的字符串
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

const int N = 26;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int cnt[N] = {0};
        for (char c: s)
            cnt[c - 'a']++;
        
        int m = 0;
        string res = "";
        for (int i = N - 1, j = N - 2; i >= 0 && j >= 0;) {
            if (cnt[i] == 0) {
                m = 0;
                i--;
            }
            else if (m < repeatLimit) {
                res += 'a' + i;
                cnt[i]--;
                m++;
            }
            else if (j >= i || cnt[j] == 0)
                j--;
            else {
                cnt[j]--;
                res += 'a' + j;
                m = 0;
            }
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "cczazcc"\n3\n
// @lcpr case=end

// @lcpr case=start
// "aababab"\n2\n
// @lcpr case=end

 */

