// Source : https://oj.leetcode.com/problems/read-n-characters-given-read4/
// Author : Hao Chen
// Date   : 2014-11-20

/********************************************************************************** 
 * 
 * The API: int read4(char *buf) reads 4 characters at a time from a file.
 * 
 * The return value is the actual number of characters read. 
 * For example, it returns 3 if there is only 3 characters left in the file.
 * 
 * By using the read4 API, implement the function int read(char *buf, int n) 
 * that reads n characters from the file.
 * 
 * Note:
 *   The read function will only be called once for each test case.
 * 
 **********************************************************************************/


// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
    public:
        /**
         * @param buf Destination buffer
         * @param n   Maximum number of characters to read
         * @return    The number of characters read
         */
        int read(char *buf, int n) {
            srand(time(0));
            if (rand()%2){
                return read1(buf, n);
            }
            return read2(buf, n);
        }

        //read the data in-place. potential out-of-boundary issue
        int read1(char *buf, int n) {
            int len = 0;
            int size = 0;

            // `buf` could be accessed out-of-boundary 
            while(len <=n && (size = read4(buf))>0){
                size = len + size > n ?  n - len : size;
                len += size;
                buf += size;
            }
            return  len;
        }

        //using a temp-buffer to avoid peotential out-of-boundary issue
        int read2(char *buf, int n) {
            char _buf[4];   // the buffer for read4()
            int _n = 0;     // the return for read4()
            int len = 0;    // total buffer read from read4()
            int size = 0;   // how many bytes need be copied from `_buf` to `buf`
            while((_n = read4(_buf)) > 0){
                //check the space of `buf` whether full or not
                size = len + _n > n ? n-len : _n;
                strncpy(buf+len, _buf, size);
                len += size;
                //buffer is full
                if (len>=n){
                    break;
                }
            }
            return len;
        }
};
