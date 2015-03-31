// Source : https://oj.leetcode.com/problems/repeated-dna-sequences/
// Author : Hao Chen
// Date   : 2015-02-09

/********************************************************************************** 
 * 
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, 
 *
 * For example: "ACGAATTCCG". 
 * When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
 * 
 * Write a function to find all the 10-letter-long sequences (substrings) that 
 * occur more than once in a DNA molecule.
 * 
 * For example,
 * 
 * Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
 * 
 * Return:
 * ["AAAAACCCCC", "CCCCCAAAAA"].
 * 
 *               
 **********************************************************************************/
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <unordered_map>
using namespace std;

const int MAX_LEN = 10;

int ACGT2Int(char ch){
    switch(ch){
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;
    }
    return -1;
}
int DNASeqs2Int(string &s, int begin){
    int result=0;
    for(int i=0; i<MAX_LEN; i++){
        result = result*4 + ACGT2Int(s[i+begin]);
    }
    return result;
}

vector<string> findRepeatedDnaSequences_01(string s) {
    unordered_map<int, int> stat;

    vector<string> result;

    for( int i=0; i+MAX_LEN<=s.size(); i++ ){

        int hash_code = DNASeqs2Int(s, i);
        stat[hash_code]++;
        if (stat[hash_code]==2){
            result.push_back(s.substr(i, MAX_LEN));
        }
    }

    return result;        
}

vector<string> findRepeatedDnaSequences_02(string s) {
    unordered_map<size_t, int> stat;
    hash<string> hash_func;

    vector<string> result;

    for( int i=0; i+MAX_LEN<=s.size(); i++ ){
        string word = s.substr(i, MAX_LEN);
        size_t hash_code = hash_func(word);
        stat[hash_code]++;
        if (stat[hash_code]==2){
            result.push_back(word);
        }
    }

    return result;
}

vector<string> findRepeatedDnaSequences(string s) {
    srand(time(0));
    if (random()%2){
        return findRepeatedDnaSequences_01(s);
    }
    return findRepeatedDnaSequences_02(s);
}

void printVector( vector<string> v ) {
    cout << "[ " ;
    for(int i=0; i<v.size(); i++ ){
        cout << v[i] << (i<v.size()-1 ? ", " : "");
    }
    cout << " ]" << endl;
}

int main(int argc, char** argv)
{
    string s =  "GAGAGAGAGAGAG" ;
    if (argc > 1){
        s = argv[1];
    }
    printVector(findRepeatedDnaSequences(s));
}
