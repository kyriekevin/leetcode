#
# @lc app=leetcode.cn id=331 lang=python3
# @lcpr version=30121
#
# [331] 验证二叉树的前序序列化
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def isValidSerialization(self, _s: str) -> bool:
        self.s = _s + ","
        self.k = 0
        if not self.dfs():
            return False
        return self.k == len(self.s)

    def dfs(self):
        if self.k == len(self.s):
            return False
        if self.s[self.k] == "#":
            self.k += 2
            return True
        while self.s[self.k] != ",":
            self.k += 1
        self.k += 1
        return self.dfs() and self.dfs()


# @lc code=end


#
# @lcpr case=start
# "9,3,4,#,#,1,#,#,2,#,6,#,#"\n
# @lcpr case=end

# @lcpr case=start
# "1,#"\n
# @lcpr case=end

# @lcpr case=start
# "9,#,#,1"\n
# @lcpr case=end

#
