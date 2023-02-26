/*
 * @lc app=leetcode.cn id=1255 lang=cpp
 * @lcpr version=21704
 *
 * [1255] 得分最高的单词集合
 */

// @lc code=start
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int tot[26] = {0};
        for (auto c: letters)
            tot[c - 'a']++;
        int n = words.size(), res = 0;

        for (int i = 0; i < 1 << n; i++) {
            int cnt[26] = {0};
            for (int j = 0; j < n; j++)
                if (i >> j & 1)
                    for (auto c: words[j])
                        cnt[c - 'a']++;

            bool flag = true;
            for (int j = 0; j < 26; j++)
                if (cnt[j] > tot[j]) {
                    flag = false;
                    break;
                }
            
            if (flag) {
                int sum = 0;
                for (int j = 0; j < 26; j++)
                    sum += cnt[j] * score[j];
                res = max(sum, res);
            }
        }

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
// ["dog","cat","dad","good"]\n["a","a","c","d","d","d","g","o","o"]\n[1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]\n
// @lcpr case=end

// @lcpr case=start
// ["xxxz","ax","bx","cx"]\n["z","a","b","c","x","x","x"]\n[4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]\n
// @lcpr case=end

// @lcpr case=start
// ["leetcode"]\n["l","e","t","c","o","d"]\n[0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0]\n
// @lcpr case=end

 */


