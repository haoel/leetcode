// Source : https://leetcode.com/problems/expression-add-operators/
// Author : Hao Chen
// Date   : 2016-01-16

/*************************************************************************************** 
 *
 * Given a string that contains only digits 0-9 and a target value, return all 
 * possibilities to add binary operators (not unary) +, -, or * between the digits so 
 * they evaluate to the target value.
 * 
 * Examples: 
 * "123", 6 -> ["1+2+3", "1*2*3"] 
 * "232", 8 -> ["2*3+2", "2+3*2"]
 * "105", 5 -> ["1*0+5","10-5"]
 * "00", 0 -> ["0+0", "0-0", "0*0"]
 * "3456237490", 9191 -> []
 * 
 * Credits:Special thanks to @davidtan1890 for adding this problem and creating all 
 * test cases.
 ***************************************************************************************/


class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if (num.size() == 0) return result;
        helper(num, target, result, "", 0, 0, 0, ' ');
        return result;        
    }
    
    //DFS algorithm
    void helper(const string &num, const int target, //`num` and `target` never change
                vector<string>& result, // the array store all of the answers
                string solution, //the current potential answer.
                int idx, // the current index of `num` array
                long long val, // the current value we calculated so far
                long long prev, // the lastest value we used for calculation, which used for operation prioirty adjustment
                char preop ) // the latest "+" or "-" operation, which used for operation prioirty adjustment 
    {
        
        if (target == val && idx == num.size()){
            result.push_back(solution);
            return;
        }
        if (idx == num.size()) return;
        
        string n;
        long long v=0;
        for(int i=idx; i<num.size(); i++) {
            //get rid of the number which start by "0"
            //e.g.  "05" is not the case.
            if (n=="0") return;
            
            n = n + num[i];
            v = v*10 + num[i]-'0';
            
            if (solution.size()==0){ 
                // the first time for initialization
                helper(num, target, result, n, i+1, v, 0, ' ');
            }else{
                // '+' or '-' needn't to adjust the priority
                helper(num, target, result, solution + '+' + n, i+1, val+v, v, '+');
                helper(num, target, result, solution + '-' + n, i+1, val-v, v, '-');
                
                //if we meet multiply operation, we need adjust the calcualtion priority
                // e.g. if the previous value is calculated by 2+3=5, 
                //      then if we need to multipy 4, it is not 5*4, it is 2+3*4=2+12=24
                //      we need be careful about multiply again, such as: 2+3*4*5
                if (preop=='+') {
                    helper(num, target, result, solution + '*' + n, i+1, (val-prev)+prev*v, prev*v, preop);
                }else if (preop=='-'){
                    helper(num, target, result, solution + '*' + n, i+1, (val+prev)-prev*v, prev*v, preop);
                }else {
                    helper(num, target, result, solution + '*' + n, i+1, val*v, v, '*');
                }
            }
        }
        
    }
};
