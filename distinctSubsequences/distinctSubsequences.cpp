// Source : https://oj.leetcode.com/problems/distinct-subsequences/
// Author : Hao Chen
// Date   : 2014-07-06

#include <string.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;


//Dynamic Programming
int numDistinct(string S, string T) {

    map< char, vector<int> > pos_map;
    int len = T.size();
    int *numOfSubSeq = new int[len+1];
    memset(numOfSubSeq, 0, sizeof(int) * (len+1) );
    numOfSubSeq[0] = 1;

    for (int i=len-1; i>=0; i--){
        pos_map[T[i]].push_back(i);
    }
   
    
    for (int i=0; i<S.size(); i++){
        char ch = S[i];
        if ( pos_map.find(ch) != pos_map.end() ) {
            for (int j=0; j<pos_map[ch].size(); j++) {
                int pos = pos_map[ch][j];
                numOfSubSeq[pos+1] += numOfSubSeq[pos];
            } 
        }
    }

    int result = numOfSubSeq[len];
    delete[] numOfSubSeq; 
    return result;
}

int main(int argc, char** argv)
{
    string s = "rabbbit";
    string t = "rabbit";
    if (argc>2){
        s = argv[1];
        t = argv[2];
    }
    cout << "S=\"" << s << "\"  T=\"" << t << "\"" << endl;
    cout << "numDistinct = " << numDistinct(s, t) << endl;
    return 0;
}
