class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        def check(x):
            return sum([floor(sqrt(x // n)) for n in ranks]) >= cars

        l, r = 0, ranks[0] * cars * cars
        while l < r:
            mid = l + r >> 1
            if check(mid):
                r = mid
            else:
                l = mid + 1
        
        return l
