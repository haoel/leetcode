// Source : https://leetcode.com/problems/course-schedule-ii/
// Author : Hao Chen
// Date   : 2015-06-10

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


class Solution {
public:
    // if has cycle, return false, else return true
    bool topologicalSort( int n, vector<int>& explored, vector<int>& path, 
                          unordered_map<int, vector<int>>& graph, 
                          vector<int>& result) 
    {
        
        for(int i=0; i<graph[n].size(); i++) {
            
            int prereq = graph[n][i];
            
            if ( path[prereq] ) {
                result.clear();
                return false;
            }
            
            path[prereq] = true;
            if (!topologicalSort(prereq, explored, path, graph, result)){
                result.clear();
                return false;
            }
            path[prereq] = false;
        }
        if (!explored[n]) {
            result.push_back(n);
        }
        explored[n] = true;
        return true;
    }

    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        vector<int> result;
        vector<int> enterance (numCourses, true);
        
        //using map to stroe the graph, it's easy to search the edge for each node
        //the bool in pair means it is explored or not
        unordered_map<int, vector<int>> graph;
        for(int i=0; i<prerequisites.size(); i++){
            graph[prerequisites[i].first].push_back( prerequisites[i].second );
            enterance[prerequisites[i].second] = false;
        }

        //explored[] is used to record the node already checked!
        vector<int> explored(numCourses, false);

        //path[] is used to check the cycle during DFS
        vector<int> path(numCourses, false);

        for(int i=0; i<numCourses; i++){
            if (!enterance[i] || explored[i]) continue;
            if (!topologicalSort(i, explored, path, graph, result)) return result;
        }
        //if there has one course hasn't been explored, means there is a cycle
        for (int i=0; i<numCourses; i++){
            if (!explored[i]) return vector<int>();
        }
        return result;
    }
};
