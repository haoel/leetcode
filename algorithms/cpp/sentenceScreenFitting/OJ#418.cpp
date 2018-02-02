//
//  OJ#418.cpp
//  LeeteCodeOJ#418
//
//  Created by Wang Yi on 25/10/16.
//  Copyright (c) 2016 Wang Yi. All rights reserved.
//

#include "OJ#418.h"
#include <string.h>
#include <iomanip>
#include <iostream>
#define FOR(START, END) for((START)=0;(START)<(END);(START)+=1) {
#define END ;}
#define N 100

// first brute force solution
int SentenceScreenFitting(char stc[][M], int row, int col, size_t l)
{
    int i, j, t, s, k=0, ret=0;
    int len[N] = {0};
    FOR(i, l) len[i] = (int)strlen(stc[i]) END
    
    FOR(i, row)
    j = col;
    t = k;
    while (j - len[k] >= 0) {
        j -= len[k] + 1;
        if (k+1 > l-1){
            FOR(s, k-t) std::cout << stc[t+s] << ' ' END;
            std::cout << stc[t+s];
            if (j - len[0] >= 0)
                std::cout << ' ';
            k = 0;
            t = 0;
            ret++;
        } else{
            k++;
        }
    }
    FOR(s, k-t-1) std::cout << stc[t+s] << ' ' END;
    if (k-t > 0)
        std::cout << stc[t+s];

    std::cout << std::setfill ('-') << std::setw(j == col ? col:j+1) << "" << std::endl;
    END
    
    return ret;
}

/*
int Solution::wordsTyping(vector<string>& sentence, int rows, int cols)
{
    int i, j, t, s, k=0, ret=0, l=(int)sentence.size();
    int len[N] = {0};
    FOR(i, l) len[i] = (int)sentence[i].size() END
    
    FOR(i, rows)
    j = cols;
    t = k;
    while (j - len[k] >= 0) {
        j -= len[k] + 1;
        if (k+1 > l-1){
//            FOR(s, k-t) std::cout << sentence[t+s] << ' ' END;
//            std::cout << sentence[t+s];
//            if (j - len[0] >= 0)
//                std::cout << ' ';
            k = 0;
            t = 0;
            ret++;
        } else{
            k++;
        }
    }
//    FOR(s, k-t-1) std::cout << sentence[t+s] << ' ' END;
//    if (k-t > 0)
//        std::cout << sentence[t+s];
//    
//    std::cout << std::setfill ('-') << std::setw(j == cols ? cols:j+1) << "" << std::endl;
    END
    
    return ret;
}
*/

// second boosting
int Solution::wordsTyping(vector<string>& sentence, int rows, int cols)
{
    int i, j, k=0, ret=0, l=(int)sentence.size();
//    int t, s;
    int jump = 0;
    int len[N] = {0};
    FOR(i, l) len[i] = (int)sentence[i].size();jump += len[i] END
    jump += l;
    
    FOR(i, rows)
    j = cols;
//    t = k;
    
    if (k == 0){
        ret += j / jump;
        j = j % jump;
    }
    
    while (j - len[k] >= 0) {
        j -= len[k] + 1;
        if (k+1 > l-1){
            //            FOR(s, k-t) std::cout << sentence[t+s] << ' ' END;
            //            std::cout << sentence[t+s];
            //            if (j - len[0] >= 0)
            //                std::cout << ' ';
            k = 0;
//            t = 0;
            ret += j / jump + 1;
            j = j % jump;
        } else {
            k++;
        }
    }
    //    FOR(s, k-t-1) std::cout << sentence[t+s] << ' ' END;
    //    if (k-t > 0)
    //        std::cout << sentence[t+s];
    //
    //    std::cout << std::setfill ('-') << std::setw(j == cols ? cols:j+1) << "" << std::endl;
    END
    
    return ret;
}