//
//  course_schedule.cpp
//  LeeteCodeOJ#207
//
//  Created by Wang Yi on 28/11/16.
//  Copyright (c) 2016 Wang Yi. All rights reserved.
//

#include <stdio.h>

#include <stack>
#include <queue>
#include <vector>
#include <unordered_set>

using std::stack;
using std::queue;
using std::vector;
using std::unordered_set;
using std::pair;

typedef pair<int, int> Val;
typedef vector<unordered_set<int>> Graph;

#define FOR(s, e) \
for (s = 0; s < e; s++) {
#define END ;}
    
    typedef struct _node {
        int val;
        // int depth;
        struct _node * parent;
    } node;
    
    class Solution {
    public:
        bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
            vector<int> outdepth(numCourses, 0);
            unordered_set<int> vex;
            if ((int) prerequisites.size() == 0)
                return true;
            vector<unordered_set<int>> graph = to_neighbor_repr(numCourses, prerequisites, outdepth);
            
            return dsf(numCourses, graph, outdepth);
        }
        
        vector<unordered_set<int>> to_neighbor_repr(int numOfvex, vector<Val>& edges,
                                                    vector<int>& outdepth) {
            // std::cout << "building ... " << std::endl;
            vector<unordered_set<int>> graph(numOfvex);
            for (auto edge : edges) {
                graph[edge.second].insert(edge.first); // second -> first
                outdepth[edge.second]++;
                // std::cout << edge.first << " <- " << edge.second << std::endl;
            }
            
            return graph;
            
        }
        
        
        bool dsf(int numOfvex, vector<unordered_set<int>>& graph, vector<int>& outdepth)
        {
            // preparation
            stack<node> s;
            vector<bool> visited(numOfvex, false);
            vector<bool> onpath(numOfvex, false);
            vector<int> starts;
            
            int i;
            
            unordered_set<int> children;
            
            
            FOR(i, numOfvex)
            if (outdepth[i] !=0 ) {
                starts.push_back(i);
            }
            END
            
            if ((int)starts.size() == 0)
                return false; // no vertex with indepth of 0 found, a circle found
            
            for (auto j: starts) {
                // std::cout << "start from " << j << std::endl;
                // do dsf search, if not visited
                // when a circle in a path found, return false.
                // else return true
                if (visited[j])
                    continue;
                
                node head;
                head.val = j;
                head.parent = NULL;
                // head.depth = 1;
                s.push(head);
                
                // non-recursive search
                while (!s.empty()) {
                    node* curr = &(s.top());
                    
                    if (visited[curr->val]) {
                        // all children have been read
                        s.pop();
                        onpath[curr->val] = false;
                        continue; // ignore ...
                    }
                    
                    onpath[curr->val] = visited[curr->val]= true;
                    children = graph[curr->val];
                    
                    if ((int)children.size() == 0) {
                        s.pop();
                        onpath[curr->val] = false;
                        // std::cout << "==== reach the end ===="<<std::endl;
                        continue;
                    }
                    
                    // std::cout << curr->val << "'s children is: ";
                    for (auto child: children) {
                        // std::cout << child << " ";
                        //if (onpath.find(child) == onpath.end())
                        if (onpath[child]) {
                            
                            // std::cout << std::endl << "a circle found:" << std::endl;
                            // std::cout << child << " <- ";
                            // while (curr->parent != NULL) {
                            //     std::cout << curr->val << " <- ";
                            //     curr = curr->parent;
                            // }
                            // std::cout << curr->val << std::endl;
                            
                            return false; // a circle found, might print debug here
                        }
                        
                        node nd;
                        nd.val = child;
                        // nd.depth = curr->depth+1;
                        nd.parent = curr; // for debug purpose ...
                        s.push(nd);
                    }
                    // std::cout << std::endl;
                }
                
            } // end of for
            return true;
        }
        
    };