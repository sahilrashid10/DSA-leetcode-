class ZeroEvenOdd {
private:
    int n;
    int num;
    int turn; // 0 = zero, 1 = odd, 2 = even
    mutex m;
    condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        num = 1;   // start from 1
        turn = 0;  // zero goes first
    }

    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&]{ return turn == 0; });
            printNumber(0);
            if (num % 2 == 1) turn = 1; // next is odd
            else turn = 2;              // next is even
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&]{ return turn == 2; });
            printNumber(num++);
            turn = 0; // back to zero
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&]{ return turn == 1; });
            printNumber(num++);
            turn = 0; // back to zero
            cv.notify_all();
        }
    }
};
