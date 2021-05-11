/**
 * @param {number[]} cardPoints
 * @param {number} k
 * @return {number}
 * 
 * https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/discuss/1202397/JS-Python-Java-C%2B%2B-or-Easy-Sliding-Window-Solution-w-Explanation
 */

 var maxScore = function(cardPoints, k) {
    let sum = cardPoints.slice(0, k).reduce((a, b) => a + b);
    let res = sum;
    for (let i = k - 1, j = cardPoints.length - 1; i >= 0; i--, j--) {
        sum += cardPoints[j] - cardPoints[i];
        res = Math.max(res, sum);
    }
    return res;
};