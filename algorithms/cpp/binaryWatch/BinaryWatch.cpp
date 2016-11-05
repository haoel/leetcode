// Source : https://leetcode.com/problems/binary-watch/
// Author : Hao Chen
// Date   : 2016-11-05

/*************************************************************************************** 
 *
 * A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 
 * LEDs on the bottom represent the minutes (0-59).
 * Each LED represents a zero or one, with the least significant bit on the right.
 * 
 * For example, the above binary watch reads "3:25".
 * 
 * Given a non-negative integer n which represents the number of LEDs that are 
 * currently on, return all possible times the watch could represent.
 * 
 * Example:
 * Input: n = 1Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", 
 * "0:16", "0:32"]
 * 
 * Note:
 * 
 * The order of output does not matter.
 * The hour must not contain a leading zero, for example "01:00" is not valid, it 
 * should be "1:00".
 * The minute must be consist of two digits and may contain a leading zero, for example 
 * "10:2" is not valid, it should be "10:02".
 ***************************************************************************************/

class Solution {
private:
    void combination(int nLED, int nLight, int max, bool zero,
                     int start, int k, int solution, 
                     vector<vector<string>>& result) {
        if (solution > max){
            return;
        }
        if (k == 0) {
            char tmp[5] = "";
            if (zero) {
                sprintf(tmp, "%02d", solution);
            }else{
                sprintf(tmp, "%d", solution);
            }
            result[nLight].push_back(tmp);
            return;
        }
        for (int i=start; i<=nLED-k; i++) {
            solution += pow(2, i);
            combination(nLED, nLight, max, zero, i+1, k-1, solution, result);
            solution -= pow(2, i);
        }
    }
    
    void generate_combination(int nLED, int max, bool zero, vector<vector<string>>& result) {
        for (int i=0; i<nLED; i++) {
            combination(nLED, i, max, zero, 0, i, 0, result);
        }
    }
    
    void print(vector<vector<string>>&  vv) {
        for(auto v : vv) {
            cout << "[ ";
            for (auto i : v) {
                cout << i << " ";
            }
            cout << "]" << endl;
        }
    }
    
private:
    vector<vector<string>> hour;
    vector<vector<string>> mins;

public:

    Solution():hour(4, vector<string>()), mins(6, vector<string>()){
        generate_combination(4, 11, false, hour);
        //print(hour);
        //[ 0 ]
        //[ 1 2 4 8 ]
        //[ 3 5 9 6 10 ]
        //[ 7 11 ]
        
        
        generate_combination(6, 59, true, mins);
        //print(mins);
        //[ 00 ]
        //[ 01 02 04 08 16 32 ]
        //[ 03 05 09 17 33 06 10 18 34 12 20 36 24 40 48 ]
        //[ 07 11 19 35 13 21 37 25 41 49 14 22 38 26 42 50 28 44 52 56 ]
        //[ 15 23 39 27 43 51 29 45 53 57 30 46 54 58 ]
        //[ 31 47 55 59 ]        
    }
    
    vector<string> readBinaryWatch(int num) {
        
        vector<string> result;
        for (int i = 0; i <= 3 && i <= num; i++) {
            if (num - i > 5) {
                continue;
            }
            for (auto h : hour[i]) {
                for (auto m : mins[num - i]) {
                    result.push_back( h + ":" + m );
                }
            }
            
        }
        return result;
    }
};
