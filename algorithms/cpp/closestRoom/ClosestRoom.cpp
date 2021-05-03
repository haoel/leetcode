// Source : https://leetcode.com/problems/closest-room/
// Author : Hao Chen
// Date   : 2021-05-03

/***************************************************************************************************** 
 *
 * There is a hotel with n rooms. The rooms are represented by a 2D integer array rooms where rooms[i] 
 * = [roomIdi, sizei] denotes that there is a room with room number roomIdi and size equal to sizei. 
 * Each roomIdi is guaranteed to be unique.
 * 
 * You are also given k queries in a 2D array queries where queries[j] = [preferredj, minSizej]. The 
 * answer to the j^th query is the room number id of a room such that:
 * 
 * 	The room has a size of at least minSizej, and
 * 	abs(id - preferredj) is minimized, where abs(x) is the absolute value of x.
 * 
 * If there is a tie in the absolute difference, then use the room with the smallest such id. If there 
 * is no such room, the answer is -1.
 * 
 * Return an array answer of length k where answer[j] contains the answer to the j^th query.
 * 
 * Example 1:
 * 
 * Input: rooms = [[2,2],[1,2],[3,2]], queries = [[3,1],[3,3],[5,2]]
 * Output: [3,-1,3]
 * Explanation: The answers to the queries are as follows:
 * Query = [3,1]: Room number 3 is the closest as abs(3 - 3) = 0, and its size of 2 is at least 1. The 
 * answer is 3.
 * Query = [3,3]: There are no rooms with a size of at least 3, so the answer is -1.
 * Query = [5,2]: Room number 3 is the closest as abs(3 - 5) = 2, and its size of 2 is at least 2. The 
 * answer is 3.
 * 
 * Example 2:
 * 
 * Input: rooms = [[1,4],[2,3],[3,5],[4,1],[5,2]], queries = [[2,3],[2,4],[2,5]]
 * Output: [2,1,3]
 * Explanation: The answers to the queries are as follows:
 * Query = [2,3]: Room number 2 is the closest as abs(2 - 2) = 0, and its size of 3 is at least 3. The 
 * answer is 2.
 * Query = [2,4]: Room numbers 1 and 3 both have sizes of at least 4. The answer is 1 since it is 
 * smaller.
 * Query = [2,5]: Room number 3 is the only room with a size of at least 5. The answer is 3.
 * 
 * Constraints:
 * 
 * 	n == rooms.length
 * 	1 <= n <= 10^5
 * 	k == queries.length
 * 	1 <= k <= 10^4
 * 	1 <= roomIdi, preferredj <= 10^7
 * 	1 <= sizei, minSizej <= 10^7
 * 
 ******************************************************************************************************/

class Solution {
private:
    void print(vector<vector<int>>& vv) {
        cout << "[";
        int i = 0;
        for(; i<vv.size()-1; i++) {
            cout << "[" << vv[i][0] << "," << vv[i][1] << "],";
        }
        cout << "[" << vv[i][0] << "," << vv[i][1] << "]]" << endl;
    }
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        

        for(int i=0; i<queries.size(); i++) { 
            queries[i].push_back(i);
        }
        
        // sorted the rooms by size by descending order, because query the minimal size.
        auto sort_by_size_desc =  [&](vector<int>& lhs, vector<int>&rhs) {
            if (lhs[1] != rhs[1] ) return lhs[1] > rhs[1];
            return lhs[0] < rhs[0];
        };
        sort(rooms.begin(), rooms.end(), sort_by_size_desc);
        sort(queries.begin(), queries.end(), sort_by_size_desc);
        //print(rooms);
        //print(queries);
        
        vector<int> result(queries.size(), -1);
        set<int> ids;
        int i = 0;
        for( auto& q: queries) {
            int preferId = q[0];
            int minSize = q[1];
            int idx = q[2];
            for (;i < rooms.size() && rooms[i][1] >= minSize; i++) {
                ids.insert(rooms[i][0]);
            }
            if (ids.size() <= 0 ) continue;
            auto it = ids.lower_bound(preferId); 
            
            int id1 = (it == ids.begin() ? -1 : *(prev(it)));
            int id2 = (it == ids.end() ? -1 : *it);
            
            if (id1 == -1 || id2 == -1) {
                result[idx] = max(id1, id2);
            }else{
                result[idx] = abs(preferId - id1) <= abs(preferId - id2) ? id1 : id2;
            }
            
        }
        return result;
    }
};
