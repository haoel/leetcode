// Source : https://leetcode.com/problems/fizz-buzz-multithreaded/
// Author : Siwei Xu
// Date   : 2019-10-07
/*
copyright xu(xusiwei1236@163.com), all right reserved.

Fizz Buzz Multithreaded
=======================

Write a program that outputs the string representation of numbers from 1 to n, however:

If the number is divisible by 3, output "fizz".
If the number is divisible by 5, output "buzz".
If the number is divisible by both 3 and 5, output "fizzbuzz".
For example, for n = 15, we output: 1, 2, fizz, 4, buzz, fizz, 7, 8, fizz, buzz, 11, fizz, 13, 14, fizzbuzz.

Suppose you are given the following code:

class FizzBuzz {
  public FizzBuzz(int n) { ... }               // constructor
  public void fizz(printFizz) { ... }          // only output "fizz"
  public void buzz(printBuzz) { ... }          // only output "buzz"
  public void fizzbuzz(printFizzBuzz) { ... }  // only output "fizzbuzz"
  public void number(printNumber) { ... }      // only output the numbers
}
Implement a multithreaded version of FizzBuzz with four threads. The same instance of FizzBuzz will be passed to four different threads:

Thread A will call fizz() to check for divisibility of 3 and outputs fizz.
Thread B will call buzz() to check for divisibility of 5 and outputs buzz.
Thread C will call fizzbuzz() to check for divisibility of 3 and 5 and outputs fizzbuzz.
Thread D will call number() which should only output the numbers.
*/
#include <stdio.h>
#include <unistd.h>
#include <syscall.h>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <iostream>
using namespace std;

#ifdef DEBUG
long gettid() { return syscall(SYS_gettid); }
#define LOGI(fmt, ...) LOGD(fmt, ##__VA_ARGS__)
#define LOGD(fmt, ...) \
    do { \
        static mutex m; \
        unique_lock<mutex> lock(m); \
        printf("[%ld] %8s +%3d: " fmt "\n", gettid(), __FUNCTION__, __LINE__, ##__VA_ARGS__); \
        fflush(stdout); \
    } while (0)
#else
#define LOGI(fmt, ...)
#define LOGD(fmt, ...)
#endif

class FizzBuzz {
private:
    mutex mt;
    int n;
    int next;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->next = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (1) {
            unique_lock<mutex> lk(mt);
            LOGD("wait 3x");
            cv.wait(lk, [this](){ return (next % 3 == 0 && next % 15 != 0) || next > n; });
            if (next > n) break;

            printFizz();

            next++;
            LOGD("next: %d", next);
            lk.unlock();
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (1) {
            unique_lock<mutex> lk(mt);
            LOGD("wait 5x");
            cv.wait(lk, [this](){ return (next % 5 == 0 && next % 15 != 0) || next > n; });
            if (next > n) break;

            printBuzz();

            next++;
            LOGD("next: %d", next);
            lk.unlock();
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while (1) {
            unique_lock<mutex> lk(mt);
            LOGD("wait 15x");
            cv.wait(lk, [this](){ return (next % 15 == 0) || next > n; });
            if (next > n) break;

            printFizzBuzz();

            next++;
            LOGD("next: %d", next);
            lk.unlock();
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (1) {
            unique_lock<mutex> lk(mt);
            LOGD("wait others");
            cv.wait(lk, [this](){ return (next%3 != 0 && next%5 != 0 && next%15 != 0) || next > n; });
            if (next > n) break;

            printNumber(next);

            next++;
            LOGD("next: %d", next);
            lk.unlock();
            cv.notify_all();
        }
    }
};

namespace lock_free {

class FizzBuzz {
private:
    int n;
    atomic<int> next;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->next = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (1) {
            int x = next.load(); // read once
            if (x > n) break;
            if (x % 3 == 0 && x % 15 != 0) {
                printFizz();
                next.store(x + 1);
            } else {
                this_thread::yield();
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (1) {
            int x = next.load(); // read once
            if (x > n) break;
            if (x % 5 == 0 && x % 15 != 0) {
                printBuzz();
                next.store(x + 1);
            } else {
                this_thread::yield();
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while (1) {
            int x = next.load(); // read once
            if (x > n) break;
            if (x % 15 == 0) {
                printFizzBuzz();
                next.store(x + 1);
            } else {
                this_thread::yield();
            }

        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (1) {
            int x = next.load(); // read once
            if (x > n) break;
            if (x%3 != 0 && x%5 != 0 && x%15 != 0) {
                printNumber(x);
                next.store(x + 1);
            } else {
                this_thread::yield();
            }
        }
    }
};

} // lock_free

int main(int argc, char* argv[])
{
    int n = argc > 1 ? atoi(argv[1]) : 15;

#ifdef LOCK_FREE
    using lock_free::FizzBuzz;
#endif
    FizzBuzz fb(n);

    thread fizz(&FizzBuzz::fizz, &fb, []() { printf("fizz,"); });
    thread buzz(&FizzBuzz::buzz, &fb, []() { printf("buzz,"); });
    thread fizzbuzz(&FizzBuzz::fizzbuzz, &fb, []() { printf("fizzbuzz,"); });
    thread number(&FizzBuzz::number, &fb, [](int n) { printf("%d,", n); });

    fizz.join();
    buzz.join();
    fizzbuzz.join();
    number.join();

    return 0;
}

