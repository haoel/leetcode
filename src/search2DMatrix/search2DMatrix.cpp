// Source : https://oj.leetcode.com/problems/search-a-2d-matrix/
// Author : Hao Chen
// Date   : 2014-06-23

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        
        int idx = vertical_binary_search(matrix, target);
        if (idx<0){
            return false;
        }
        
        idx = binary_search(matrix[idx], target);
        
        return (idx < 0 ? false : true);
        
    }
    int vertical_binary_search(vector< vector<int> > v, int key){
        int low = 0;
        int high = v.size()-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if (v[mid][0] == key){
                return mid;
            }
            if (key < v[mid][0]){
                high = mid - 1;
                continue;
            }
            if (key > v[mid][0]){
                low = mid + 1;
                continue;
            }
        }
        return low-1;        
    }
    
    int binary_search(vector<int> v, int key) {
        int low = 0;
        int high = v.size()-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if (v[mid] == key){
                return mid;
            }
            if (key < v[mid]){
                high = mid - 1;
                continue;
            }
            if (key > v[mid]){
                low = mid + 1;
                continue;
            }
        }
        return -1;
    }
};
