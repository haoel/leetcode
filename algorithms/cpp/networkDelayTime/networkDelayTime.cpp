// Source : https://leetcode.com/problems/network-delay-time/
// Author : Sunny Lin
// Date   : 2023-06-07

/********************************************************************************** 
* 
Utilize Dijkstra's algorithm
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

struct  cmp
{
    bool operator()(pair<int, int>a, pair<int, int>b){
        return a.second > b.second;
    }
};

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
    vector<vector<pair<int, int>>> adjlist(n);
    for(auto & time: times){
        adjlist[time[0] - 1].push_back({time[1] - 1, time[2]});
    }

    vector<int> _distance(n, INF);
    _distance[k - 1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>q;
    q.push({k - 1, 0});
    
    while (!q.empty())
    {
        int current_vertex = q.top().first;
        q.pop();
        for(auto& adj_neighbor: adjlist[current_vertex]){
            int neighboring_vertex = adj_neighbor.first;
            int weight = adj_neighbor.second;
            if(_distance[neighboring_vertex] > ( _distance[current_vertex] + weight)){
                _distance[neighboring_vertex] = _distance[current_vertex] + weight;
                q.push({neighboring_vertex, _distance[neighboring_vertex]});
            }
        }
    }
    int min_time = *max_element(_distance.begin(), _distance.end());
    if(min_time == INF) return -1;
    return min_time;
}

