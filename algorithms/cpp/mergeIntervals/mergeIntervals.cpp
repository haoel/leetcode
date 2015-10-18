// Source : https://oj.leetcode.com/problems/merge-intervals/
// Author : Hao Chen
// Date   : 2014-08-26

/********************************************************************************** 
* 
* Given a collection of intervals, merge all overlapping intervals.
* 
* For example,
* Given [1,3],[2,6],[8,10],[15,18],
* return [1,6],[8,10],[15,18].
* 
*               
**********************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

//Two factos sorting [start:end]
bool compare(const Interval& lhs, const Interval& rhs){
    return (lhs.start==rhs.start) ? lhs.end < rhs.end : lhs.start < rhs.start;
}

vector<Interval> merge(vector<Interval> &intervals) {

    vector<Interval> result;

    if (intervals.size() <= 0) return result;
    //sort the inervals. Note: using the customized comparing function.
    sort(intervals.begin(), intervals.end(), compare);
    for(int i=0; i<intervals.size(); i++) { 
        int size = result.size();
        // if the current intervals[i] is overlapped with previous interval.
        // merge them together
        if( size>0 && result[size-1].end >= intervals[i].start) {
            result[size-1].end = max(result[size-1].end, intervals[i].end); 
        }else{
            result.push_back(intervals[i]);
        }
    }
    
    return result;
}


int main(int argc, char**argv)
{
    Interval i1(1,4);
    Interval i2(0,2);
    Interval i3(3,5);
    Interval i4(15,18);
    vector<Interval> intervals;
    intervals.push_back(i1);
    intervals.push_back(i2);
    intervals.push_back(i3);
    intervals.push_back(i4);
    
    vector<Interval> r = merge(intervals);
    
    for(int i=0; i<r.size(); i++){
        cout << "[ " << r[i].start << ", " << r[i].end << " ] ";
    }
    cout <<endl;

    return 0;
}
