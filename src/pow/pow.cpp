// Source : https://oj.leetcode.com/problems/powx-n/
// Author : Hao Chen
// Date   : 2014-06-25

#include <stdio.h>
#include <stdlib.h>

double pow(double x, int n) {

    bool sign = false;
    unsigned int exp = n;
    if(n<0){
        exp = -n;
        sign = true;
    }
    double result = 1.0;
    while (exp) {
        if (exp & 1){
            result *= x;
        }
        exp >>= 1;
        x *= x;
    }

    return sign ? 1/result : result;

}

int main(int argc, char** argv){
    double x=2.0;
    int n = 3;
    if (argc==3){
        x = atof(argv[1]);
        n = atoi(argv[2]);
    }
    printf("%f\n", pow(x, n));
    return 0;
}
