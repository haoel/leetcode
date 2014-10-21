// Source : https://oj.leetcode.com/problems/sqrtx/
// Author : Hao Chen
// Date   : 2014-08-26

/********************************************************************************** 
* 
* Implement int sqrt(int x).
* 
* Compute and return the square root of x.
*               
**********************************************************************************/

#include <stdlib.h>
#include <iostream>
using namespace std;


int sqrt(int x) {

    if (x <=0 ) return 0;
    
    //the sqrt is not greater than x/2+1
    int e = x/2+1;
    int s = 0;
    // binary search
    while ( s <= e ) {
        int mid = s + (e-s)/2;
        long long sq = (long long)mid*(long long)mid;
        if (sq == x ) return mid;
        if (sq < x) {
            s = mid + 1;
        }else {
            e = mid - 1;
        }
    }
    return e; 
        
}

// http://en.wikipedia.org/wiki/Newton%27s_method
int sqrt_nt(int x) {
    if (x == 0) return 0;
    double last = 0;
    double res = 1;
    while (res != last)
    {
        last = res;
        res = (res + x / res) / 2;
    }
    return int(res);
}


int main(int argc, char**argv)
{
    int n = 2;
    if( argc > 1 ){
        n = atoi(argv[1]);
    }
    cout << "sqrt(" << n << ") = " << sqrt(n) << endl;
    return 0;
}
