// Source : https://leetcode.com/problems/frog-jump/
// Author : Hao Chen
// Date   : 2016-11-12

/*************************************************************************************** 
 *
 * A frog is crossing a river. The river is divided into x units and at each unit there 
 * may or may not exist a stone. The frog can jump on a stone, but it must not jump 
 * into the water.
 * 
 * Given a list of stones' positions (in units) in sorted ascending order, determine if 
 * the frog is able to cross the river by landing on the last stone. Initially, the 
 * frog is on the first stone and assume the first jump must be 1 unit.
 * 
 * If the frog's last jump was k units, then its next jump must be either k - 1, k, or 
 * k + 1 units. Note that the frog can only jump in the forward direction.
 * 
 * Note:
 * 
 * The number of stones is ≥ 2 and is 
 * Each stone's position will be a non-negative integer 31.
 * The first stone's position is always 0.
 * 
 * Example 1:
 * 
 * [0,1,3,5,6,8,12,17]
 * 
 * There are a total of 8 stones.
 * The first stone at the 0th unit, second stone at the 1st unit,
 * third stone at the 3rd unit, and so on...
 * The last stone at the 17th unit.
 * 
 * Return true. The frog can jump to the last stone by jumping 
 * 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 
 * 2 units to the 4th stone, then 3 units to the 6th stone, 
 * 4 units to the 7th stone, and 5 units to the 8th stone.
 * 
 * Example 2:
 * 
 * [0,1,2,3,4,8,9,11]
 * 
 * Return false. There is no way to jump to the last stone as 
 * the gap between the 5th and 6th stone is too large.
 ***************************************************************************************/

class Solution {
public:
    bool canCross_recursion(vector<int>& stones, int curr, int last_jump) {
        for(int i=curr+1; i<stones.size(); i++){
            int next_jump = stones[i] - stones[curr];
            //the minimal jump is far exceed the current node, go to check next node.
            if (next_jump < last_jump - 1) continue;
            //cannot reach this one, then simple reture false;
            if (next_jump > last_jump + 1) return false;
            
            if (i == stones.size() - 1 || canCross_recursion(stones, i, next_jump)) return true;
        }
        return false;
    }
    
    bool canCross_recursion_with_cache(vector<int>& stones, int curr, int last_jump, 
                                        unordered_map<int, unordered_map<int, bool>>& cache) 
    {
        //check the cache is hitted ?
        if (cache.find(curr) != cache.end() && cache[curr].find(last_jump)!=cache[curr].end()) {
            return cache[curr][last_jump];
        }
        
        for(int i=curr+1; i<stones.size(); i++){
            int next_jump = stones[i] - stones[curr];
            if (next_jump < last_jump - 1) continue;
            if (next_jump > last_jump + 1) break;
            if (i == stones.size() - 1 || canCross_recursion_with_cache(stones, i, next_jump, cache)) {
                cache[curr][last_jump] = true;
                return true;
            }
        }
        cache[curr][last_jump] = false;
        return false;
    }
    
    bool canCross_non_recursion(vector<int>& stones) {
        
        // the `jumps` map store the all possible `last jumps`
        unordered_map<int, unordered_set<int>> jumps = {{0, {0}}};
        
        for(int i=0; i<stones.size(); i++) {
            if (jumps.find(i) == jumps.end()){ 
                continue;
            }
            //for each possible last jump which reach the current node.
            for(int last_jump : jumps[i]) {
                //find the next nodes can be reached.
                for (int j=i+1; j < stones.size(); j++) {
                    //ingore the rest node which cannot be reached
                    if (stones[i] + last_jump + 1 < stones[j]) break;
                    
                    // evaluated three possbile jumps for next node 
                    for (int next_jump  = last_jump - 1;   next_jump <= last_jump + 1;  next_jump++)  {
                        if ( stones[i] + next_jump  == stones[j] ) {
                            jumps[j].insert(next_jump);
                        }
                    }
                        
                }
            }
        }
        
        return jumps.find(stones.size()-1)!=jumps.end();
    }
    
    bool canCross(vector<int>& stones) {
        
        //Burst Force solution -- accepted ~500ms
        return canCross_non_recursion(stones);
        
        //DFS with cache solution - accepted ~160ms
        unordered_map<int, unordered_map<int, bool>> cache;
        return canCross_recursion_with_cache(stones, 0, 0, cache);
        
        // Time Limit Error 
        return canCross_recursion(stones, 0, 0); 
        
    }
};
