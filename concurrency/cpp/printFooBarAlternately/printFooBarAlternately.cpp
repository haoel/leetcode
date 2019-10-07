// Source : https://leetcode.com/problems/print-foobar-alternately
// Author : Siwei Xu
// Date   : 2019-10-07
/*

Print Foobar Alternately
========================

Suppose you are given the following code:

class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}
The same instance of FooBar will be passed to two different threads. Thread A will call foo() while thread B will call bar(). Modify the given program to output "foobar" n times.



Example 1:

Input: n = 1
Output: "foobar"
Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar(). "foobar" is being output 1 time.
Example 2:

Input: n = 2
Output: "foobarfoobar"
Explanation: "foobar" is being output 2 times.
*/

#include <vector>
#include <atomic>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class FooBar {
private:
    mutex m;
    condition_variable cv;
    int n;
    bool flag = false; // for foo printed

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&](){ return !flag; });
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            flag = true;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&](){ return flag; });
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            flag = false;
            cv.notify_one();
        }
    }
};

namespace lock_free
{
class FooBar {
private:
    int n;
    atomic<bool> flag{false}; // for foo printed

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            while (flag) { this_thread::yield(); }
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            flag = true;
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            while (!flag) { this_thread::yield(); }
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            flag = false;
        }
    }
};
} // namespace lock_free


void prints(const char* s) {
    printf(s); fflush(stdout);
}

int main(int argc, char* argv[])
{
    int n = argc > 1 ? atoi(argv[1]) : 10;

    using lock_free::FooBar;
    FooBar fb(n);
    vector<thread> threads;
    threads.push_back(thread(&FooBar::foo, &fb, [](){
        prints("foo");
    }));
    threads.push_back(thread(&FooBar::bar, &fb, [](){
        prints("bar");
    }));
    for (auto& t: threads) t.join();
    prints("\n");
    return 0;
}
