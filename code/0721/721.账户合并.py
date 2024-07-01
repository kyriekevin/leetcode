#
# @lc app=leetcode.cn id=721 lang=python3
#
# [721] 账户合并
#

# @lc code=start
class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        email2idx = defaultdict(list)
        for i, account in enumerate(accounts):
            for email in account[1:]:
                email2idx[email].append(i)
        
        def dfs(i):
            st[i] = True
            for email in accounts[i][1:]:
                if email in email_set:
                    continue
                email_set.add(email)
                for j in email2idx[email]:
                    if not st[j]:
                        dfs(j)
        
        res = []
        st = [False] * len(accounts)
        for i, t in enumerate(st):
            if not t:
                email_set = set()
                dfs(i)
                res.append([accounts[i][0]] + sorted(email_set))
        
        return res
# @lc code=end

