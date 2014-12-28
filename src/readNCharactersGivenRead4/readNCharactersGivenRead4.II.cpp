// Source : https://oj.leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/
// Author : Hao Chen
// Date   : 2014-12-01


/*
 * The API: int read4(char *buf) reads 4 characters at a time from a file.
 * 
 * The return value is the actual number of characters read. 
 * For example, it returns 3 if there is only 3 characters left in the file.
 * 
 * By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
 * 
 * Note:
 * The read function may be called multiple times.
 */


/*
 *  The key to solve this problem is: 
 *
 *    You have to buffer the extra data return from `read4()` API, which is for next call for `read()` .
 */

#include <stdio.h>
#include <string.h>
// Forward declaration of the read4 API.
static char input[64];
static char *p = input;

int read4(char *buf) {

    int s=0;
    for (; s<4 && *p!='\0'; s++){
        buf[s] = *p;
        p++;
    } 
    return s;
}


class RingBuffer {

    public:
        RingBuffer(int cap=4): _capacity(cap) {
            _size = 0;

            _pbuf = new char[_capacity];
            _p = _pbuf;
            _pend = _pbuf + _capacity - 1;
        } 
        ~RingBuffer(){
            delete _pbuf;
        }
        int read(char* buf, int n){
            //empty, nothing can read
            if (_size==0) return 0;

            //read `n` or all 
            int s;
            for (s=0; s<n && s<_size; s++){
                buf[s] = *_p;
                _p = (_p < _pend) ? _p + 1 : _pbuf;  
            }
            _size -= s;
            return s;
        }

        int write(char* buf, int n) {
            //full, cannot write
            if (_size >= _capacity) return 0;

            //write `n` or all
            int s;
            char *p = _p + _size;
            for (s=0; s < _capacity - _size && s < n; s++){
                *p = buf[s];
                p = (p < _pend) ? p + 1 : _pbuf;
            }
            _size += s;
            return s;
        }

    private:
        const int   _capacity;
        int         _size;

        char*       _pbuf;
        char*       _p;
        char*       _pend;

};

class Solution {
    public:
        /**
         * @param buf Destination buffer
         * @param n   Maximum number of characters to read
         * @return    The number of characters read
         */
        int read(char *buf, int n) {
            int buf_size = 0;
            int api_size = 0;

            //read the data from the RingBuffer at first
            buf_size = _ring_buffer.read(buf, n);
            if (buf_size == n) {
                return n;
            }
            n = n - buf_size;

            //read the data from the API at second
            api_size = read1(buf + buf_size, n);

            return buf_size + api_size;
        }

        // The read1 implementation is from the `Read N Characters Given Read4` problem
        // Add the feature - write the extra char(s) into RingBuffer
        int read1(char *buf, int n) {
            char _buf[4];   // the buffer for read4()
            int _n = 0;     // the return for read4()
            int len = 0;    // total buffer read from read4()
            int size = 0;   // how many bytes need be copied from `_buf` to `buf`
            while((_n = read4(_buf)) > 0){
                //check the space of `buf` whether full or not
                size = len + _n > n ? n-len : _n;
                //write the extra char(s) into RingBuffer
                if (len + _n > n ){
                    _ring_buffer.write(_buf + size, _n - size);    
                }
                strncpy(buf+len, _buf, size);
                len += size;
                //buffer is full
                if (len>=n){
                    break;
                }
            }
            return len;
        }


    private: 
        RingBuffer _ring_buffer;
};


int main()
{
    Solution s;
    const int buf_len = 10;
    char buf[buf_len]={0};
#define SET_INPUT(s)    strcpy(input, s); p=input; printf("input data = \"%s\"\n", p);
#define CLEAR_BUFFER()  memset(buf, 0, sizeof(buf)/sizeof(buf[0]) )
#define READ(s, buf, n) CLEAR_BUFFER(); printf("read(%d) => ",n); s.read(buf, n); printf("%s\n", buf);

    printf("-----------------------------\n");
    SET_INPUT("1234abcd1234abcdxyz");
    for(int i=0; i<5; i++){
        READ(s, buf, 4);
    }
    printf("-----------------------------\n");
    SET_INPUT("ab");
    READ(s, buf, 1);
    READ(s, buf, 2);

    printf("-----------------------------\n");
    SET_INPUT("abcde");
    for(int i=0; i<5; i++){
        READ(s, buf, 1);
    }
    printf("-----------------------------\n");
    SET_INPUT("1234xyzabcd00");
    READ(s, buf, 4);
    for(int i=0; i<3; i++){
        READ(s, buf, 1);
    }
    READ(s, buf, 4);
    printf("-----------------------------\n");
    return 0;
}
