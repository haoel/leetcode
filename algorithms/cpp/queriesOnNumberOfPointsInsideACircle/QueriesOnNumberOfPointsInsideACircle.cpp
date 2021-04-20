// Source : https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/
// Author : Hao Chen
// Date   : 2021-04-20

/***************************************************************************************************** 
 *
 * You are given an array points where points[i] = [xi, yi] is the coordinates of the i^th point on a 
 * 2D plane. Multiple points can have the same coordinates.
 * 
 * You are also given an array queries where queries[j] = [xj, yj, rj] describes a circle centered at 
 * (xj, yj) with a radius of rj.
 * 
 * For each query queries[j], compute the number of points inside the j^th circle. Points on the 
 * border of the circle are considered inside.
 * 
 * Return an array answer, where answer[j] is the answer to the j^th query.
 * 
 * Example 1:
 * 
 * Input: points = [[1,3],[3,3],[5,3],[2,2]], queries = [[2,3,1],[4,3,1],[1,1,2]]
 * Output: [3,2,2]
 * Explanation: The points and circles are shown above.
 * queries[0] is the green circle, queries[1] is the red circle, and queries[2] is the blue circle.
 * 
 * Example 2:
 * 
 * Input: points = [[1,1],[2,2],[3,3],[4,4],[5,5]], queries = [[1,2,2],[2,2,2],[4,3,2],[4,3,3]]
 * Output: [2,3,2,4]
 * Explanation: The points and circles are shown above.
 * queries[0] is green, queries[1] is red, queries[2] is blue, and queries[3] is purple.
 * 
 * Constraints:
 * 
 * 	1 <= points.length <= 500
 * 	points[i].length == 2
 * 	0 <= x​​​​​​i, y​​​​​​i <= 500
 * 	1 <= queries.length <= 500
 * 	queries[j].length == 3
 * 	0 <= xj, yj <= 500
 * 	1 <= rj <= 500
 * 	All coordinates are integers.
 * 
 * Follow up: Could you find the answer for each query in better complexity than O(n)?
 ******************************************************************************************************/

class Solution {
private:
    //refer to: https://stackoverflow.com/a/7227057/13139221
    bool inCircle( vector<int>& point,  vector<int>& circle ) {
        int x = point[0], y = point[1];
        int xo = circle[0], yo = circle[1], r = circle[2];
        
        int dx = abs(x-xo);
        if ( dx > r ) return false;
        int dy = abs(y-yo);
        if ( dy > r ) return false;
        if ( dx + dy <= r ) return true;
        return ( dx*dx + dy*dy <= r*r );
    }
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> result;
        for(auto& c : queries) {
            int cnt = 0;
            for(auto& p : points) {
                if ( inCircle(p, c) ) cnt++;
            }
            result.push_back(cnt);
        }
        return result;
    }
};
