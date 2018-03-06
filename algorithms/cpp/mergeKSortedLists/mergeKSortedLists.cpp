#include <algorithm>
#include <cstdarg>
#include <forward_list>
#include <iostream>
#include <utility>
#include <vector>

std::forward_list<int>* MergeKSortedLists(int k...) {
  va_list args;
  va_start(args, k);

  std::vector<std::pair<int, std::forward_list<int>*>> heap;
  
  for (int i = 0; i < k; ++i) {
    auto l =  va_arg(args, std::forward_list<int>*);
    if (!l->empty()) {
      heap.push_back(std::make_pair(l->front(), l));
      l->pop_front();
    }
  }

  std::make_heap(heap.begin(), heap.end());

  auto result = new std::forward_list<int>();

  while (heap.size() > 0) {
    std::pop_heap(heap.begin(), heap.end());
    result->push_front(heap.back().first);
    auto l = heap.back().second;
    if (!l->empty()) {
      heap.back().first = l->front();
      l->pop_front();
      std::push_heap(heap.begin(), heap.end());
    } else {
      heap.pop_back();
    }
  }

  result->reverse();
  return result;
}

int main() {
  std::forward_list<int> v1 {4 ,3, 1};
  std::forward_list<int> v2 {};
  std::forward_list<int> v3 {2};

  std::forward_list<int>* r = MergeKSortedLists(3, &v1, &v2, &v3);
  std::copy(r->begin(), r->end(), std::ostream_iterator<int>(std::cout, " "));
  delete r;

  return 0;
}
