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
        int total = 0;
        int start = -1; // initially, start + 1 is 0
        for(int i = 0; i < gas.size(); i++){
            current += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if(current < 0){
                current = 0;
                start = i;
            }
        }
        return total>=0 ? start + 1 : -1;
    }
};
