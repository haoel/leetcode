class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        ans = kSum = sum(cardPoints[:k])
        for i in range(k - 1, -1, -1):
            kSum += cardPoints[len(cardPoints) - k + i] - cardPoints[i]
            ans = max(ans, kSum)
        return ans