// Source : https://leetcode.com/problems/fizz-buzz/
// Author : Hao Chen
// Date   : 2016-11-13

/*************************************************************************************** 
 *
 * Write a program that outputs the string representation of numbers from 1 to n.
 * 
 * But for multiples of three it should output “Fizz” instead of the number and for the 
 * multiples of five output “Buzz”. For numbers which are multiples of both three and 
 * five output “FizzBuzz”.
 * 
 * Example:
 * 
 * n = 15,
 * 
 * Return:
 * [
 *     "1",
 *     "2",
 *     "Fizz",
 *     "4",
 *     "Buzz",
 *     "Fizz",
 *     "7",
 *     "8",
 *     "Fizz",
 *     "Buzz",
 *     "11",
 *     "Fizz",
 *     "13",
 *     "14",
 *     "FizzBuzz"
 * ]
 ***************************************************************************************/

class Solution {
public:
    vector<string> fizzBuzz_old_school_way(int n) {
        vector<string> result;
        for (int i=1; i<=n; i++) {
            if ( i%3 == 0 && i%5 ==0 ) {
                result.push_back("FizzBuzz");
            }else if (i%3 == 0) {
                result.push_back("Fizz");
            }else if (i%5 == 0) {
                result.push_back("Buzz");
            }else{
                result.push_back(std::to_string(i));
            }
        }
        return result;
    }
    
    
    class FizzBuzz {
        public:
            FizzBuzz() : x(0) {}
            
            string operator()() {
                x++; 
                if ( x%3 == 0 && x%5 ==0 ) {
                    return ("FizzBuzz");
                }else if (x%3 == 0) {
                    return ("Fizz");
                }else if (x%5 == 0) {
                    return("Buzz");
                }
                return std::to_string(x);
            }
            
        private:
            int x;
    };
    
    vector<string> fizzBuzz_cpp_way(int n) {
        vector<string> result(n);
        generate(result.begin(), result.end(), FizzBuzz());
        return result;
    }
    
    vector<string> fizzBuzz(int n) {
        
        //both method has same performance
        
        if (rand() % 2 == 0) {
            return fizzBuzz_cpp_way(n); 
        }
        return fizzBuzz_old_school_way(n);   
    }
};
