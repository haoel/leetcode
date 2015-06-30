// Source : https://leetcode.com/problems/the-skyline-problem/
// Author : Hao Chen
// Date   : 2015-06-11

/********************************************************************************** 
 * 
 * A city's skyline is the outer contour of the silhouette formed by all the buildings 
 * in that city when viewed from a distance. Now suppose you are given the locations and 
 * height of all the buildings as shown on a cityscape photo (Figure A), write a program 
 * to output the skyline formed by these buildings collectively (Figure B).
 * 
 *  ^                                        ^                                                                   
 *  |                                        |                                                                   
 *  |                                        |                                                                   
 *  |    +-----+                             |    O-----+                                                        
 *  |    |     |                             |    |     |                                                        
 *  |    |     |                             |    |     |                                                        
 *  |    |  +--+------+                      |    |     O------+                                                 
 *  |    |  |         |                      |    |            |                                                 
 *  |  +-+--+----+    |   +------+           |  O-+            |   O------+                                      
 *  |  |         |    |   |      |           |  |              |   |      |                                      
 *  |  |         |    |   |    +-+--+        |  |              |   |      O--+                                   
 *  |  |         |    |   |    |    |        |  |              |   |         |                                   
 *  |  |         |    |   |    |    |        |  |              |   |         |                                   
 *  |  |         |    |   |    |    |        |  |              |   |         |                                   
 *  |  |         |    |   |    |    |        |  |              |   |         |                                   
 *  +--+---------+----+---+----+----+--->    +--+--------------O---+---------O--->                               
 *  
 *   https://leetcode.com/static/images/problemset/skyline1.jpg  
 *   https://leetcode.com/static/images/problemset/skyline2.jpg  
 * 
 * The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], 
 * where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, 
 * and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 , and Ri - Li > 0. 
 * You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.
 * 
 * For instance, the dimensions of all buildings in Figure A are recorded as: 
 *  [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .
 * 
 * The output is a list of "key points" (red dots in Figure B) in the format of 
 * [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. 
 * A key point is the left endpoint of a horizontal line segment. 
 *
 * Note that the last key point, where the rightmost building ends, is merely used to mark 
 * the termination of the skyline, and always has zero height. Also, the ground in between 
 * any two adjacent buildings should be considered part of the skyline contour.
 * 
 * For instance, the skyline in Figure B should be represented as:
 *  [ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].
 * 
 * Notes:
 * 
 *  - The number of buildings in any input list is guaranteed to be in the range [0, 10000].
 *  - The input list is already sorted in ascending order by the left x position Li. 
 *  - The output list must be sorted by the x position. 
 *  - There must be no consecutive horizontal lines of equal height in the output skyline. 
 *    For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; 
 *    the three lines of height 5 should be merged into one in the final output as such: 
 *    [...[2 3], [4 5], [12 7], ...]
 * 
 * Credits: Special thanks to @stellari for adding this problem, 
 *          creating these two awesome images and all test cases.
 *               
 **********************************************************************************/



/*
 * Sweep line with max-heap
 * ------------------------
 * Notice that "key points" are either the left or right edges of the buildings. 
 * 
 * Therefore, we first obtain both the edges of all the N buildings, and store the 2N edges in a sorted array. 
 * Maintain a max-heap of building heights while scanning through the edge array: 
 * 1) If the current edge is a left edge, then add the height of its associated building to the max-heap; 
 * 2) If the edge is a right one, remove the associated height from the heap. 
 * 
 * Then we take the top value of the heap (yi) as the maximum height at the current edge position (xi). 
 * Now (xi, yi) is a potential key point. 
 * 
 * If yi is the same as the height of the last key point in the result list, it means that this key point 
 * is not a REAL key point, but rather a horizontal continuation of the last point, so it should be discarded; 
 * 
 * otherwise, we add (xi,yi) to the result list because it is a real key point. 
 * 
 * Repeat this process until all the edges are checked.
 * 
 * It takes O(NlogN) time to sort the edge array. For each of the 2N edges, 
 * it takes O(1) time to query the maximum height but O(logN) time to add 
 * or remove elements. Overall, this solution takes O(NlogN) time.
 */
class Solution {
public:

    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector< pair<int, int> > edges;
        
        //put all of edge into a vector
        //set left edge as negtive, right edge as positive
        //so, when we sort the edges, 
        //  1) for same left point, the height would be descending order
        //  2) for same right point, the height would be ascending order
        int left, right, height;
        for(int i=0; i<buildings.size(); i++) {
            left   = buildings[i][0];
            right  = buildings[i][1];
            height = buildings[i][2];
            edges.push_back(make_pair(left, -height));
            edges.push_back(make_pair(right, height));
        }
        sort(edges.begin(), edges.end());

        // 1) if we meet a left edge, then we add its height into a `set`.
        //    the `set` whould sort the height automatically.
        // 2) if we meet a right edge, then we remove its height from the `set`
        //
        // So, we could get the current highest height from the `set`, if the 
        // current height is different with preivous height, then we need add
        // it into the result.
        vector< pair<int, int> > result;
        multiset<int> m;
        m.insert(0);
        int pre = 0, cur = 0;
        for (int i=0; i<edges.size(); i++){
            pair<int,int> &e = edges[i];
            if (e.second < 0) {
                m.insert(-e.second);
            }else{
                m.erase(m.find(e.second));
            }
            cur = *m.rbegin();
            if (cur != pre) {
                result.push_back(make_pair(e.first, cur));
                pre = cur;
            }
        }
        return result;

    }
};
