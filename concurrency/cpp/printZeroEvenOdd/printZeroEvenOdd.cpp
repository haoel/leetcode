// Source : https://leetcode.com/problems/print-zero-even-odd
// Author : Siwei Xu
// Date   : 2019-10-07
/*

Print Zero Even Odd
===================

Suppose you are given the following code:

class ZeroEvenOdd {
  public ZeroEvenOdd(int n) { ... }      // constructor
  public void zero(printNumber) { ... }  // only output 0's
  public void even(printNumber) { ... }  // only output even numbers
  public void odd(printNumber) { ... }   // only output odd numbers
}
The same instance of ZeroEvenOdd will be passed to three different threads:

Thread A will call zero() which should only output 0's.
Thread B will call even() which should only ouput even numbers.
Thread C will call odd() which should only output odd numbers.
Each of the threads is given a printNumber method to output an integer. Modify the given program to output the series 010203040506... where the length of the series must be 2n.



Example 1:

Input: n = 2
Output: "0102"
Explanation: There are three threads being fired asynchronously. One of them calls zero(), the other calls even(), and the last one calls odd(). "0102" is the correct output.
Example 2:

Input: n = 5
Output: "0102030405"
*/
#include <unistd.h>
#include <sys/types.h>
#include <syscall.h>
#include <math.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>

using namespace std;

long gettid() { return syscall(SYS_gettid); }

static inline bool is_odd(int n) { return n & 1; }
static inline bool is_even(int n) { return !is_odd(n); }

class ZeroEvenOdd {
private:
    mutex m;
    int n;
    int x{0}; // last printed non-zero number
    bool zeroed{false}; // zero printed
    condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while (1) {
            unique_lock<mutex> lock(m);

            cv.wait(lock, [&]() { return !zeroed || x >= n; });
            if (x >= n) break;

            printNumber(0);
            zeroed = true;

            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while (1) {
            unique_lock<mutex> lock(m);

            cv.wait(lock, [&]() { return (is_even(x) && zeroed) || x >= n; });
            if (x >= n) break;

            printNumber(++x);
            zeroed = false;

            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while (1) {
            unique_lock<mutex> lock(m);

            cv.wait(lock, [&]() { return (is_odd(x) && zeroed) || x >= n; });
            if (x >= n) break;

            printNumber(++x);
            zeroed = false;

            cv.notify_all();
        }
    }
};


namespace v2 {

class ZeroEvenOdd {
private:
    mutex m;
    int n;
    int x{0};
    int next{0};
    condition_variable cv_zero;
    condition_variable cv_odd;
    condition_variable cv_even;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    //x: 0      1       1       2
    // ZERO -> ODD -> ZERO -> EVEN
    //  ^                       |
    //  +-----------------------+

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while (1) {
            unique_lock<mutex> lock(m);
            cv_zero.wait(lock, [&]() { return next == 0 || x >= n; });
            if (x >= n) {
                cv_odd.notify_one();
                cv_even.notify_one();
                break;
            }

            printNumber(0); next = x+1;

            if (is_odd(next)) {
                cv_odd.notify_one();
            } else {
                cv_even.notify_one();
            }
        }
    }

    void odd(function<void(int)> printNumber) {
        while (1) {
            unique_lock<mutex> lock(m);
            cv_odd.wait(lock, [&]() { return is_even(x) || x >= n; });
            if (x >= n) break;

            printNumber(++x); next = 0;

            cv_zero.notify_one();
        }
    }

    void even(function<void(int)> printNumber) {
        while (1) {
            unique_lock<mutex> lock(m);
            cv_even.wait(lock, [&]() { return is_odd(x) || x >= n; });
            if (x >= n) break;

            printNumber(++x); next = 0;

            cv_zero.notify_one();
        }
    }
};

}

namespace lock_free
{

class ZeroEvenOdd {
private:
    int n;
    atomic<int> index{0};

public:
    ZeroEvenOdd(int n) {
        this->n = 2*n;
    }

    // input n=5
    // index: 0 1 2 3 4 5 6 7 8 9
    // print: 0 1 0 2 0 3 0 4 0 5

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n;) { // 0, 2, 4...
            int x = index.load();
            if (x != i) {
                std::this_thread::yield();
                continue;
            }
            printNumber(0);
            index.store(x + 1);
            i += 2;
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i < n;) { // 1, 5, 9...
            int x = index.load();
            if (x != i) {
                std::this_thread::yield();
                continue;
            }
            printNumber((x+1) / 2);
            index.store(x + 1);
            i += 4;
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 3; i < n;) { // 3, 7, 11...
            int x = index.load();
            if (x != i) {
                std::this_thread::yield();
                continue;
            }
            printNumber((x+1) / 2);
            index.store(x + 1);
            i += 4;
        }
    }
};

} // namespace lock_free


void printNumber(int n) {
    // static std::mutex m;
    // std::unique_lock<std::mutex> lock(m);
    // cout << gettid() << ": " << n << endl;
    cout << n;
}

int main(int argc, char* argv[]) {
    int n = argc > 1 ? stoi(argv[1]) : 2;

    using ZeroEvenOdd = lock_free::ZeroEvenOdd;
    ZeroEvenOdd zeo(n);

    thread t0(&ZeroEvenOdd::zero, &zeo, printNumber);
    thread t1(&ZeroEvenOdd::odd,  &zeo, printNumber);
    thread t2(&ZeroEvenOdd::even, &zeo, printNumber);

    t0.join();
    t1.join();
    t2.join();

    cout << endl;
    return 0;
}