/*
 * @lc app=leetcode.cn id=1487 lang=cpp
 * @lcpr version=21708
 *
 * [1487] 保证文件名唯一
 */

// @lc code=start
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> res;
        unordered_map<string, int> cnt;

        for (auto name: names) {
            if (!cnt.count(name)) {
                res.push_back(name);
                cnt[name] = 1;
            }
            else {
                int k = cnt[name];
                while (cnt.count(name + "(" + to_string(k) + ")"))
                    k += 1;
                
                string t = name + "(" + to_string(k) + ")";
                res.push_back(t);
                cnt[name] = k + 1;
                cnt[t] = 1;
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
// ["pes","fifa","gta","pes(2019)"]\n
// @lcpr case=end

// @lcpr case=start
// ["gta","gta(1)","gta","avalon"]\n
// @lcpr case=end

// @lcpr case=start
// ["onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece"]\n
// @lcpr case=end

// @lcpr case=start
// ["wano","wano","wano","wano"]\n
// @lcpr case=end

// @lcpr case=start
// ["kaido","kaido(1)","kaido","kaido(1)"]\n
// @lcpr case=end

 */


