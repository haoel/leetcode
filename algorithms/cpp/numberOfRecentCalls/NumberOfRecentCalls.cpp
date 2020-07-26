// Source : https://leetcode.com/problems/number-of-recent-calls/
// Author : Hao Chen
// Date   : 2020-07-26

/***************************************************************************************************** 
 *
 * Write a class RecentCounter to count recent requests.
 * 
 * It has only one method: ping(int t), where t represents some time in milliseconds.
 * 
 * Return the number of pings that have been made from 3000 milliseconds ago until now.
 * 
 * Any ping with time in [t - 3000, t] will count, including the current ping.
 * 
 * It is guaranteed that every call to ping uses a strictly larger value of t than before.
 * 
 * Example 1:
 * 
 * Input: inputs = ["RecentCounter","ping","ping","ping","ping"], inputs = [[],[1],[100],[3001],[3002]]
 * Output: [null,1,2,3,3]
 * 
 * Note:
 * 
 * 	Each test case will have at most 10000 calls to ping.
 * 	Each test case will call ping with strictly increasing values of t.
 * 	Each call to ping will have 1 <= t <= 10^9.
 * 
 ******************************************************************************************************/

class RecentCounter {
public:
    RecentCounter() {

    }

    int ping(int t) {
        req.push_back(t);
        return req.size() - binary_search(t-3000);
    }
private:
    vector<int> req;
    int binary_search(int x) {
        int low=0, high=req.size()-1;
        while(low < high) {
            int mid = low + (high -low) / 2;
            if ( req[mid] == x ) return mid;
            if ( req[mid] < x ) low = mid + 1;
            else high = mid - 1;
        }
        cout << "x="  << x << "\tlow=" << low << endl;
        return x > req[low] ? low+1 : low ;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
