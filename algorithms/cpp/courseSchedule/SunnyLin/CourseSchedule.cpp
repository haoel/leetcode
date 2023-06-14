// Source : https://leetcode.com/problems/course-schedule/
// Author : Sunny Lin
// Date   : 2023-06-05

/********************************************************************************** 
 * 
 * There are a total of n courses you have to take, labeled from 0 to n - 1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
 * which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, return the ordering of courses 
 * you should take to finish all courses.
 * 
 * There may be multiple correct orders, you just need to return one of them. If it is impossible to 
 * finish all courses, return an empty array.
 * 
 * For example:
 *      2, [[1,0]]
 * There are a total of 2 courses to take. To take course 1 you should have finished course 0. 
 * So the correct course order is [0,1]
 * 
 *      4, [[1,0],[2,0],[3,1],[3,2]]
 * There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. 
 * Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. 
 * Another correct ordering is[0,2,1,3].
 * 
 * Note:
 * The input prerequisites is a graph represented by a list of edges, not adjacency matrices. 
 * Read more about how a graph is represented.
 * 
 * click to show more hints.
 * 
 * Hints:
 * 
 *  - This problem is equivalent to finding the topological order in a directed graph. If a cycle exists, 
 *    no topological ordering exists and therefore it will be impossible to take all courses.
 *
 *  - Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining 
 *    the basic concepts of Topological Sort.
 *
 *  - Topological sort could also be done via BFS.
 * 
 *               
 **********************************************************************************/

#include <stdio.h>

#include <queue>
#include <vector>
#include <unordered_set>

using std::queue;
using std::vector;
using std::pair;

bool dfs(int head, vector<vector<int>>& adjlist, vector<bool>& seen){

    if (seen[head] == false){
        seen[head] = true;
    }
    else{
        return false;
    }

    for(auto& adj: adjlist[head]){
        
        if( not dfs(adj, adjlist, seen)){
            return false;
        }
    }
    return true;

}


bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adjlist(numCourses);
    int current{};

    queue<int> q;
    for(auto& pair: prerequisites){
        adjlist[pair[1]].push_back(pair[0]);
    }

    for(int v{}; v < adjlist[v].size(); v++){
        vector<bool> seen(numCourses, false);
        for(auto& adj_v : adjlist[v]){
            q.push(adj_v);
        }

        while (!q.empty())
        {   
            current = q.front();
            if(current == v)return false;
            q.pop();
            seen[current] = true;
            for(auto& adj_current: adjlist[current]){
                if(~seen[adj_current]){
                    q.push(adj_current);
                }
            }
        }
    }
    return true;
}