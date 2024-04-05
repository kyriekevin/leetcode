# @leet start
class Solution:
    def distanceTraveled(self, mainTank: int, additionalTank: int) -> int:
        res = 0
        while mainTank > 0:
            if mainTank < 5 or additionalTank == 0:
                res += mainTank * 10
                break
            else:
                res += 50
                mainTank -= 4
                additionalTank -= 1
        return res


# @leet end
