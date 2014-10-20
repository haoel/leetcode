// Source : https://oj.leetcode.com/problems/gas-station/
// Author : Hao Chen
// Date   : 2014-10-11

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int current = 0;
        int start = gas.size(); //start from the end to beginning
        int total = 0;
        
        do {
            if (total + gas[current] - cost[current] >= 0) {
                total += (gas[current] - cost[current]);
                current++; // can go from current to current+1
            }else{
                start--; //not enough gas, try to start the one before origin start point.
                total += (gas[start] - cost[start]);
            }
        } while(current != start);
        
        return total>=0 ? start % gas.size() : -1;
    }
};
