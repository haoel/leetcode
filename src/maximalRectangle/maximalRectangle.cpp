// Source : https://oj.leetcode.com/problems/maximal-rectangle/
// Author : Hao Chen
// Date   : 2014-07-21

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;

int largestRectangleArea(vector<int> &height) {

    if (height.size()<=0) return 0;

    height.push_back(0);
    vector<int> stack;
    int maxArea=0;

    for(int i=0; i<height.size(); ){
        if (stack.size()==0 || height[i] >= height[ stack.back() ] ){
            stack.push_back(i);
            i++;
        }else{
            int topIdx = stack.back();
            stack.pop_back();
            int area = height[topIdx] * ( stack.size()==0 ? i  : i - stack.back() - 1 );
            if (area > maxArea){
                maxArea = area;
            }
        }
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char> > &matrix) {

    if (matrix.size()<=0 || matrix[0].size()<=0) return 0;
    int row = matrix.size();
    int col = matrix[0].size();
    vector< vector<int> > heights(row);
    for (int i=0; i<row; i++){
        vector<int> v(col);
        heights[i] = v;
    }

    int maxArea = 0;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++) {
            if (matrix[i][j]=='1'){
                heights[i][j] = (i==0 ? 1 : heights[i-1][j] + 1);
            }
        }
        int area = largestRectangleArea(heights[i]);
        if (area > maxArea){
            maxArea = area;
        }
    }

    return maxArea;

}

void printArray(vector<int> &v)
{
    cout << "{";
    for(int i=0; i<v.size(); i++) {
        cout << " " << v[i];
    }
    cout << "}" << endl;
}

void test(int a[], int n)
{
    vector<int> v(a, a + n);
    printArray(v);
    cout << largestRectangleArea(v) << endl;
}

int main(int argc, char** argv)
{
    #define TEST(a) test(a, sizeof(a)/sizeof(int))

    int a0[] = {2,1,3,1};
    TEST(a0);
    int a1[] = {2,1,5,6,2,3};
    TEST(a1);



    cout << "------------------" << endl; 
    srand(time(0));

    int r = 3;
    int c = 3;
    if (argc>2){
        r = atoi(argv[1]);
        c = atoi(argv[2]);
    }

    vector< vector<char> > matrix;
    for(int i=0; i<r; i++){
        vector<char> v;
        cout << "[";
        for(int j=0; j<c; j++) {
            char ch = random()%2+'0';
            v.push_back(ch);
            cout << " " << ch;
        }
        matrix.push_back(v);
        cout << " ]" << endl;
    }
    cout << "------------------" << endl; 
    cout << "maxArea = " << maximalRectangle(matrix) << endl;

    return 0;
}



