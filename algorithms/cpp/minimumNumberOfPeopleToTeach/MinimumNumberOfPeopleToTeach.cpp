// Source : https://leetcode.com/problems/minimum-number-of-people-to-teach/
// Author : Hao Chen
// Date   : 2021-02-17

/***************************************************************************************************** 
 *
 * On a social network consisting of m users and some friendships between users, two users can 
 * communicate with each other if they know a common language.
 * 
 * You are given an integer n, an array languages, and an array friendships where:
 * 
 * 	There are n languages numbered 1 through n,
 * 	languages[i] is the set of languages the i​​​​​​th​​​​ user knows, and
 * 	friendships[i] = [u​​​​​​i​​​, v​​​​​​i] denotes a friendship between the users u​​​​​​​​​​​
 * i​​​​​ and vi.
 * 
 * You can choose one language and teach it to some users so that all friends can communicate with 
 * each other. Return the minimum number of users you need to teach.
 * Note that friendships are not transitive, meaning if x is a friend of y and y is a friend of z, 
 * this doesn't guarantee that x is a friend of z.
 * 
 * Example 1:
 * 
 * Input: n = 2, languages = [[1],[2],[1,2]], friendships = [[1,2],[1,3],[2,3]]
 * Output: 1
 * Explanation: You can either teach user 1 the second language or user 2 the first language.
 * 
 * Example 2:
 * 
 * Input: n = 3, languages = [[2],[1,3],[1,2],[3]], friendships = [[1,4],[1,2],[3,4],[2,3]]
 * Output: 2
 * Explanation: Teach the third language to users 1 and 3, yielding two users to teach.
 * 
 * Constraints:
 * 
 * 	2 <= n <= 500
 * 	languages.length == m
 * 	1 <= m <= 500
 * 	1 <= languages[i].length <= n
 * 	1 <= languages[i][j] <= n
 * 	1 <= u​​​​​​i < v​​​​​​i <= languages.length
 * 	1 <= friendships.length <= 500
 * 	All tuples (u​​​​​i, v​​​​​​i) are unique
 * 	languages[i] contains only unique values
 ******************************************************************************************************/

class Solution {

public:
    bool hasLang(vector<int>& langlist, int lang){
        for(auto& l : langlist) {
            if (l == lang) return true;
        }
        return false;
    }
    
    bool canComm(int u, int v, int n, vector<vector<bool>>& langs) {
        for (int l=0; l<n; l++) {
            if (langs[u][l] && langs[v][l]) return true;
        }
        return false;
    }
    
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int persons = languages.size();
        //use to check a person know a langauge or not
        vector<vector<bool>> langs(persons, vector<bool>(n, false));
        for (int p=0; p<persons; p++) {
            for(int l=0; l<languages[p].size(); l++) {
                langs[p][languages[p][l]-1] = true;
            }
        } 
        
        int result = persons;
        vector<vector<bool>> langToTeach(n, vector<bool>(persons, false));
        for (int l=0; l <n; l++) {
            int cnt = 0;
            vector<bool> teach(persons, false);
            for (auto& fs : friendships) {
                int u = fs[0] - 1;
                int v = fs[1] - 1;

                if (canComm(u, v, n, langs)) continue;

                if (langs[u][l]==false && teach[u]==false) {
                    teach[u] = true; cnt++;
                }
                if (langs[v][l]==false && teach[v]==false) {
                    teach[v] = true; cnt++;
                }
            }
            result = min(result, cnt);
        }
        
        return result;
    }
};
