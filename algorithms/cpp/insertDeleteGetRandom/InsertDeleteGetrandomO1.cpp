// Source : https://leetcode.com/problems/insert-delete-getrandom-o1/
// Author : Hao Chen
// Date   : 2016-08-25

/*************************************************************************************** 
 *
 * Design a data structure that supports all following operations in average O(1) time.
 * 
 * insert(val): Inserts an item val to the set if not already present.
 * remove(val): Removes an item val from the set if present.
 * getRandom: Returns a random element from current set of elements. Each element must 
 * have the same probability of being returned.
 * 
 * Example:
 * 
 * // Init an empty set.
 * RandomizedSet randomSet = new RandomizedSet();
 * 
 * // Inserts 1 to the set. Returns true as 1 was inserted successfully.
 * randomSet.insert(1);
 * 
 * // Returns false as 2 does not exist in the set.
 * randomSet.remove(2);
 * 
 * // Inserts 2 to the set, returns true. Set now contains [1,2].
 * randomSet.insert(2);
 * 
 * // getRandom should return either 1 or 2 randomly.
 * randomSet.getRandom();
 * 
 * // Removes 1 from the set, returns true. Set now contains [2].
 * randomSet.remove(1);
 * 
 * // 2 was already in the set, so return false.
 * randomSet.insert(2);
 * 
 * // Since 1 is the only number in the set, getRandom always return 1.
 * randomSet.getRandom();
 ***************************************************************************************/


class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if ( find(val) ) return false; 
        data.push_back(val);
        valpos[val] = data.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if ( !find(val) ) return false; 
        
		/*
         * Tricky
         * ------
         * 1) Copy the data from the last one to the place need be removed.
         * 2) Remove the last one.
         */
        int _idx = valpos[val];
        int _val = data.back();
        
        data[_idx] = _val;
        valpos[_val] = _idx;
        
        valpos.erase(val);
        data.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return data[ rand() % data.size() ];
    }
    
private:    
    unordered_map<int, int> valpos; //value position map
    vector<int> data;
    bool find(int val) {
        return (valpos.find(val) != valpos.end());
    }
    
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
