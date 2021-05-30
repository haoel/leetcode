// Source : https://leetcode.com/problems/process-tasks-using-servers/
// Author : Hao Chen
// Date   : 2021-05-30

/***************************************************************************************************** 
 *
 * You are given two 0-indexed integer arrays servers and tasks of lengths n and m 
 * respectively. servers[i] is the weight of the i^th server, and tasks[j] is the time 
 * needed to process the j^th task in seconds.
 * 
 * You are running a simulation system that will shut down after all tasks are processed. Each server 
 * can only process one task at a time. You will be able to process the j^th task starting from the 
 * j^th second beginning with the 0^th task at second 0. To process task j, you assign it to the 
 * server with the smallest weight that is free, and in case of a tie, choose the server with the 
 * smallest index. If a free server gets assigned task j at second t, it will be free again at 
 * the second t + tasks[j].
 * 
 * If there are no free servers, you must wait until one is free and execute the free tasks as soon as 
 * possible. If multiple tasks need to be assigned, assign them in order of increasing index.
 * 
 * You may assign multiple tasks at the same second if there are multiple free servers.
 * 
 * Build an array ans of length m, where ans[j] is the index of the server the j^th task 
 * will be assigned to.
 * 
 * Return the array ans.
 * 
 * Example 1:
 * 
 * Input: servers = [3,3,2], tasks = [1,2,3,2,1,2]
 * Output: [2,2,0,2,1,2]
 * Explanation: Events in chronological order go as follows:
 * - At second 0, task 0 is added and processed using server 2 until second 1.
 * - At second 1, server 2 becomes free. Task 1 is added and processed using server 2 until second 3.
 * - At second 2, task 2 is added and processed using server 0 until second 5.
 * - At second 3, server 2 becomes free. Task 3 is added and processed using server 2 until second 5.
 * - At second 4, task 4 is added and processed using server 1 until second 5.
 * - At second 5, all servers become free. Task 5 is added and processed using server 2 until second 7.
 * 
 * Example 2:
 * 
 * Input: servers = [5,1,4,3,2], tasks = [2,1,2,4,5,2,1]
 * Output: [1,4,1,4,1,3,2]
 * Explanation: Events in chronological order go as follows: 
 * - At second 0, task 0 is added and processed using server 1 until second 2.
 * - At second 1, task 1 is added and processed using server 4 until second 2.
 * - At second 2, servers 1 and 4 become free. Task 2 is added and processed using server 1 until 
 * second 4. 
 * - At second 3, task 3 is added and processed using server 4 until second 7.
 * - At second 4, server 1 becomes free. Task 4 is added and processed using server 1 until second 9. 
 * - At second 5, task 5 is added and processed using server 3 until second 7.
 * - At second 6, task 6 is added and processed using server 2 until second 7.
 * 
 * Constraints:
 * 
 * 	servers.length == n
 * 	tasks.length == m
 * 	1 <= n, m <= 2 * 10^5
 * 	1 <= servers[i], tasks[j] <= 2 * 10^5
 ******************************************************************************************************/

class Solution {
private:
    template<class T>
    void print(T  q) {
        cout << "[";
        while(!q.empty()) {
            auto& p = q.top(); 
            cout << "[" << p.first << ","<< p.second << "]";
            q.pop();
        }
        cout << "]" << endl;
    }
public:
    
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        typedef pair<int,int> IntPair;
        typedef priority_queue<IntPair, vector<IntPair>, greater<IntPair>> PriorityQueue;
        
        // asc sorted by {weight, index}
        PriorityQueue idle;
        // asc sorted by {time, index}
        PriorityQueue busy;
        
        for(int i=0; i<servers.size(); i++){
            idle.push({servers[i], i});
        }
        
        //print(idle);
        
        int time = 0;
        vector<int> ans;
        for(int i=0; i<tasks.size(); i++) {
            time = max(i, time);

            //check the tasks finished
            while(true) { 
                while(!busy.empty()){
                    auto& t = busy.top().first;
                    auto& id = busy.top().second;
                    if (t > time) break;
                    idle.push({servers[id], id});
                    busy.pop();
                }
                if (!idle.empty())  break;
                //set the time to the fisrt finish running task 
                time = busy.top().first;
            }
            
            //process the current task
            auto& id = idle.top().second;
            ans.push_back(id);
            busy.push({time + tasks[i], id});
            idle.pop();
        }
        
        return ans;
    }
};
