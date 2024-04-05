# @leet start
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        res = []
        path = []

        def dfs(i: int, target: int) -> None:
            if target == 0:
                res.append(path.copy())
                return

            if i == len(candidates) or target < candidates[i]:
                return

            dfs(i + 1, target)

            path.append(candidates[i])
            dfs(i, target - candidates[i])
            path.pop()

        dfs(0, target)

        return res


# @leet end
