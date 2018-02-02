//
//  main.cpp
//  Docker_Builder
//
//  Created by Wang Yi on 10/4/17.
//  Copyright © 2017 Wang Lei. All rights reserved.
//

#include <iostream>
#include <strstream>
#include <sstream>
#include <string>
using std::string;
#include <unordered_map>
using std::pair;
using std::make_pair;
#include "Tree.hpp"

#define FOR(s, e) \
for(s=0; s < e; s++) {
#define END ;}

int main(int argc, const char * argv[]) {
    int N;
    std::cout << "Input the Number of imgs dependencies: ";
    std::cin >> N;
    vector<pair<string, string>> Rel(N);
    vector<string> item(2);
    std::stringstream split, kw;
    string line;
    string temp, part;
    
    std::getline(std::cin, line);
    
    int i=0, j;
    while(i < N) {
        std::getline(std::cin, line);
        split << line;
        while (split >> temp && i < N){
            kw.str(temp);
            j = 0;
            while (std::getline(kw, part, ',') && j < 2)
            {
                item[j++] = part;
            }
            Rel.at(i++) = pair<string, string>(item[0],item[1]);
            kw.clear();
        }
    
    }
    
    shared_ptr<vector<string>> ret = DockerBuildDependency(Rel);
    
    for (auto item : *ret)
    {
        std::cout << item << ' ';
    }
    std::cout << std::endl;
    
    return 0;
}