// Source : https://leetcode.com/problems/interval-list-intersections/
// Author : Hao Chen
// Date   : 2019-02-05

/***************************************************************************************************** 
 *
 * Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted 
 * order.
 * 
 * Return the intersection of these two interval lists.
 * 
 * (Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= 
 * b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can 
 * be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)
 * 
 * Example 1:
 *    
 *             0   2     5      10     13           23 24 25
 *      A     +---+     +-------+     +-------------+  +--+
 *    
 *               1      5    8     12      15        24 25  26
 *      B        +------+    +------+      +----------+  +--+
 *    
 *              1  2    5    8  10         15      23 24 25
 *    Ans        ++     +    +--+          +--------+ +  +
 *    
 * 
 * Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
 * Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 * Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.
 * 
 * Note:
 * 
 * 	0 <= A.length < 1000
 * 	0 <= B.length < 1000
 * 	0 <= A[i].start, A[i].end, B[i].start, B[i].end < 109
 * 
 ******************************************************************************************************/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    //return true if lhs starts earlier than  rhs
    bool compareInterval(Interval& lhs, Interval& rhs) {
        return lhs.start < rhs.start;
    }
    //check two interval overlapped or not
    bool overlapped(Interval& lhs, Interval& rhs) {
        return (compareInterval(lhs, rhs)) ?
                             lhs.end >= rhs.start:
                             rhs.end >= lhs.start;

    }
    //merge two interval - return the intersections of two intervals
    Interval mergeTwoInterval(Interval& lhs, Interval& rhs) {
        Interval result;
        result.start = max(lhs.start, rhs.start);
        result.end = min(lhs.end, rhs.end);
        return result;
    }

    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        int lenA = A.size();
        int lenB = B.size();

        vector<Interval> result;
        if (lenA <=0 || lenB<=0) return result; //edge case

        int i=0, j=0;
        while ( i < lenA && j < lenB ) {
            if( overlapped(A[i], B[j]) ) {
                result.push_back(mergeTwoInterval(A[i], B[j]));
                // if the current interval is not overlapped with next one,
                // then we move the next interval.
                int nexti = i;
                if ( j==lenB-1 || !overlapped(A[i], B[j+1]) ) nexti=i+1;
                if ( i==lenA-1 || !overlapped(A[i+1], B[j]) ) j++;
                i = nexti;
            }else{
                //if not overlapped, we just move the next one
                compareInterval(A[i], B[j]) ? i++ : j++;
            }
        }
        return result;
    }
};
