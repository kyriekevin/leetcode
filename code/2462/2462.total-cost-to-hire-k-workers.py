# @leet start
class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        n = len(costs)
        if 2 * candidates + k > n:
            costs.sort()
            return sum(costs[:k])

        left = costs[:candidates]
        right = costs[-candidates:]
        heapify(left)
        heapify(right)

        res = 0
        i, j = candidates, n - candidates - 1

        for _ in range(k):
            if left[0] <= right[0]:
                res += heapreplace(left, costs[i])
                i += 1
            else:
                res += heapreplace(right, costs[j])
                j -= 1

        return res


# @leet end
