//
//  OJ#418.cpp
//  LeeteCodeOJ#418
//
//  Created by Wang Yi on 25/10/16.
//  Copyright (c) 2016 Wang Yi. All rights reserved.
//


/**********************************************************************************
 *  
 *  Given a rows x cols screen and a sentence represented by a list of words, find 
 *  how many times the given sentence can be fitted on the screen.
 *  
 *  Note:
 *  
 *      A word cannot be split into two lines.
 *      The order of words in the sentence must remain unchanged.
 *      Two consecutive words in a line must be separated by a single space.
 *      Total words in the sentence won't exceed 100.
 *      Length of each word won't exceed 10.
 *      1 ≤ rows, cols ≤ 20,000.
 *  
 *   
 *  
 *  Example 1:
 *  
 *  Input:
 *  rows = 2, cols = 8, sentence = ["hello", "world"]
 *  
 *  Output: 
 *  1
 *  
 *  Explanation:
 *  hello---
 *  world---
 *  
 *  The character '-' signifies an empty space on the screen.
 *  
 *   
 *  
 *  Example 2:
 *  
 *  Input:
 *  rows = 3, cols = 6, sentence = ["a", "bcd", "e"]
 *  
 *  Output: 
 *  2
 *  
 *  Explanation:
 *  a-bcd- 
 *  e-a---
 *  bcd-e-
 *  
 *  The character '-' signifies an empty space on the screen.
 *  
 *   
 *  
 *  Example 3:
 *  
 *  Input:
 *  rows = 4, cols = 5, sentence = ["I", "had", "apple", "pie"]
 *  
 *  Output: 
 *  1
 *  
 *  Explanation:
 *  I-had
 *  apple
 *  pie-I
 *  had--
 *  
 *  The character '-' signifies an empty space on the screen.
 *  
 *  *********************************************************************************/


#include "sentenceScreenFitting.h"
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
