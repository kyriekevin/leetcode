#
# @lc app=leetcode.cn id=2810 lang=python3
# @lcpr version=30121
#
# [2810] 故障键盘
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def finalString(self, s: str) -> str:
        q = deque()
        flag = True

        for c in s:
            if c == "i":
                flag = not flag
            elif flag:
                q.append(c)
            else:
                q.appendleft(c)

        return "".join(q if flag else reversed(q))


# @lc code=end


#
# @lcpr case=start
# "string"\n
# @lcpr case=end

# @lcpr case=start
# "poiinter"\n
# @lcpr case=end

#
