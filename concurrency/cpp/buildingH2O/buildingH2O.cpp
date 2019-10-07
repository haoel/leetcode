// Source : https://leetcode.com/problems/building-h2o
// Author : Siwei Xu
// Date   : 2019-10-07
/*

Building H2O
============

There are two kinds of threads, oxygen and hydrogen. Your goal is to group these threads to form water molecules. There is a barrier where each thread has to wait_consumed until a complete molecule can be formed. Hydrogen and oxygen threads will be given releaseHydrogen and releaseOxygen methods respectively, which will allow them to pass the barrier. These threads should pass the barrier in groups of three, and they must be able to immediately bond with each other to form a water molecule. You must guarantee that all the threads from one molecule bond before any other threads from the next molecule do.

In other words:

If an oxygen thread arrives at the barrier when no hydrogen threads are present, it has to wait_consumed for two hydrogen threads.
If a hydrogen thread arrives at the barrier when no other threads are present, it has to wait_consumed for an oxygen thread and another hydrogen thread.
We don’t have to worry about matching the threads up explicitly; that is, the threads do not necessarily know which other threads they are paired up with. The key is just that threads pass the barrier in complete sets; thus, if we examine the sequence of threads that bond and divide them into groups of three, each group should contain one oxygen and two hydrogen threads.

Write synchronization code for oxygen and hydrogen molecules that enforces these constraints.



Example 1:

Input: "HOH"
Output: "HHO"
Explanation: "HOH" and "OHH" are also valid answers.
Example 2:

Input: "OOHHHH"
Output: "HHOHHO"
Explanation: "HOHHHO", "OHHHHO", "HHOHOH", "HOHHOH", "OHHHOH", "HHOOHH", "HOHOHH" and "OHHOHH" are also valid answers.


Constraints:

Total length of input string will be 3n, where 1 ≤ n ≤ 20.
Total number of H will be 2n in the input string.
Total number of O will be n in the input string.

*/
#include <assert.h>
#include <unistd.h>
#include <syscall.h>
#include <unordered_set>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
#include <atomic>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

long gettid() { return syscall(SYS_gettid); }

#define LOGI(fmt, ...) \
    do { \
        static mutex m; \
        unique_lock<mutex> lock(m); \
        printf("[%ld] %8s +%3d: " fmt "\n", gettid(), __FUNCTION__, __LINE__, ##__VA_ARGS__); \
        fflush(stdout); \
    } while (0)

#define LOGD(fmt, ...)  // LOGI(fmt, ##__VA_ARGS__)


class H2O {
    mutex m;
    condition_variable cv; // for H/O in, and H2O out
    int H = 0, O = 0;

public:
    H2O() { }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lk(m);
        cv.wait(lk, [&](){ return H < 2; });
        // H: {0, 1}

        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();

        H++; // H: {1, 2}
        if (H == 2 && O == 1) {
            H = 0; //
            O = 0;
        }
        cv.notify_all(); // H: {0, 1, 2}
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lk(m);
        cv.wait(lk, [&]() { return O < 1; });
        // O: {0}

        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        O++; // O: {1}
        if (H == 2 && O == 1) {
            H = 0;
            O = 0;
        }
        cv.notify_one(); // O: {0, 1}
    }
};

void append(string& output, char c)
{
    static std::mutex m;
    std::unique_lock<mutex> lk(m);
    putchar(c); fflush(stdout);
    output += c; // for result check
}

string test(string input)
{
    H2O h2o;
    string output;

    LOGI("start %zu threads...", input.size());
    std::vector<thread> threads;
    for (size_t i = 0; i < input.size(); i++) {
        const char c = input[i];
        if (c == 'H') {
            threads.push_back(std::thread(&H2O::hydrogen, &h2o, [&]() {
                append(output, 'H');
            }));
        } else {
            threads.push_back(std::thread(&H2O::oxygen, &h2o, [&]() {
                append(output, 'O');
            }));
        }
    }

    for (size_t i = 0; i < threads.size(); i++) {
        threads[i].join();
    }
    putchar('\n');
    LOGI("join %zu threads done!", threads.size());
    return output;
}

bool check(string output)
{
    LOGI("output: %s", output.c_str());
    bool result = true;
    for (size_t i = 0; i < output.size(); i += 3) {
        string os = output.substr(i, 3u);
        string ss = os;
        sort(ss.begin(), ss.end());
        if(ss != "HHO") {
            result = false;
            LOGI("CHECK FAILED at %zu: %s", i, os.c_str());
        }
    }
    return result;
}

int main(int argc, char* argv[])
{
    int n = argc > 1 ? atoi(argv[1]) : 8;
    string input;
    input.resize(n, 'O');
    input.resize(3*n, 'H');
    LOGI("input : %s", input.c_str());

    string output = test(input);
    bool result = check(output);
    LOGI("check %s!", result ? "SUCC" : "FAIL");

    return 0;
}
