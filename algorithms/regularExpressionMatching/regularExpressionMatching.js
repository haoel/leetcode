/****
 * Solution of https://leetcode.com/problems/regular-expression-matching/
 * @author: Jerry Zou
 * @date: 2015.6.5
 **/

/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
    var regexp = new RegExp(p, 'g'),
        matches = s.match(regexp);

    return !!(matches && matches[0] === s);
};