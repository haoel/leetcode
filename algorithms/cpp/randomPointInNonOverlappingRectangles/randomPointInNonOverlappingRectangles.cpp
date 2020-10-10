// Source : https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/submissions/ 
// Author : rqj
// Date   : 2020-10-10

/********************************************************************************** 
 *
 * Given a list of non-overlapping axis-aligned rectangles rects, write a function
 * pick which randomly and uniformily picks an integer point in the space covered
 * by the rectangles.
 *
 * Note:
 * 1. An integer point is a point that has integer coordinates. 
 * 2. A point on the perimeter of a rectangle is included in the space covered by
 * the rectangles. 
 * 3. ith rectangle = rects[i] = [x1,y1,x2,y2], where [x1, y1] are the integer
 * coordinates of the bottom-left corner, and [x2, y2] are the integer coordinates
 * of the top-right corner.
 * 4. length and width of each rectangle does not exceed 2000.
 * 5. 1 <= rects.length <= 100
 * 6. pick return a point as an array of integer coordinates [p_x, p_y]
 * 7. pick is called at most 10000 times.
 *
 * Example 1:
 * Input:
 * ["Solution","pick","pick","pick"]
 * [[[[1,1,5,5]]],[],[],[]]
 * Output: [null,[4,1],[4,1],[3,3]]
 * 
 * Example 2:
 * Input: 
 * ["Solution","pick","pick","pick","pick","pick"]
 * [[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]]
 * Output: [null,[-1,-2],[2,0],[-2,-1],[3,0],[-2,-2]]
 *
 * Explanation of Input Syntax:
 * The input is two lists: the subroutines called and their arguments.
 * Solution's constructor has one argument, the array of rectangles rects. pick
 * has no arguments. Arguments are always wrapped with a list, even if there aren't
 * any.
 *
 **********************************************************************************/

class Solution {
public:
    //attributes
    vector<vector<int>> rects_b; //copy of the given 'rects' vector
    vector<int> points_until; //value of element 'e' = num of points in all rects before 'e', including it

    Solution(vector<vector<int>>& rects) {
        for (auto &e : rects) {
            int before = (points_until.size() == 0) ? 0 : points_until.back(); //points before 'e'
            points_until.push_back((e[2] - e[0] + 1) * (e[3] - e[1] + 1) + before);
            rects_b = rects;
        }
    }

    vector<int> pick() {
        int ind = rand() % points_until.back(); //randomly choose one of the points counted
        int rect = upper_bound(points_until.begin(), points_until.end(), ind) - points_until.begin();
        ind -= (rect == 0) ? 0 : points_until[rect - 1];
        int row = rects_b[rect][3] - rects_b[rect][1] + 1;
        return {ind/row + rects_b[rect][0], ind%row + rects_b[rect][1]};
    }
};
