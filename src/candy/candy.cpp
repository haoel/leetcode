// Source : https://oj.leetcode.com/problems/candy/
// Author : Hao Chen
// Date   : 2014-10-12

/********************************************************************************** 
* 
* There are N children standing in a line. Each child is assigned a rating value. 
* 
* You are giving candies to these children subjected to the following requirements:
* 
* Each child must have at least one candy.
* Children with a higher rating get more candies than their neighbors.
* 
* What is the minimum candies you must give?
* 
*               
**********************************************************************************/

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;


void print(vector<int> &v);

int candy(vector<int> &ratings) {

    vector<int> candyCnt(ratings.size()) ;
    //allocate candies, considering the minimal rating on the left
    candyCnt[0] = 1;
    for(int i = 1; i < ratings.size(); i++){
        candyCnt[i] = ratings[i] > ratings[i-1] ? candyCnt[i-1]+1 : 1;
    }
    print(candyCnt); 
    //modify the allocation, considering the minimal rating on the right
    int totalCandy = candyCnt[ratings.size()-1];
    for(int i = ratings.size()-2; i >= 0; i--){
        candyCnt[i] = (ratings[i] > ratings[i+1] && candyCnt[i+1]+1 > candyCnt[i]) ? candyCnt[i+1]+1 : candyCnt[i];
        //count total candies by the way
        totalCandy += candyCnt[i];
    }
    print(candyCnt);
    return totalCandy;
}

void generateRatings(vector<int> &ratings, int n) {
    srand(time(0));
    for (int i=0; i<n; i++) {
        ratings.push_back(rand()%10);
    }
}

void print(vector<int> &v) {
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(int argc, char**argv)
{
    int n = 10;
    if (argc>1){
        n = atoi(argv[1]);
    }   
    vector<int> ratings;
    generateRatings(ratings, n);
    print(ratings);

    cout << candy(ratings) << endl;

    return 0;
}
