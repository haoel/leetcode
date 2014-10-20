// Source : https://oj.leetcode.com/problems/word-ladder/
// Author : Hao Chen
// Date   : 2014-10-12

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
