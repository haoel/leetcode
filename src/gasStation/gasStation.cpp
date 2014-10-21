// Source : https://oj.leetcode.com/problems/gas-station/
// Author : Hao Chen
// Date   : 2014-10-11

/********************************************************************************** 
* 
* There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
* 
* You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to 
* its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
* 
* Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
* 
* Note:
* The solution is guaranteed to be unique.
* 
*               
**********************************************************************************/

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
