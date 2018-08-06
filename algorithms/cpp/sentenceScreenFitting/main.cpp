//
//  main.cpp
//  LeeteCodeOJ#418
//
//  Created by Wang Yi on 25/10/16.
//  Copyright (c) 2016 Wang Yi. All rights reserved.
//

#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <vector>
#include "sentenceScreenFitting.h"
#define N 100
#define M 10

using std::vector;

int main(int argc, const char * argv[]) {
    int rows, cols, ret;
//    int i=0;
//    char stc[N][M];
    vector<string> sentence;
    std::string word;
    std::string line;
    std::stringstream numbers, split;
    
    std::getline(std::cin, line);
    numbers << line;
    numbers >> rows >> cols;
    std::getline(std::cin, line);
    split << line;

    while (split >> word){
        sentence.push_back(word);
//        strcpy(stc[i++], word.c_str());
    }
    
    Solution solution;
    ret = solution.wordsTyping(sentence, rows, cols);
//    ret = SentenceScreenFitting(stc, rows, cols, i);
    std::cout << ret << std::endl;
    return 0;
}
