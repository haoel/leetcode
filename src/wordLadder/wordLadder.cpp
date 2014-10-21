// Source : https://oj.leetcode.com/problems/word-ladder/
// Author : Hao Chen
// Date   : 2014-10-12

/********************************************************************************** 
* 
* Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:
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

class Solution {
public:
    //BFS non-recursive method
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        
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
