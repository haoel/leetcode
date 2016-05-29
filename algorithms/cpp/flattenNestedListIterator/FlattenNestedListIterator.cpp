// Source : https://leetcode.com/problems/flatten-nested-list-iterator/
// Author : Hao Chen
// Date   : 2016-05-30

/*************************************************************************************** 
 *
 * Given a nested list of integers, implement an iterator to flatten it.
 * 
 * Each element is either an integer, or a list -- whose elements may also be integers 
 * or other lists.
 * 
 * Example 1:
 * Given the list [[1,1],2,[1,1]],
 * 
 * By calling next repeatedly until hasNext returns false, the order of elements 
 * returned by next should be: [1,1,2,1,1].
 * 
 * Example 2:
 * Given the list [1,[4,[6]]],
 * 
 * By calling next repeatedly until hasNext returns false, the order of elements 
 * returned by next should be: [1,4,6].
 ***************************************************************************************/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
    vector<int> v;
    int index;
    void flatten(vector<NestedInteger> &nestedList) {
        for (auto item : nestedList){
            if (item.isInteger()){
                v.push_back( item.getInteger() );
            }else{
                flatten( item.getList() );
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
        index = 0;
    }

    int next() {
        return v[index++];
    }

    bool hasNext() {
        return (index < v.size() );
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
