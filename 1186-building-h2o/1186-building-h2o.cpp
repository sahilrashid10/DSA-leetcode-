class H2O {
private:
    mutex m;
    condition_variable cv;
    int count;
public:
    H2O() {
        count = 0; 
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        unique_lock<mutex> lock(m);
        cv.wait(lock, [&]{return count < 2;});
        releaseHydrogen();
        count++;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        unique_lock<mutex> lock(m);
        cv.wait(lock, [&]{return count == 2;});
        releaseOxygen();
        count = 0;
        cv.notify_all();
    }
};