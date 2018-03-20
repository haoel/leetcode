// Source : https://oj.leetcode.com/problems/trapping-rain-water/
// Author : Hao Chen
// Date   : 2014-07-02

/********************************************************************************** 
* 
* Given n non-negative integers representing an elevation map where the width of each bar is 1, 
* compute how much water it is able to trap after raining. 
* 
* For example, 
* Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*   
*     ^                                             
*     |                                             
*   3 |                       +--+                  
*     |                       |  |                  
*   2 |          +--+xxxxxxxxx|  +--+xx+--+         
*     |          |  |xxxxxxxxx|  |  |xx|  |         
*   1 |   +--+xxx|  +--+xxx+--+  |  +--+  +--+      
*     |   |  |xxx|  |  |xxx|  |  |  |  |  |  |      
*   0 +---+--+---+--+--+---+--+--+--+--+--+--+----->
*       0  1   0  2  1   0  1  3  2  1  2  1        
* 
* The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 
* 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*               
**********************************************************************************/

#include <iostream>
#include <vector>

int Trap(std::vector<int>& elev) {
  int capacity = 0;
  
  while (true) {  // Scan levels from the bottom to the top.
    int non_zero = 0;  // count non-zero, i.e., the number of blocks.
    int left = elev.size();
    int right = -1;
    for (int i = 0; i < elev.size(); ++i) {
      if (elev[i] > 0) {
	left = (left == elev.size()) ? i : left;
	right = i;
	non_zero++;
      }
      elev[i]--;
    }

    if (right - left < 2)
      break;

    capacity += right - left - 1 - non_zero + 2;
  }

  return capacity;
}

int main() {
  std::vector<int> elev = {0,1,0,2,1,0,1,3,2,1,2,1};
  std::cout << Trap(elev) << "\n";
  return 0;
}
