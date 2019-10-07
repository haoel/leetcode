// Source : https://leetcode.com/problems/print-in-order
// Author : Siwei Xu
// Date   : 2019-10-07
/*

Print In Order
==============

Suppose we have a class:

public class Foo {
  public void first() { print("first"); }
  public void second() { print("second"); }
  public void third() { print("third"); }
}
The same instance of Foo will be passed to three different threads. Thread A will call first(), thread B will call second(), and thread C will call third(). Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().



Example 1:

Input: [1,2,3]
Output: "firstsecondthird"
Explanation: There are three threads being fired asynchronously. The input [1,2,3] means thread A calls first(), thread B calls second(), and thread C calls third(). "firstsecondthird" is the correct output.
Example 2:

Input: [1,3,2]
Output: "firstsecondthird"
Explanation: The input [1,3,2] means thread A calls first(), thread B calls third(), and thread C calls second(). "firstsecondthird" is the correct output.


Note:

We do not know how the threads will be scheduled in the operating system, even though the numbers in the input seems to imply the ordering. The input format you see is mainly to ensure our tests' comprehensiveness.
*/
#include <vector>
#include <atomic>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class Foo {
public:
    int last;
    mutex m;
    condition_variable cv;
    Foo() : last(0) {}

    void first(function<void()> printFirst) {
        unique_lock<mutex> lck(m);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        last = 1;
        cv.notify_one();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lck(m);
        while(last != 1){
            cv.wait(lck);
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        last = 2;
        cv.notify_one();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lck(m);
        while(last != 2){
            cv.wait(lck);
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};

namespace lock_free
{

class Foo {
    atomic<bool> f1;
    atomic<bool> f2;
public:
    Foo() : f1(false), f2(false) { }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        f1 = true;
    }

    void second(function<void()> printSecond) {
        // printSecond() outputs "second". Do not change or remove this line.
        while (!f1) {
            this_thread::yield();
        }
        printSecond();
        f2 = true;
    }

    void third(function<void()> printThird) {
        // printThird() outputs "third". Do not change or remove this line.
        while (!f2) {
            this_thread::yield();
        }
        printThird();
    }
};

} // namespace lock_free

void prints(const char* s) {
    printf(s); fflush(stdout);
}

int main(int argc, char* argv[])
{
    // using lock_free::Foo;
    Foo foo;

    vector<thread> threads;
    threads.push_back(thread(&Foo::first, &foo, [](){
        prints("first");
    }));
    threads.push_back(thread(&Foo::second, &foo, [](){
        prints("second");
    }));
    threads.push_back(thread(&Foo::third, &foo, [](){
        prints("thrid");
    }));

    for (auto& t: threads) t.join();

    prints("\n");
    return 0;
}
