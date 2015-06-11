/****
 * Solution of https://leetcode.com/problems/spiral-matrix-ii/
 * @author: Jerry Zou
 * @date: 2015.6.4
 **/

/**
 * @param {number} n
 * @return {number[][]}
 */
var generateMatrix = function(n) {
    function generateBorder(matrix, startPoint, startNum, length) {
        var x = startPoint.x,
            y = startPoint.y,
            i;

        for (i = 0; i < length; x++, i++) {
            matrix[y][x] = startNum++;
        }
        x--, y++;
        for (i = 1; i < length; y++, i++) {
            matrix[y][x] = startNum++;
        }
        y--, x--;
        for (i = 1; i < length; x--, i++) {
            matrix[y][x] = startNum++;
        }
        x++, y--;
        for (i = 1; i < length-1; y--, i++) {
            matrix[y][x] = startNum++;
        }
        return startNum;
    }

    var matrix = [],
        next = 1,
        j = 0;

    for (; j < n; j++) {
        matrix[j] = [];
    }

    for (j = 0; j < n; j += 1) {
        next = generateBorder(matrix, { x:j, y:j }, next, n-j*2);
    }
    
    return matrix;
};