// Source : https://leetcode.com/problems/queue-reconstruction-by-height/
// Author : Hao Chen
// Date   : 2016-11-12

/*************************************************************************************** 
 *
 * Suppose you have a random list of people standing in a queue. Each person is 
 * described by a pair of integers (h, k), where h is the height of the person and k is 
 * the number of people in front of this person who have a height greater than or equal 
 * to h. Write an algorithm to reconstruct the queue.
 * 
 * Note:
 * The number of people is less than 1,100.
 * 
 * Example
 * 
 * Input:
 * [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 * 
 * Output:
 * [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 ***************************************************************************************/

class Solution {

public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        //sort function
        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2)
                    { return p1.first == p2.first ? p1.second < p2.second : p1.first > p2.first; };
        //sort the people with their height with descending order
        // and if the height is same then sort by K with ascending order
        sort(people.begin(), people.end(), comp);
        
        // For example:
        // Original Queue:  [7,0], [4,4], [7,1], [5,0], [6,1], [5,2]
        //   Sorted Queue:  [7,0], [7,1], [6,1], [5,0], [5,2], [4,4] 
        
        
        // Why do we need to sort like this?
        //
        //     ** The position of shorter people is ZERO impacted with higher people. **
        //    
        // and, the shortest people has no impacts to all of people. we can simpley insert it to the Kth position
        //
        // So, we sorted the people from highest to the shortest, then when we insert the people to another array,
        //
        // we always can guarantee the people is going to be inserted has nothing to do with the people has been inserted.
        //   
        // Let's continue the about example above
        //
        //    [7,0] => []                                then [7,0]
        //    [7,1] => [7,0]                             then [7,0], [7,1]
        //    [6,1] => [7,0], [7,1]                      then [7,0], [6,1], [7,1]
        //    [5,0] => [7,0], [6,1], [7,1]               then [5,0], [7,0], [6,1], [7,1]
        //    [5,2] => [5,0], [7,0], [6,1], [7,1]        then [5,0], [7,0], [5,2], [6,1], [7,1]
        //    [4,4] => [5,0], [7,0], [5,2], [6,1], [7,1] then [5,0], [7,0], [5,2], [6,1], [4,4], [7,1]
        //
        // We alway can see, the people is going to be inserted has NO IMPACT with the current people.
        //     
        //    [6,1] => [7,0], [7,1]  
        // 
        //    Whatever the people[6,1] placed, it has nothing to do with the people [7,0] [7,1],
        //    So, we can just insert the people to the place he like - the `Kth` place. 
        //
        //
        vector<pair<int, int>> res;
        for (auto& p : people) {
            res.insert(res.begin() + p.second, p);
        }
        return res;
    }
};
