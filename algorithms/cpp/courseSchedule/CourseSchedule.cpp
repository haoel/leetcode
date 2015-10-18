// Source : https://leetcode.com/problems/course-schedule/
// Author : Hao Chen
// Date   : 2015-06-09

/********************************************************************************** 
 * 
 * There are a total of n courses you have to take, labeled from 0 to n - 1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
 * which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it possible for you to 
 * finish all courses?
 * 
 * For example:
 *      2, [[1,0]]
 * There are a total of 2 courses to take. To take course 1 you should have finished course 0. 
 * So it is possible.
 * 
 *      2, [[1,0],[0,1]]
 * There are a total of 2 courses to take. To take course 1 you should have finished course 0, 
 * and to take course 0 you should also have finished course 1. So it is impossible.
 * 
 * Note:
 * The input prerequisites is a graph represented by a list of edges, not adjacency matrices. 
 * Read more about how a graph is represented.
 * 
 * click to show more hints.
 * 
 * Hints:
 * 
 *  - This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, 
 *    no topological ordering exists and therefore it will be impossible to take all courses.
 *
 *  - Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic 
 *    concepts of Topological Sort. (https://class.coursera.org/algo-003/lecture/52)
 *
 *  - Topological sort could also be done via BFS. (http://en.wikipedia.org/wiki/Topological_sorting#Algorithms)
 * 
 *               
 **********************************************************************************/


class Solution {
public:

    bool hasCycle(int n, vector<int>& explored, vector<int>& path, map<int, vector<int>>& graph) {
        
        for(int i=0; i<graph[n].size(); i++){
            
            //detect the cycle
            if ( path[graph[n][i]] ) return true;
            
            //set the marker
            path[graph[n][i]] = true;
            
            if (hasCycle(graph[n][i], explored, path, graph)) {
                return true;
            }
            //backtrace reset
            path[graph[n][i]] = false;
        }
        //no cycle found, mark this node can finished!
        explored[n] = true;
        return false;
        
    }

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        //using map to stroe the graph, it's easy to search the edge for each node
        //the bool in pair means it is explored or not
        map<int, vector<int>> graph;
        for(int i=0; i<prerequisites.size(); i++){
            graph[prerequisites[i].first].push_back( prerequisites[i].second );
        }
        
        //explored[] is used to record the node already checked!
        vector<int> explored(numCourses, false);
        
        //path[] is used to check the cycle during DFS
        vector<int> path(numCourses, false);
        
        for(int i=0; i<numCourses; i++){
            
            if (explored[i]) continue;
            if (hasCycle(i, explored, path, graph)) return false;
            

        }
        return true;
    }
};
