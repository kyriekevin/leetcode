# @leet start
class Solution:
    def numberOfWeeks(self, milestones: List[int]) -> int:
        longest = max(milestones)
        rest = sum(milestones) - longest
        if longest > rest + 1:
            return 2 * rest + 1
        return longest + rest


# @leet end

