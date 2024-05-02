# @leet start
class Solution:
    def findMinimumTime(self, tasks: List[List[int]]) -> int:
        tasks.sort(key=lambda x: x[1])
        run = [False] * (tasks[-1][1] + 1)
        for start, end, duration in tasks:
            duration -= sum(run[start : end + 1])
            if duration <= 0:
                continue
            for i in range(end, start - 1, -1):
                if run[i]:
                    continue
                run[i] = True
                duration -= 1
                if duration == 0:
                    break

        return sum(run)


# @leet end
