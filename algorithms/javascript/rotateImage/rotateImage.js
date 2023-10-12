/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    const n = matrix.length;
    const depth = ~~(n / 2);

    for (let i = 0; i < depth; i++) {
        const innerLimit = n - 1 - 2 * i;
        const opp = n - i - 1;
        for (let j = 0; j < innerLimit; j++) {
            const temp = matrix[i][i + j];
            matrix[i][i + j] = matrix[opp - j][i];
            matrix[opp - j][i] = matrix[opp][opp - j];
            matrix[opp][opp - j] = matrix[i + j][opp];
            matrix[i + j][opp] = temp;
        }
    }
    return matrix;
};