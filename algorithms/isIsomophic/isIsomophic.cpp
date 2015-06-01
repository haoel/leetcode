//
//  Solution.cpp
//  LeetCode-205-IsomorphicStrings
//
//  Created by Tong Li on 1/06/2015.
//  Copyright (c) 2015 Tong Li. All rights reserved.
//

#include "Solution.h"
#include <string>
#include <unordered_map>

using namespace std;

bool Solution::isIsomophic(string s, string t) {
    
    // First of all, check their length
    if (s.length() != t.length()) {
        return false;
    }
    
    // A hash table to store the mapping
    unordered_map<char, char> map;
    unordered_map<char, char> mapReverse;
    
    for (int i = 0; i < s.length(); ++i) {
        // check if the mapping key exists
        if (map.find(s[i]) == map.end()) {
            // Couldn't find the key in the map,
            // so we store the key and value into the map
            map[s[i]] = t[i];
        } else if (map[s[i]] != t[i]) {
            // We found the key, so we need to compare whether the value matched
            return false;
        } else {
            continue;
        }
        
        // check the other way around
        if (mapReverse.find(t[i]) == mapReverse.end()) {
            mapReverse[t[i]] = s[i];
        } else if (mapReverse[t[i]] != s[i]) {
            return false;
        }
    }
    
    return true;
}