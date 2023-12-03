class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        res = s = sum(cardPoints[:k])
        for i in range(1, k + 1):
            s += cardPoints[-i] - cardPoints[k - i]
            res = max(res, s)
        return res
