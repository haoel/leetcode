// Source : https://oj.leetcode.com/problems/word-ladder/
// Author : Hao Chen
// Date   : 2014-10-12

/********************************************************************************** 
* 
* Given two words (start and end), and a dictionary, find the length of shortest 
* transformation sequence from start to end, such that:
* 
* Only one letter can be changed at a time
* Each intermediate word must exist in the dictionary
* 
* For example,
* 
* Given:
* start = "hit"
* end = "cog"
* dict = ["hot","dot","dog","lot","log"]
* 
* As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
* return its length 5.
* 
* Note:
* 
* Return 0 if there is no such transformation sequence.
* All words have the same length.
* All words contain only lowercase alphabetic characters.
* 
*               
**********************************************************************************/

// --------------------------- 
//  BFS non-recursive method
// ---------------------------
//
//    Using BFS instead of DFS is becasue the solution need the shortest transformation path.
//  
//    So, we can change every char in the word one by one, until find all possible transformation.
//
//    Keep this iteration, we will find the shorest path.
//
// For example:
//   
//     start = "hit"
//     end = "cog"
//     dict = ["hot","dot","dog","lot","log","dit","hig", "dig"]
//
//                      +-----+                  
//        +-------------+ hit +--------------+   
//        |             +--+--+              |   
//        |                |                 |   
//     +--v--+          +--v--+           +--v--+
//     | dit |    +-----+ hot +---+       | hig |
//     +--+--+    |     +-----+   |       +--+--+
//        |       |               |          |   
//        |    +--v--+         +--v--+    +--v--+
//        +----> dot |         | lot |    | dig |
//             +--+--+         +--+--+    +--+--+
//                |               |          |   
//             +--v--+         +--v--+       |   
//        +----> dog |         | log |       |   
//        |    +--+--+         +--+--+       |   
//        |       |               |          |   
//        |       |    +--v--+    |          |   
//        |       +--->| cog |<-- +          |   
//        |            +-----+               |   
//        |                                  |   
//        |                                  |   
//        +----------------------------------+   
//     
//     1) queue <==  "hit"
//     2) queue <==  "dit", "hot", "hig"
//     3) queue <==  "dot", "lot", "dig"
//     4) queue <==  "dog", "log" 
// 
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        
        // Using a map for two purposes: 
        //   1) store the distince so far.
        //   2) remove the duplication 
        map<string, int> dis;
        dis[start] = 1;
        
        queue<string> q;
        q.push(start);
        
        while(!q.empty()){

            string word = q.front(); 
            q.pop();
            
            if (word == end) {
                break;
            }
            
            for (int i=0; i<word.size(); i++){
                string temp = word;
                for(char c='a'; c<='z'; c++){
                    temp[i] = c;
                    if (dict.count(temp)>0 && dis.count(temp)==0){
                        dis[temp] = dis[word] + 1;
                        q.push(temp);
                    }
                }
            }
        }
        return (dis.count(end)==0) ? 0 : dis[end];
        
    }
};
