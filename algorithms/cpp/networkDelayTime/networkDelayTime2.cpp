// Source : https://leetcode.com/problems/network-delay-time/
// Author : Sunny Lin
// Date   : 2023-06-07

/********************************************************************************** 
* 
Utilize Bellman-Ford algorithm
 */

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
using namespace std;

#define INF numeric_limits<int>::max()

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
    vector<int> _distance(n, INF);
    _distance[k - 1] = 0;

    for(int i{}; i < n-1; i++){
        for(auto & source_target_time :times){
            int source = source_target_time[0];
            int target = source_target_time[1];
            int weight = source_target_time[2];
            if(_distance[source - 1] != INF and _distance[target -1] > _distance[source -1] + weight){
                _distance[target - 1] = _distance[source -1] + weight;
            }
        }
    }

    int min_time = *max_element(_distance.begin(), _distance.end());
    if(min_time == INF) return -1;
    return min_time;
}

