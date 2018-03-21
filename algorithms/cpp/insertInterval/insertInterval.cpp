// Source : https://oj.leetcode.com/problems/insert-interval/
// Author : Hao Chen
// Date   : 2014-08-26

/********************************************************************************** 
* 
* Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
* 
* You may assume that the intervals were initially sorted according to their start times.
* 
* Example 1:
* Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
* 
* Example 2:
* Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
* 
* This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
* 
*               
**********************************************************************************/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

void InsertInterval(std::vector<std::pair<int, int> >& intervals,
		    std::pair<int, int>& itvl) {
  auto pos = std::lower_bound(intervals.begin(), intervals.end(), itvl);

  int start = std::max(0L,
		       std::distance(intervals.begin(), pos) - 1);
  int left = itvl.first;
  int right = itvl.second;
  int num_merges = 0;
  for (int i = start; i < intervals.size(); ++i) {
    if ((left <= intervals[i].first && intervals[i].first <= right) ||
	(left <= intervals[i].second && intervals[i].second <= right)) {
      num_merges++;
      left = std::min(intervals[i].first, left);
      right = std::max(intervals[i].second, right);
    }
  }

  if (num_merges > 0) {
    intervals[start].first = left;
    intervals[start].second = right;
    for (int i = 1; i < num_merges; ++i) {
      intervals.erase(intervals.begin() + start + 1);
    }
  } else {
    intervals.insert(pos, itvl);
  }
}

int main() {
  std::vector<std::pair<int, int> > intervals =
    { {1,2},{3,5},{6,7},{8,10},{12,16}};
  std::pair<int, int> itvl(4,9);
  InsertInterval(intervals, itvl);

  for (auto& i : intervals) {
    std::cout << "(" << i.first << "," << i.second << "), ";
  }
  std::cout << "\n";
  return 0;
}
