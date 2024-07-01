# @leet start
class Solution:
    def minimumMoves(self, nums: List[int], k: int, maxChanges: int) -> int:
        pos = []
        c = 0
        for i, x in enumerate(nums):
            if x == 0:
                continue
            pos.append(i)
            c = max(c, 1)

            if i > 0 and nums[i - 1] == 1:
                if i > 1 and nums[i - 2] == 1:
                    c = 3
                else:
                    c = max(c, 2)

        c = min(c, k)
        if maxChanges >= k - c:
            return max(c - 1, 0) + (k - c) * 2

        n = len(pos)
        pre = list(accumulate(pos, initial=0))
        res = inf
        sz = k - maxChanges

        for r in range(sz, n + 1):
            l = r - sz
            mid = l + sz // 2

            s1 = pos[mid] * (mid - l) - (pre[mid] - pre[l])
            s2 = pre[r] - pre[mid] - pos[mid] * (r - mid)
            res = min(res, s1 + s2)

        return res + 2 * maxChanges


# @leet end

