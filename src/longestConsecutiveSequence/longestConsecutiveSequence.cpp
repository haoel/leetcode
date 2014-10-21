// Source : https://oj.leetcode.com/problems/longest-consecutive-sequence/
// Author : Hao Chen
// Date   : 2014-06-22

/********************************************************************************** 
* 
* Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
* 
* For example,
* Given [100, 4, 200, 1, 3, 2],
* The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
* 
* Your algorithm should run in O(n) complexity.
* 
*               
**********************************************************************************/

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
