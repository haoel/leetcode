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

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

void MergeIntervals(std::vector<std::pair<int, int>>& intervals) {
  std::sort(intervals.begin(), intervals.end());

  for (int i = 0; i < intervals.size() - 1; ++i) {
    if (intervals[i+i].first < intervals[i].second) {
      intervals[i].second = std::max(intervals[i].second, intervals[i+1].second);
      intervals.erase(intervals.begin() + i + 1); 
    }
  }
}

int main() {
  std::vector<std::pair<int, int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
  MergeIntervals(intervals);
  for (auto& v : intervals) {
    std::cout << "(" << v.first << "," << v.second << "), ";
  }
  return 0;
}
