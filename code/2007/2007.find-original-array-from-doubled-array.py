# @leet start
class Solution:
    def findOriginalArray(self, changed: List[int]) -> List[int]:
        changed.sort()
        res = []
        cnt = Counter()

        for x in changed:
            if x not in cnt:
                cnt[2 * x] += 1
                res.append(x)
            else:
                cnt[x] -= 1
                if cnt[x] == 0:
                    del cnt[x]

        return [] if cnt else res


# @leet end
