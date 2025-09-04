#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <array>

using namespace std;

/*
  Semaphore with setCount / wait / signal operations.
  Implemented using a mutex + condition_variable.
*/
class Semaphore {
private:
    mutex m;
    condition_variable cv;
    int count = 0;

public:
    Semaphore() = default;
    Semaphore(int init) : count(init) {}

    // Set initial count (used in screenshot-style initialization)
    void setCount(int c) {
        unique_lock<mutex> lock(m);
        count = c;
        if (count > 0) cv.notify_all();
    }

    // Wait (P) - block until count > 0 then decrement
    void wait() {
        unique_lock<mutex> lock(m);
        while (count == 0) cv.wait(lock);
        --count;
    }

    // Signal (V) - increment and wake one waiter
    void signal() {
        unique_lock<mutex> lock(m);
        ++count;
        cv.notify_one();
    }
};

///////////////////////////////////////////////////////////////////////////////
// DiningPhilosophers matching the screenshot logic:
// - Semaphore fork[5]
// - std::mutex m used as a global lock for ordering fork acquisition
// - In wantsToEat: lock, wait on fork[(i+1)%5], wait on fork[i], then pickLeft/pickRight
///////////////////////////////////////////////////////////////////////////////
class DiningPhilosophers {
private:
    std::array<Semaphore, 5> fork; // 5 forks
    std::mutex m;                  // global mutex (prevents circular waiting)

public:
    DiningPhilosophers() {
        // initialize each fork's count to 1 (available)
        for (int i = 0; i < 5; ++i) fork[i].setCount(1);
    }

    // The callbacks are provided by caller (matching LeetCode-style signature)
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

        // Acquire a global lock while acquiring fork semaphores to avoid deadlock.
        // NOTE: this mirrors the screenshot which does:
        //   lock(m);
        //   fork[(i+1)%5].wait();
        //   fork[i].wait();
        {
            lock_guard<mutex> lock(m);

            // Acquire right fork first ((i+1) % 5)
            fork[(philosopher + 1) % 5].wait();

            // Acquire left fork (philosopher)
            fork[philosopher].wait();
        } // release global lock here

        // At this point the philosopher holds both forks (semaphores).
        // The screenshot then calls pickLeftFork() then pickRightFork().
        pickLeftFork();
        pickRightFork();

        // Eat (critical section with forks held, but global lock released)
        eat();

        // Put down forks and signal semaphores (release resources).
        putLeftFork();
        fork[(philosopher + 1) % 5].signal();

        putRightFork();
        fork[philosopher].signal();
    }
};

///////////////////////////////////////////////////////////////////////////////
// Small demo main() to show the behavior. This launches 5 threads, each
// calling wantsToEat once. Output order is non-deterministic (depends on OS).
///////////////////////////////////////////////////////////////////////////////
// int main() {
//     DiningPhilosophers dp;

//     auto pickLeftFork  = [](){ cout << "pickLeftFork\n"; };
//     auto pickRightFork = [](){ cout << "pickRightFork\n"; };
//     auto eat           = [](){ cout << "eat\n"; };
//     auto putLeftFork   = [](){ cout << "putLeftFork\n"; };
//     auto putRightFork  = [](){ cout << "putRightFork\n"; };

//     // Launch 5 philosopher threads (each will try to pick forks using the same order as screenshot)
//     array<thread,5> threads;
//     for (int i = 0; i < 5; ++i) {
//         threads[i] = thread([&dp, i, &pickLeftFork, &pickRightFork, &eat, &putLeftFork, &putRightFork]() {
//             dp.wantsToEat(i, pickLeftFork, pickRightFork, eat, putLeftFork, putRightFork);
//         });
//     }

//     for (auto &t : threads) if (t.joinable()) t.join();

//     return 0;
// }
