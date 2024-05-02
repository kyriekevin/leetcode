# @leet start
class Solution:
    def jobScheduling(
        self, startTime: List[int], endTime: List[int], profit: List[int]
    ) -> int:
        jobs = sorted(zip(endTime, startTime, profit))
        n = len(jobs)
        f = [0] * n
        f[0] = jobs[0][2]

        for i in range(1, n):
            f[i] = max(f[i - 1], jobs[i][2])
            if jobs[0][0] <= jobs[i][1]:
                l, r = 0, i - 1
                while l < r:
                    mid = (l + r + 1) // 2
                    if jobs[mid][0] <= jobs[i][1]:
                        l = mid
                    else:
                        r = mid - 1
                f[i] = max(f[i], f[l] + jobs[i][2])

        return f[n - 1]


# @leet end

