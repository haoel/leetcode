// Source : https://leetcode.com/problems/find-median-from-data-stream/
// Author : Hao Chen
// Date   : 2015-11-14

/*************************************************************************************** 
 *
 * Median is the middle value in an ordered integer list. If the size of the list is 
 * even, there is no middle value. So the median is the mean of the two middle value.
 * Examples: 
 * [2,3,4] , the median is 3
 * [2,3], the median is (2 + 3) / 2 = 2.5 
 * 
 * Design a data structure that supports the following two operations:
 * 
 * void addNum(int num) - Add a integer number from the data stream to the data 
 * structure.
 * double findMedian() - Return the median of all elements so far.
 * 
 * For example:
 * 
 * add(1)
 * add(2)
 * findMedian() -> 1.5
 * add(3) 
 * findMedian() -> 2
 * 
 * Credits:Special thanks to @Louis1992 for adding this problem and creating all test 
 * cases.
 *               
 ***************************************************************************************/


class MedianFinder {
    
private:
    //we seprate the sorted array to two parts
    multiset<int> first, second;
    
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if (first.empty() || num <= *(first.rbegin()) ) {
            first.insert(num);
        } else {
            second.insert(num);
        }
        
        if (first.size() > second.size() + 1) {
            auto it = first.end();
            it--;
            second.insert(*(it));
            first.erase(it);
        }
        
        if ( first.size() < second.size() ) {
            first.insert(*(second.begin()));
            second.erase(second.begin());
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (first.size()> second.size()) {
            return *(first.rbegin());
        }
        double x = *first.rbegin();
        double y = *second.begin();
        return (x+y)/2;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
