// Source : https://oj.leetcode.com/problems/longest-consecutive-sequence/
// Author : Hao Chen
// Date   : 2014-06-22

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        
        map<int, int> m;
        for (int i=0; i<num.size(); i++){
            m[num[i]]=i;
        }
        
        int max_seq=0; 
        for (int i=0; i<num.size(); i++){
            int cnt=1;
            
            for(int n = num[i]+1;m.find(n)!=m.end();n++){
                m.erase(m.find(n));
                cnt++;
                
            }
            for(int n = num[i]-1;m.find(n)!=m.end();n--){
                m.erase(m.find(n));
                cnt++;
            }
            if (max_seq < cnt){
                max_seq = cnt;
            }
            if (m.size()==0){
                break;
            }
        }
        return max_seq;
    }
};
