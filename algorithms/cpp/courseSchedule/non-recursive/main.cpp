//
//  main.cpp
//  LeeteCodeOJ#207
//
//  Created by Wang Yi on 28/11/16.
//  Copyright (c) 2016 Wang Yi. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>

#include "course_schedule.cpp"

using std::make_pair;

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sl;
    int numCourses = 4;
    vector<Val> prerequisites;
    prerequisites.push_back(make_pair<int, int>(0,1));
    prerequisites.push_back(make_pair<int, int>(3,1));
    prerequisites.push_back(make_pair<int, int>(1,3));
    prerequisites.push_back(make_pair<int, int>(3,2));

    
    std::cout << sl.canFinish(numCourses, prerequisites);
    return 0;
}
