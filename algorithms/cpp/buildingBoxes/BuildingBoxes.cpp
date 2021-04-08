// Source : https://leetcode.com/problems/building-boxes/
// Author : Hao Chen
// Date   : 2021-04-09

/***************************************************************************************************** 
 *
 * You have a cubic storeroom where the width, length, and height of the room are all equal to n 
 * units. You are asked to place n boxes in this room where each box is a cube of unit side length. 
 * There are however some rules to placing the boxes:
 * 
 * 	You can place the boxes anywhere on the floor.
 * 	If box x is placed on top of the box y, then each side of the four vertical sides of the 
 * box y must either be adjacent to another box or to a wall.
 * 
 * Given an integer n, return the minimum possible number of boxes touching the floor.
 * 
 * Example 1:
 * 
 * Input: n = 3
 * Output: 3
 * Explanation: The figure above is for the placement of the three boxes.
 * These boxes are placed in the corner of the room, where the corner is on the left side.
 * 
 * Example 2:
 * 
 * Input: n = 4
 * Output: 3
 * Explanation: The figure above is for the placement of the four boxes.
 * These boxes are placed in the corner of the room, where the corner is on the left side.
 * 
 * Example 3:
 * 
 * Input: n = 10
 * Output: 6
 * Explanation: The figure above is for the placement of the ten boxes.
 * These boxes are placed in the corner of the room, where the corner is on the back side.
 * 
 * Constraints:
 * 
 * 	1 <= n <= 10^9
 ******************************************************************************************************/

/*

    At first, let's  build the perfect pyramid at the corner.

    we can find the following sequence:

        height    cubes
        1         1
        2         1 + 2 = 3
        3         1 + 2 + 3 = 6
        4         1 + 2 + 3 + 4 = 10
        5         1 + 2 + 3 + 4 + 5 = 15

    total(height) = total(height - 1) + sum( from 1 to height )
    
    sum ( from 1 to height) = (height * (height+1)) / 2
                            = height^2/2 + height/2
    So,
    
    total(height) =  (1+2+...+height)/2 + ( 1^2 + 2^2 +...+ height^2 ) / 2
    
    we know,  Σn^2 = [n(n+1)(2n+1)]/6  (ref: https://brilliant.org/wiki/sum-of-n-n2-or-n3/)
    
    So, 
    
    total(height) = (height * (height+1)) / 4 + (height(height+1)(2height+1))/12
                  = height * (height + 1) * (height + 2) / 6
    

    for the rest cubes, we can place them like this

             (10) 
            (6) (9) 
          (3) (5) (8) 
        (1) (2) (4) (7) 
        
    sum ( for 1 to n ) = n(n+1)/2
    

*/


class Solution {
private:
    int total(long h){
        return h * (h+1) * (h+2) / 6;
    }
public:
    int minimumBoxes(int n) {
        //find the maxiumn height which total(height) <= n
        //binary search
        int left = 1, right = pow(6l*n, 1.0/3) ;
        while(left <= right){
            int mid = left + (right - left) / 2;
            int t = total(mid);
            if ( t == n ) return mid*(mid+1l)/2;
            if ( t < n) left = mid + 1;
            else right = mid - 1;
        }
        int height = right;
        int remind = n - total(height);
        int bottom = height * (height+1l)/2 ;
        //cout << "n=" << n << ", height=" << height << 
        //    ", bottom = " << bottom << ", remind=" << remind << endl;
        
        //find teh maxium h which sum(1..h) <= remind
        //binary search
        left = 1; right = sqrt(2*remind);
        while ( left <= right) {
            int mid = left + (right - left)/2;
            int h = mid*(mid+1)/2;
            if ( h == remind) return bottom + mid;
            if ( h < remind) left = mid + 1;
            else right = mid -1;
        }
        //cout << "left=" << left << ", right=" << right << endl;
        return bottom + left;
    }
};
