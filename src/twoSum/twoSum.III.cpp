// Source : https://oj.leetcode.com/problems/two-sum-iii-data-structure-design/
// Author : Hao Chen
// Date   : 2014-12-29

/********************************************************************************** 
* 
* Design and implement a TwoSum class. It should support the following operations: add and find.
* 
* add - Add the number to an internal data structure.
* find - Find if there exists any pair of numbers which sum is equal to the value.
* 
* For example,
*
*   add(1); add(3); add(5);
*   find(4) -> true
*   find(7) -> false
* 
**********************************************************************************/

class TwoSum {
    private:
        unordered_map<int, int> nums;
    public:

        //O(1) add
        void add(int number) {
            nums[number]++;
        }

        //O(n) find
        bool find(int value) {
            int one, two;
            for(auto it = nums.begin(); it != nums.end(); it++){
                one = it->first;
                two = value - one;
                if ( (one == two && it->second > 1) ||
                        (one != two && nums.find(two) != nums.end() ) ){
                    return true;
                }
            }
            return false;
        }
};
