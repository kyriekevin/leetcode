#
# @lc app=leetcode.cn id=1487 lang=python3
# @lcpr version=21708
#
# [1487] 保证文件名唯一
#

# @lc code=start
class Solution:
    def getFolderNames(self, names: List[str]) -> List[str]:
        res, s = [], {}
        for name in names:
            if name not in s:
                res.append(name)
                s[name] = 1
            else:
                k = s[name]
                while name + "(" + str(k) + ")" in s:
                    k += 1
                
                t = name + "(" + str(k) + ")"
                res.append(t)
                s[name] = k + 1
                s[t] = 1

        return res 
# @lc code=end

# @lcpr-div-debug-arg-start
# funName=
# paramTypes= []
# returnType=
# @lcpr-div-debug-arg-end


#
# @lcpr case=start
# ["pes","fifa","gta","pes(2019)"]\n
# @lcpr case=end

# @lcpr case=start
# ["gta","gta(1)","gta","avalon"]\n
# @lcpr case=end

# @lcpr case=start
# ["onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece"]\n
# @lcpr case=end

# @lcpr case=start
# ["wano","wano","wano","wano"]\n
# @lcpr case=end

# @lcpr case=start
# ["kaido","kaido(1)","kaido","kaido(1)"]\n
# @lcpr case=end

#


