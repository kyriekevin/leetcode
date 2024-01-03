/*
 * @lc app=leetcode.cn id=500 lang=cpp
 * @lcpr version=30112
 *
 * [500] 键盘行
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
    vector<string> findWords(vector<string>& words) {
        string line[3] = {
            "qwertyuiop",
            "asdfghjkl",
            "zxcvbnm"
        };

        unordered_map<char, int> hash;
        for (int i = 0; i < 3; i++)
            for (auto &ch: line[i])
                hash[ch] = i;
        
        vector<string> res;
        for (auto &word: words) {
            set<int> S;
            for (auto ch: word)
                S.insert(hash[tolower(ch)]);
            if (S.size() == 1)
                res.push_back(word);
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["Hello","Alaska","Dad","Peace"]\n
// @lcpr case=end

// @lcpr case=start
// ["omk"]\n
// @lcpr case=end

// @lcpr case=start
// ["adsdf","sfd"]\n
// @lcpr case=end

 */

