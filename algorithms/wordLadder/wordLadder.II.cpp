// Source : https://oj.leetcode.com/problems/word-ladder-ii/
// Author : Hao Chen
// Date   : 2014-10-13

/********************************************************************************** 
* 
* Given two words (start and end), and a dictionary, find all shortest transformation 
* sequence(s) from start to end, such that:
* 
* Only one letter can be changed at a time
* Each intermediate word must exist in the dictionary
* 
* For example,
* 
* Given:
* start = "hit"
* end = "cog"
* dict = ["hot","dot","dog","lot","log"]
* 
* Return
* 
*   [
*     ["hit","hot","dot","dog","cog"],
*     ["hit","hot","lot","log","cog"]
*   ]
* 
* Note:
* 
* All words have the same length.
* All words contain only lowercase alphabetic characters.
* 
*               
**********************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_set>
using namespace std;

// Solution
//
//      1) Using BSF algorithm build a tree like below
//      2) Using DSF to parse the tree to the transformation path.
//
// For example:
//
//     start = "hit"
//     end = "cog"
//     dict = ["hot","dot","dog","lot","log","dit","hig", "dig"]
//
//                      +-----+
//        +-------------+ hit +--------------+
//        |             +--+--+              |
//        |                |                 |
//     +--v--+          +--v--+           +--v--+
//     | dit |    +-----+ hot +---+       | hig |
//     +--+--+    |     +-----+   |       +--+--+
//        |       |               |          |
//        |    +--v--+         +--v--+    +--v--+
//        +----> dot |         | lot |    | dig |
//             +--+--+         +--+--+    +--+--+
//                |               |          |
//             +--v--+         +--v--+       |
//        +----> dog |         | log |       |
//        |    +--+--+         +--+--+       |
//        |       |               |          |
//        |       |    +--v--+    |          |
//        |       +--->| cog |<-- +          |
//        |            +-----+               |
//        |                                  |
//        |                                  |
//        +----------------------------------+

map< string, unordered_set<string> >& 
buildTree(string& start, string& end, unordered_set<string> &dict) {

    static map< string, unordered_set<string> > parents;
    parents.clear();

    unordered_set<string> level[3];
    unordered_set<string> *previousLevel = &level[0];
    unordered_set<string> *currentLevel = &level[1];
    unordered_set<string> *newLevel = &level[2];
    unordered_set<string> *p =NULL;
    currentLevel->insert(start);

    bool reachEnd = false;

    while( !reachEnd ) {
        newLevel->clear();
        for(auto it=currentLevel->begin(); it!=currentLevel->end(); it++) {    
            for (int i=0; i<it->size(); i++) {
                string newWord = *it;
                for(char c='a'; c<='z'; c++){
                    newWord[i] = c;
                    if (newWord == end){
                        reachEnd = true;
                        parents[*it].insert(end);
                        continue;
                    }
                    if ( dict.count(newWord)==0 || currentLevel->count(newWord)>0 || previousLevel->count(newWord)>0 ) {
                        continue;
                    }
                    newLevel->insert(newWord);
                    //parents[newWord].insert(*it);
                    parents[*it].insert(newWord);
                }
            }
        } 
        if (newLevel->empty()) break;

        p = previousLevel; 
        previousLevel = currentLevel;
        currentLevel = newLevel;
        newLevel = p;
    }


    if ( !reachEnd ) {
        parents.clear();
    } 
    return parents;
}

void generatePath( string start, string end,
        map< string, unordered_set<string> > &parents, 
        vector<string> path,
        vector< vector<string> > &paths) {

    if (parents.find(start) == parents.end()){
        if (start == end){
            paths.push_back(path);
        }
        return;
    }

    for(auto it=parents[start].begin(); it!=parents[start].end(); it++){
        path.push_back(*it);
        generatePath(*it, end, parents, path, paths);
        path.pop_back();
    }

}

vector< vector<string> > 
findLadders(string start, string end, unordered_set<string> &dict) {

    vector< vector<string> > ladders;
    vector<string> ladder;
    ladder.push_back(start);
    if (start == end){
        ladder.push_back(end);
        ladders.push_back(ladder);
        return ladders;
    }

    map< string, unordered_set<string> >& parents = buildTree(start, end, dict);

    if  (parents.size()<=0) {
        return ladders;
    }

    generatePath(start, end, parents, ladder, ladders);

    return ladders;
}

void printLadders(vector< vector<string> > &ladders){
    int i, j;
    for (i=0; i<ladders.size(); i++){
        for (j=0; j<ladders[i].size()-1; j++){
            cout << ladders[i][j] << " -> ";
        }
        cout << ladders[i][j] << endl; 
    }
}

int main(int argc, char** argv)
{
    string start = "hit";
    string end = "cog";
    //unordered_set<string> dict ({"hot","dot","dog","lot","log"});
    unordered_set<string> dict ({"bot","cig", "cog", "dit", "dut", "hot", "hit" ,"dot","dog","lot","log"});

    vector< vector<string> > ladders;
    ladders = findLadders(start, end, dict);
    printLadders(ladders);
    return 0;
}
