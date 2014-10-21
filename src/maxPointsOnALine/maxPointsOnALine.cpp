// Source : https://oj.leetcode.com/problems/max-points-on-a-line/
// Author : Hao Chen
// Date   : 2014-10-12

/********************************************************************************** 
* 
* Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*               
**********************************************************************************/

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

// O^2 solution
int maxPoints(vector<Point> &points) {

    #define INT_MAX 2147483647
    #define INT_MIN -2147483648

    if (points.size()<=0) return 0;
    if (points.size()<=2) return points.size();
    
    int maxnum = 0;
    map<double, int> slopeMap;
    for(int i=0; i<points.size(); i++) {
        slopeMap.clear();
        slopeMap[INT_MIN] = 0;
        int samePointCnt = 1;
        for (int j=0; j<points.size(); j++) {
            if (i==j) continue;
            int delta_x = points[i].x - points[j].x;
            int delta_y = points[i].y - points[j].y;
            if (delta_y == 0 && delta_x == 0){
                samePointCnt++;
                continue;
            }
            double slope = INT_MAX;
            if (delta_x!=0) {
                slope = 1.0*delta_y / delta_x;
            }
            slopeMap[slope]++;
        }
        map<double, int>::iterator it;
        for (it = slopeMap.begin(); it != slopeMap.end(); it++) {
            if (maxnum < it->second + samePointCnt) {
                maxnum = it->second + samePointCnt;
            }
        }
    }

    return maxnum;
}

void generatePoints(vector<Point> &points, int n) {
    srand(time(0));
    Point p;
    for(int i=0; i<n; i++) {
        p.x = rand() % 1;
        p.y = rand() % 1;
        points.push_back(p);
    }
}

void printPoints(vector<Point> &points) {
    for(int i=0; i<points.size(); i++) {
        cout << "(" << points[i].x << "," << points[i].y << ") ";
    }
    cout << endl;
}


int main(int argc, char** argv) 
{
    int n = 20;
    if ( argc > 1) {
        n = atoi(argv[1]);
    }
    vector<Point> points;
    generatePoints(points, n);
    printPoints(points);
    cout << maxPoints(points) << endl;
    return 0;
}
