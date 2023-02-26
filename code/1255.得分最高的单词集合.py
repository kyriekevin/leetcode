#
# @lc app=leetcode.cn id=1255 lang=python3
# @lcpr version=21704
#
# [1255] 得分最高的单词集合
#

# @lc code=start
class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        cnt = Counter(letters)
        n, res = len(words), 0

        for i in range(1 << n):
            cur = Counter(''.join([words[j] for j in range(n) if i >> j & 1]))
            if all(v <= cnt[c] for c, v in cur.items()):
                t = sum(v * score[ord(c) - ord('a')] for c, v in cur.items())
                res = max(res, t)

        return res
            
# @lc code=end

# @lcpr-div-debug-arg-start
# funName=
# paramTypes= []
# returnType=
# @lcpr-div-debug-arg-end


#
# @lcpr case=start
# ["dog","cat","dad","good"]\n["a","a","c","d","d","d","g","o","o"]\n[1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]\n
# @lcpr case=end

# @lcpr case=start
# ["xxxz","ax","bx","cx"]\n["z","a","b","c","x","x","x"]\n[4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]\n
# @lcpr case=end

# @lcpr case=start
# ["leetcode"]\n["l","e","t","c","o","d"]\n[0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0]\n
# @lcpr case=end

#


