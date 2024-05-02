# @leet start
class Solution:
    def minimumRefill(self, plants: List[int], capacityA: int, capacityB: int) -> int:
        res = 0
        a, b = capacityA, capacityB
        i, j = 0, len(plants) - 1

        while i < j:
            if a < plants[i]:
                res += 1
                a = capacityA
            a -= plants[i]
            i += 1

            if b < plants[j]:
                res += 1
                b = capacityB
            b -= plants[j]
            j -= 1

        if i == j and max(a, b) < plants[i]:
            res += 1

        return res


# @leet end

