// Source : https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
// Author : Hao Chen
// Date   : 2021-02-13

/***************************************************************************************************** 
 *
 * Given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi 
 * and ends at endDayi.
 * 
 * You can attend an event i at any day d where startTimei <= d <= endTimei. Notice that you can only 
 * attend one event at any time d.
 * 
 * Return the maximum number of events you can attend.
 * 
 * Example 1:
 * 
 * Input: events = [[1,2],[2,3],[3,4]]
 * Output: 3
 * Explanation: You can attend all the three events.
 * One way to attend them all is as shown.
 * Attend the first event on day 1.
 * Attend the second event on day 2.
 * Attend the third event on day 3.
 * 
 * Example 2:
 * 
 * Input: events= [[1,2],[2,3],[3,4],[1,2]]
 * Output: 4
 * 
 * Example 3:
 * 
 * Input: events = [[1,4],[4,4],[2,2],[3,4],[1,1]]
 * Output: 4
 * 
 * Example 4:
 * 
 * Input: events = [[1,100000]]
 * Output: 1
 * 
 * Example 5:
 * 
 * Input: events = [[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7]]
 * Output: 7
 * 
 * Constraints:
 * 
 * 	1 <= events.length <= 105
 * 	events[i].length == 2
 * 	1 <= startDayi <= endDayi <= 105
 ******************************************************************************************************/


class Solution {
private:
    static const bool comp_start(vector<int>& x, vector<int>& y) {
        if ( x[0] != y[0] ) return x[0] < y[0];
        return x[1] < y[1];
    }
    static const bool comp_end(vector<int>& x, vector<int>& y) {
        if ( x[1] != y[1] ) return x[1] < y[1];
        return x[0] < y[0];
    }


    //union find
    int find(int x, vector<int>& f) {
        if(f[x] == x) {
            return x;
        } else {
            return f[x] = find(f[x], f);
        }
    }
    void print(vector<vector<int>>& events){
        cout << "[" ;
        for(auto e: events) {
            cout << "[" << e[0] << "," << e[1] << "]," ;
        }
        cout << "]" << endl;
    }
public:
    int maxEvents(vector<vector<int>>& events) {
        return maxEvents_priority_queue(events);//332ms
        return maxEvents_union_find(events); // 336ms
    }

    int maxEvents_priority_queue(vector<vector<int>>& events) {
        std::sort(events.begin(), events.end(), comp_start);
        //print(events);

        int start = events[0][0];
        int end = 0;
        for(auto& e:events){
            end = max(end, e[1]);
        }

        int result = 0;
        int i = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int day = start; day <= end; day++) {
            while (i<events.size() && events[i][0]==day) {
                pq.push(events[i][1]); //push the ending day
                i++;
            }
            //remove out-of-date event
            while(!pq.empty() && pq.top() < day)  {
                pq.pop();
            }

            //if there still has event, then choose current day.
            if (!pq.empty()){
                pq.pop();
                result++;
            }

            //no more date need to process
            if (pq.empty() && i >= events.size()) break;
        }
        return result;
    }

    int maxEvents_union_find(vector<vector<int>>& events) {
        std::sort(events.begin(), events.end(), comp_end);


        int end = events[events.size()-1][1];
        int start = end;
        for(auto& e:events){
            start = min(start, e[0]);
        }

        vector<int> dict;
        for (int i=0; i<=end-start+1; i++){
            dict.push_back(i);
        }

        int result = 0;

        for(auto& e : events) {

            int x = find(e[0]-start, dict);
            if ( x <= e[1]-start ){
                result++;
                dict[x] = find(x+1, dict);
            }
        }

        return result;
    }
};
