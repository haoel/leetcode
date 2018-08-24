// Source : https://oj.leetcode.com/problems/search-in-rotated-sorted-array/
// Author : Hong Qiu
// Date   : 2018-08-24

/********************************************************************************** 
* 
* Suppose a sorted array is rotated at some pivot unknown to you beforehand.
* 
* (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
* 
* You are given a target value to search. If found in the array return its index, otherwise return -1.
* 
* You may assume no duplicate exists in the array.
*               
**********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
        static int searchRotated(vector<int> numArray, int target){
            //Array is split into two parts by the midpoint, it is alway true that 
	    //at least one side is in order, i.e. either LeftHandSide(LHS) is
	    //unrotated or RHS is unrotated. Start to search in un-rotated side.
	    //if not found, go to the other side to continue on.
            int l = 0, m, h = numArray.size() - 1;	
            while (l < h){
                m = (l+h)/2;
                if (  numArray[l] <= numArray[m] ){ //LHS of midpoint not rotated
		    if ( numArray[l] <= target && target <= numArray[m]){
		        h = m;
                    } 
                    else{
                        l=m+1;
	            }

	        }
		else if ( numArray[m] < numArray[h] ){//RHS of midpoint not rotated{
		    if ( numArray[m] < target && target <= numArray[h]){
		        l = m + 1;
	            }
         	    else{
		        h=m;
                    }
	            cout << l << ':' << h << endl;
               }
	   }
	   if (numArray[h] == target) {return h; } else { return -1;}
        }
};
int main (){
	Solution s;
	cout << s.searchRotated({4,5,6,7,0,1,2,3}, 4) << endl <<"----"<<endl;
	cout << s.searchRotated({4,5,6,7,0,1,2,3}, 5) << endl <<"----"<<endl;
	cout << s.searchRotated({4,5,6,7,0,1,2,3}, 6) << endl <<"----"<<endl;
	cout << s.searchRotated({4,5,6,7,0,1,2,3}, 7) << endl <<"----"<<endl;
	cout << s.searchRotated({4,5,6,7,0,1,2,3}, 0) << endl <<"----"<<endl;
	cout << s.searchRotated({4,5,6,7,0,1,2,3}, 1) << endl <<"----"<<endl;
	cout << s.searchRotated({4,5,6,7,0,1,2,3}, 2) << endl <<"----"<<endl;
	cout << s.searchRotated({4,5,6,7,0,1,2,3}, 3) << endl <<"----"<<endl;
        vector<int> inputes[] = {
            {1},
            {1},
            {6,8,9,1,3,5},
            {1,2},
            {2,1},
            {4,5,6,7,0,1,2},
            {0,1,2,4,5,6,7},
        };
        int targets[] = {0,1,5,2,2,6,6};
        int results[] = {-1,0,5,1,0,2,5};

        for (int i = 0; i < 7; i++) {
       
	cout << ((s.searchRotated(inputes[i], targets[i]) == results[i])?"passed":"failed") << endl <<"----"<<endl;
        }
}

