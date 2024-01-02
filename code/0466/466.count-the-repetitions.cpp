/*
 * @lc app=leetcode.cn id=466 lang=cpp
 * @lcpr version=30112
 *
 * [466] 统计重复个数
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
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        vector<int> cnt;
        unordered_map<int, int> hash;

        for (int i = 0, k = 0; i < n1; i++) {
            for (int j = 0; j < s1.size(); j++)
                if (s1[j] == s2[k % s2.size()])
                    k++;
            cnt.push_back(k);

            if (hash.count(k % s2.size())) {
                int a = i - hash[k % s2.size()];
                int b = k - cnt[hash[k % s2.size()]];
                int res = (n1 - i - 1) / a * b;
                for (int u = 0; u < (n1 - i - 1) % a; u++)
                    for (int j = 0; j < s1.size(); j++)
                        if (s1[j] == s2[k % s2.size()])
                            k++;
                res += k;
                return res / s2.size() / n2;
            }

            hash[k % s2.size()] = i;
        }

        if (cnt.empty())
            return 0;
        
        return cnt.back() / s2.size() / n2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "acb"\n4\n"ab"\n2\n
// @lcpr case=end

// @lcpr case=start
// "acb"\n1\n"acb"\n1\n
// @lcpr case=end

 */

