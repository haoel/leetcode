// Source : https://leetcode.com/problems/perfect-rectangle/
// Author : Hao Chen
// Date   : 2016-09-08

/*************************************************************************************** 
 *
 * Given N axis-aligned rectangles where N > 0, determine if they all together form an 
 * exact cover of a rectangular region.
 * 
 * Each rectangle is represented as a bottom-left point and a top-right point. For 
 * example, a unit square is represented as [1,1,2,2]. (coordinate of bottom-left point 
 * is (1, 1) and top-right point is (2, 2)).
 * 
 * Example 1:
 * 
 * rectangles = [
 *   [1,1,3,3],
 *   [3,1,4,2],
 *   [3,2,4,4],
 *   [1,3,2,4],
 *   [2,3,3,4]
 * ]
 * 
 * Return true. All 5 rectangles together form an exact cover of a rectangular region.
 * 
 * Example 2:
 * 
 * rectangles = [
 *   [1,1,2,3],
 *   [1,3,2,4],
 *   [3,1,4,2],
 *   [3,2,4,4]
 * ]
 * 
 * Return false. Because there is a gap between the two rectangular regions.
 * 
 * Example 3:
 * 
 * rectangles = [
 *   [1,1,3,3],
 *   [3,1,4,2],
 *   [1,3,2,4],
 *   [3,2,4,4]
 * ]
 * 
 * Return false. Because there is a gap in the top center.
 * 
 * Example 4:
 * 
 * rectangles = [
 *   [1,1,3,3],
 *   [3,1,4,2],
 *   [1,3,2,4],
 *   [2,2,4,4]
 * ]
 * 
 * Return false. Because two of the rectangles overlap with each other.
 ***************************************************************************************/


class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<string,int> mp;
        string corners[4];
        for(auto v: rectangles)
            for(int i = 0; i<4; ++i){
                corners[i] = to_string(v[i/2*2]) + "," + to_string(v[(i%2)*2+1]);
                if(mp[corners[i]] & int(pow(2,i))) return false;
                else mp[corners[i]] |= int(pow(2,i));
            }
        int corner = 0;
        for(auto i=mp.begin(); i!=mp.end(); ++i){
            int val = i->second;
            if(!(val & (val-1)) && (++corner >4)) return false;
            if((val & (val-1)) && !(val == 3 || val==12 || val==10 || val==5 || val==15)) return false;
        }
        return true;        
    }
};
