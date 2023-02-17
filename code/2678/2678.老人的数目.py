class Solution:
    def countSeniors(self, details: List[str]) -> int:
        return sum(1 for info in details if int(info[11: 13]) > 60)
