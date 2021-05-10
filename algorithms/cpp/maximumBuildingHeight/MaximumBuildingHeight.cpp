// Source : https://leetcode.com/problems/maximum-building-height/
// Author : Hao Chen
// Date   : 2021-04-25

/***************************************************************************************************** 
 *
 * You want to build n new buildings in a city. The new buildings will be built in a line and are 
 * labeled from 1 to n.
 * 
 * However, there are city restrictions on the heights of the new buildings:
 * 
 * 	The height of each building must be a non-negative integer.
 * 	The height of the first building must be 0.
 * 	The height difference between any two adjacent buildings cannot exceed 1.
 * 
 * Additionally, there are city restrictions on the maximum height of specific buildings. These 
 * restrictions are given as a 2D integer array restrictions where restrictions[i] = [idi, maxHeighti] 
 * indicates that building idi must have a height less than or equal to maxHeighti.
 * 
 * It is guaranteed that each building will appear at most once in restrictions, and building 1 will 
 * not be in restrictions.
 * 
 * Return the maximum possible height of the tallest building.
 * 
 * Example 1:
 * 
 * Input: n = 5, restrictions = [[2,1],[4,1]]
 * Output: 2
 * Explanation: The green area in the image indicates the maximum allowed height for each building.
 * We can build the buildings with heights [0,1,2,1,2], and the tallest building has a height of 2.
 * 
 * Example 2:
 * 
 * Input: n = 6, restrictions = []
 * Output: 5
 * Explanation: The green area in the image indicates the maximum allowed height for each building.
 * We can build the buildings with heights [0,1,2,3,4,5], and the tallest building has a height of 5.
 * 
 * Example 3:
 * 
 * Input: n = 10, restrictions = [[5,3],[2,5],[7,4],[10,3]]
 * Output: 5
 * Explanation: The green area in the image indicates the maximum allowed height for each building.
 * We can build the buildings with heights [0,1,2,3,3,4,4,5,4,3], and the tallest building has a 
 * height of 5.
 * 
 * Constraints:
 * 
 * 	2 <= n <= 10^9
 * 	0 <= restrictions.length <= min(n - 1, 10^5)
 * 	2 <= idi <= n
 * 	idi is unique.
 * 	0 <= maxHeighti <= 10^9
 ******************************************************************************************************/

/* 

At first , it's not difficult to work out the max height between two buildings.

**Case study**

considering the following restractions:

1) Building #1 `max-height = 1`, Building #5 `max-height = 1`
     then we can have the building height list - `[1,2,3,2,1] `

2) Building #1 `max-height = 3`, Building #5 `max-height = 1`
     then we can have the building height list - `[3,4,3,2,1]` 

3) Building #1 `max-height = 1`, Building #5 `max-height = 9`
     then we can have the building height list - `[1,2,3,4,5]`

So, we can figure out the following rules :

1) if two restraction has same limited height, suppose we have `[n .........  n]`, 
     then we can have the building height list   `[n, n+1, n+2, ... n+m-1, n+m, n+m-1 ..., n+2, n+1, n]`
	 
	 So, **`m = width /2`**  - the `width` is the  number of buildings. 
	 
2) if two restraction has different limited height, suppose we have `[n ...... n+x]`
    then we still can have the building height list like 1) - we just add some buildings behind `[n .... n+x, (n+x-1... n) ]`
	
	So, **`m = (width+x)/2`** - we need to extend x buildings

3) if there hasn't enough buildings between two restractions. then,  the max height we can make is **`width`**.  For examples:
    - Building#1 max-height  = 2,  building#3 max-height = 5 : then, we only can make `[2,3,4]`
    - Building#1 max-height  = 2,  building#2 max-height = 9 : then, we only can make `[2,3]`

So, we can have the following source code to calculate the max height between two restractions.

```
    int getMaxHeight(vector<int>& left, vector<int>& right) {
        
        int width = right[0] - left[0];
        int height_delta = abs(right[1] - left[1]);
        int min_height = min (left[1], right[1]);
        
        //if the `width` is enough to have `height_delta`
        if (width >= height_delta) return min_height + (width + height_delta) / 2;
        
        // if the `width` is not enought have `height_delta`
        // then, the `width` is the max height we can make
        int max_height =  min_height + width;
        
        return max_height;
    }
```

BUT, we still have a case need to deal with, considering we have the following restractions:

`[1,1], [2,2] ,[3,3], [4,0]`

we can process them couple by couple.

- step 1: `[1,1], [2,2]` : max-height = 2
- step 2: `[2,2] ,[3,3]` : max-height = 3
- step 3: `[3,3], [4,0]` : max-height = 1

for the last couple of restractions, we can see the building#3 max-height is 1, so we have go backwards to recaluate the building#2 and building#1.

- step 3: `[3,1], [4,0]` : max-height = 1  (change the `[3,3]` to `[3,1]` )
- step:4: `[2,2] ,[3,1]` : max-height = 2
- step 5: `[1,1], [2,2]` : max-height = 2

So, the correct answer of max height is `2`

finally, we have the whole source code with debug code inside.
*/

class Solution {
private:
    void print(vector<vector<int>>& vv){
        cout << "[" ;
        for(int i = 0; i < vv.size()-1; i++) {
            cout << "[" <<vv[i][0] << "," << vv[i][1] << "],";
        }
        int i = vv.size()  - 1;
        cout << "[" << vv[i][0] << "," << vv[i][1] << "]]" << endl;
    }

public:
    int getMaxHeight(vector<int>& left, vector<int>& right) {

        int width = right[0] - left[0];
        int height_delta = abs(right[1] - left[1]);
        int min_height = min (left[1], right[1]);

        //if the `width` is enough to have `height_delta`
        if (width >= height_delta) return min_height + (width + height_delta) / 2;

        // if the `width` is not enought have `height_delta`
        // then, the `width` is the max height we can make
        int max_height =  min_height + width;

        // if the restriction is higher then make it to right limitation.
        left[1] = min (left[1], max_height);
        right[1] = min (right[1], max_height);

        return max_height;
    }

    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0});
        restrictions.push_back({n, n-1});
        sort(restrictions.begin(), restrictions.end());

        //print(restrictions);

        for(int i=0; i<restrictions.size()-1; i++){
            int height = getMaxHeight(restrictions[i], restrictions[i+1]);
            //cout << "[" << restrictions[i][0] << "," << restrictions[i][1]<< "] - "
            //     << "[" << restrictions[i+1][0] << "," << restrictions[i+1][1]<< "] = "
            //     << height << endl;
        }
        cout << endl;
        int maxHeight = 0;
        for(int i= restrictions.size()-1; i>0; i--){
            int height = getMaxHeight(restrictions[i-1], restrictions[i]);
            //cout << "[" << restrictions[i-1][0] << "," << restrictions[i-1][1]<< "] - "
            //     << "[" << restrictions[i][0] << "," << restrictions[i][1]<< "] = "
            //     << height << endl;
            maxHeight = max(maxHeight, height);

        }
        // cout << endl;
        return maxHeight;
    }
};
