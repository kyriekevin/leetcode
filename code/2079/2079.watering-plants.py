# @leet start
class Solution:
    def wateringPlants(self, plants: List[int], capacity: int) -> int:
        res = len(plants)
        water = capacity

        for i, need in enumerate(plants):
            if water < need:
                res += 2 * i
                water = capacity
            water -= need
        return res


# @leet end
