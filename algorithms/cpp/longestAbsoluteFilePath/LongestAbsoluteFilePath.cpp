// Source : https://leetcode.com/problems/longest-absolute-file-path/
// Author : Hao Chen
// Date   : 2016-08-23

/*************************************************************************************** 
 *
 * Suppose we abstract our file system by a string in the following manner:
 * 
 * The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
 * 
 * dir
 *     subdir1
 *     subdir2
 *         file.ext
 * 
 * The directory dir contains an empty sub-directory subdir1 and a sub-directory 
 * subdir2 containing a file file.ext.
 * 
 * The string 
 * "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile
 * 2.ext" represents:
 * 
 * dir
 *     subdir1
 *         file1.ext
 *         subsubdir1
 *     subdir2
 *         subsubdir2
 *             file2.ext
 * 
 * The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains 
 * a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 
 * contains a second-level sub-directory subsubdir2 containing a file file2.ext.
 * 
 * We are interested in finding the longest (number of characters) absolute path to a 
 * file within our file system. For example, in the second example above, the longest 
 * absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not 
 * including the double quotes).
 * 
 * Given a string representing the file system in the above format, return the length 
 * of the longest absolute path to file in the abstracted file system. If there is no 
 * file in the system, return 0.
 * 
 * Note:
 * 
 * The name of a file contains at least a . and an extension.
 * The name of a directory or sub-directory will not contain a ..
 * 
 * Time complexity required: O(n) where n is the size of the input string.
 * 
 * Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another 
 * path aaaaaaaaaaaaaaaaaaaaa/sth.png.
 ***************************************************************************************/

class Solution {
public:
    // Solution
    // --------
    // We can see the input formation has the order
    // so, we can maintain an array which states the current level's path length
    //
    // For example:
    //    dir
    //        subdir1            <- length[ level1 = len("dir")+len("/"), 
    //                                      level2 = len("dir")+len("/")+len("subdir1")+len("/") ] 
    //           file.ext
    //        subdir2
    //           file.ext
    //           subsubdir1     <- length[ level1 = len("dir")+len("/"), 
    //                                     level2 = len("dir")+len("/")+len("subdir2")+len("/"), 
    //                                     level3 = len("dir")+len("/")+len("subdir2")+len("/")+len("subsubdir1")+len("/") ] 
    //               file.ext  
    //
    int lengthLongestPath(string input) {
        
         stringstream ss(input); 
         string line;
         int result = 0;
         
         vector<int> length;
         length.push_back(0); //initialize top dummy level's length is zero
        
         while (getline(ss, line, '\n')) {
             //get current level, start from 1
             int level = 0;
             while ( line[level++] == '\t'); // get the level
             int len = line.size() - level + 1;

             //if is a file, then cacualte the total length.
             if (line.find('.') != string::npos) { 
                 if ( length[level-1] + len > result ) {
                    result = length[level-1] + len;
                 }
             } else {
                
                 if (length.size() <= level) {
                     length.push_back(0); 
                 }
                 
                 // if it a folder, then update the current level's length
                 length[level] = length[level-1] + len + 1; // 1 for "/" path delimiter
             }
             
         }
         return result;
    }
};
