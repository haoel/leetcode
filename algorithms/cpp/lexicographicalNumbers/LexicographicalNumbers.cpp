// Source : https://leetcode.com/problems/lexicographical-numbers/
// Author : Hao Chen
// Date   : 2016-08-23

/*************************************************************************************** 
 *
 * Given an integer n, return 1 - n in lexicographical order.
 * 
 * For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
 * 
 * Please optimize your algorithm to use less time and space. The input size may be as 
 * large as 5,000,000.
 ***************************************************************************************/
class Solution {
    
//Solution 1: convert the int to string for sort, Time complexity is high (Time Limited Error)
public:
    vector<int> lexicalOrder01(int n) {
        vector<int> result;
        for (int i=1; i<=n; i++) {
            result.push_back(i);
        }
        sort(result.begin(), result.end(), this->myComp);
        return result;
    }
private:
    static bool myComp(int i,int j) { 
        static char si[32]={0}, sj[32]={0};
        sprintf(si, "%d\0", i);
        sprintf(sj, "%d\0", j);
        return (strcmp(si, sj)<0); 
    }
    
    
//Solution 2 : using recursive way to solution the problem, 540ms
public:
    vector<int> lexicalOrder02(int n) {
        vector<int> result;
        for (int i=1; i<=n && i<=9; i++) {
            result.push_back(i);
            lexicalOrder_helper(i, n, result);
        }
        return result;
    }
    
private:
    void lexicalOrder_helper(int num, int& n, vector<int>& result) {
        for (int i=0; i<=9; i++) {
            int tmp = num * 10 + i;
            if (tmp > n) {
                break;
            }
            result.push_back(tmp);
            lexicalOrder_helper(tmp, n, result);
        }
    }

//Solution 3: no recursive way, but the code is not easy to read
public :
    vector<int> lexicalOrder03(int n) {
        vector<int> result;
        int curr = 1;
        while (result.size()<n) {
            // Step One
            // ---------
            //Adding all of the possible number which multiply 10 as much as possible 
            // such as: curr = 1, then 1, 10, 100, 1000 ...
            //          curr = 12, then 12, 120, 1200, ...
            for (; curr <= n; curr*=10 ) {
                result.push_back(curr);
            }
            
            // Step Two
            // ---------
            // After find the number which multiply 10 greater than `n`, then go back the previous one,
            // and keep adding 1 until it carry on to next number
            // for example:
            //    curr = 100, then we need evalute:  11,12,13,14,15,16,17,18,19, but stop at 20
            //    curr = 230, then we need evaluate: 24,25,26,27,28,29, but stop at 30.
            curr = curr/10 + 1;
            for (;  curr <= n &&  curr % 10 != 0; curr++) {
                result.push_back(curr);
            }

            // Step Three
            // ----------
            // Now, we finished all of the number, we need go back for next number
            // Here is a bit tricky.
            // 
            // Assuming the n is 234, and Step One evaluted 190, and Step Two, evaluted 191,192,...,199
            // Now, the `curr` is 200, and we need start from 2 instead of 20, that's why need keep dividing 10
            for (; curr%10 == 0; curr/=10);
           
        }
        return result;
    }
    
    
//start point
public:
    vector<int> lexicalOrder(int n) {
        srand(time(NULL));
        if (rand()%2) 
            return lexicalOrder02(n); // recursive way  560ms
        else 
            return lexicalOrder03(n); // non-recursive way, 460ms
    }

};
