// Source : https://leetcode.com/problems/time-needed-to-inform-all-employees/
// Author : Shreya Vanga
// Date   : 2020-10-02

/*************************************************************************************** 
 *
 * A company has n employees with a unique ID for each employee from 0 to n - 1. 
 * The head of the company has is the one with headID.
 *
 * Each employee has one direct manager given in the manager array where manager[i] is 
 * the direct manager of the i-th employee, manager[headID] = -1. Also it's guaranteed 
 * that the subordination relationships have a tree structure.
 *
 * The head of the company wants to inform all the employees of the company of an urgent 
 * piece of news. He will inform his direct subordinates and they will inform their 
 * subordinates and so on until all employees know about the urgent news.
 *
 * The i-th employee needs informTime[i] minutes to inform all of his direct subordinates 
 * (i.e After informTime[i] minutes, all his direct subordinates can start spreading the news).
 *
 * Return the number of minutes needed to inform all the employees about the urgent news.
 * 
 * Example:
 * 
 * Given: n = 1, headID = 0, manager = [-1], informTime = [0]
 * Return: 0
 * 
 * Given: n = 7, headID = 6, manager = [1,2,3,4,5,6,-1], informTime = [0,6,5,4,3,2,1]
 * Return: 21 
 * 
 ***************************************************************************************/





class Solution {
public:
    vector<int>visited;
    long long int dfs(vector<vector<int>>& adj, vector<int>& informTime, int src, int n)
    {
        long long int count = 0;
        for(int i=0;i<adj[src].size();i++)
        {
            count = max(count,dfs(adj, informTime, adj[src][i], n));
        }
        return (informTime[src]+count);
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>adj(n);
        for(int i=0;i<manager.size();i++)
        {
            if(manager[i] != -1)
                adj[manager[i]].push_back(i);
        }
        long long int time;
        visited.resize(n,0);
        visited[headID] = 1;
        time= dfs(adj, informTime, headID, n);
        return time;
    }
};
