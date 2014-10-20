// Source : https://oj.leetcode.com/problems/insert-interval/
// Author : Hao Chen
// Date   : 2014-08-26

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

bool compare(const Interval& lhs, const Interval& rhs){
    return (lhs.start==rhs.start) ? lhs.end < rhs.end : lhs.start < rhs.start;
}

vector<Interval> merge(vector<Interval> &intervals) {

    vector<Interval> result;

    if (intervals.size() <= 0) return result;

    sort(intervals.begin(), intervals.end(), compare);
    for(int i=0; i<intervals.size(); i++) {
        int size = result.size();
        if( size>0 && result[size-1].end >= intervals[i].start) {
            result[size-1].end = max(result[size-1].end, intervals[i].end);
        }else{
            result.push_back(intervals[i]);
        }
    }

    return result;
}

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {

    intervals.push_back(newInterval);

    return merge(intervals);
}

int main(int argc, char**argv)
{
    Interval i1(1,2);
    Interval i2(3,5);
    Interval i3(6,7);
    Interval i4(8,10);
    Interval i5(12,16);
    vector<Interval> intervals;
    intervals.push_back(i1);
    intervals.push_back(i2);
    intervals.push_back(i3);
    intervals.push_back(i4);
    intervals.push_back(i5);

    Interval n(4,9);
    vector<Interval> r = insert(intervals, n);

    for(int i=0; i<r.size(); i++){
        cout << "[ " << r[i].start << ", " << r[i].end << " ] ";
    }
    cout <<endl;

    return 0;
}
