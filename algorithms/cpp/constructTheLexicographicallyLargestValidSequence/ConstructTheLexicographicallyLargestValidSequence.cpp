// Source : https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/
// Author : Hao Chen
// Date   : 2021-04-24

/***************************************************************************************************** 
 *
 * Given an integer n, find a sequence that satisfies all of the following:
 * 
 * 	The integer 1 occurs once in the sequence.
 * 	Each integer between 2 and n occurs twice in the sequence.
 * 	For every integer i between 2 and n, the distance between the two occurrences of i is 
 * exactly i.
 * 
 * The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of 
 * their indices, |j - i|.
 * 
 * Return the lexicographically largest sequence. It is guaranteed that under the given constraints, 
 * there is always a solution. 
 * 
 * A sequence a is lexicographically larger than a sequence b (of the same length) if in the first 
 * position where a and b differ, sequence a has a number greater than the corresponding number in b. 
 * For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first position they 
 * differ is at the third number, and 9 is greater than 5.
 * 
 * Example 1:
 * 
 * Input: n = 3
 * Output: [3,1,2,3,2]
 * Explanation: [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the lexicographically largest 
 * valid sequence.
 * 
 * Example 2:
 * 
 * Input: n = 5
 * Output: [5,3,1,4,3,5,2,4,2]
 * 
 * Constraints:
 * 
 * 	1 <= n <= 20
 ******************************************************************************************************/

class Solution {
private:
    void print(vector<int>& v) {
        cout << "[" ;
        for(int i=0; i<v.size()-1; i++){
            cout << v[i] << ",";
        }
        cout << v[v.size()-1] << "]" << endl;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2*n-1, 0);
        vector<bool> available(n+1, true); // an array remember which num hasn't been chosen.
        available[0] = false;
        
        dfs(available, result, 0, n);
        
        return result;
    }
    
    bool dfs(vector<bool>& available, vector<int>& result, int pos, int cnt){
        //the `cnt` means how many number has been processed.
        if (cnt == 0) return true;
        
        //start from the bigger number.
        int n = 0;
        for(int i = available.size()-1; i > 0; i--){
            // if the number has already been chosen, skip to next one.
            if (!available[i]) continue;
            //if the number cannot be put into the array, skip to next one
            if ( i > 1 && pos + i >= result.size()) continue;
            if ( i > 1 && (result[pos] != 0 || result[pos+i] != 0)) continue;
            
            // choose the current number `i`
            available[i] = false;
            result[pos] = i;
            if (i > 1) result[pos+i] = i;
            int next_pos = pos;
            while( next_pos < result.size() && result[next_pos]!=0) next_pos++;
            
            //print(result);
            if (dfs(available, result, next_pos, cnt-1)) return true; 
            
            // if failed to find the answer. roll back.
            available[i] = true;
            result[pos] = 0;
            if (i > 1) result[pos+i] = 0;
        }
        
        return false;
    }
};
