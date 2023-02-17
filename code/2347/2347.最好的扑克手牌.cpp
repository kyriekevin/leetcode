/*
 * @lc app=leetcode.cn id=2347 lang=cpp
 * @lcpr version=21704
 *
 * [2347] 最好的扑克手牌
 */

// @lc code=start
class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_set<int> s;
        for (auto x: suits)
            s.emplace(x);
        
        if (s.size() == 1)
            return "Flush";
        
        unordered_map<int, int> cnt;
        for (auto x: ranks)
            cnt[x]++;
        
        if (cnt.size() == 5)
            return "High Card";
        
        for (auto [_, b]: cnt)
            if (b > 2)
                return "Three of a Kind";
        
        return "Pair";
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
// [13,2,3,1,9]\n["a","a","a","a","a"]\n
// @lcpr case=end

// @lcpr case=start
// [4,4,2,4,4]\n["d","a","a","b","c"]\n
// @lcpr case=end

// @lcpr case=start
// [10,10,2,12,9]\n["a","b","c","a","d"]\n
// @lcpr case=end

 */


