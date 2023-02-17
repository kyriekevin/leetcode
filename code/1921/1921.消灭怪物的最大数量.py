class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        arr = sorted([(d - 1) // s + 1 for d, s in zip(dist, speed)])
        for attack, arrival in enumerate(arr):
            if attack >= arrival:
                return attack

        return len(arr)
