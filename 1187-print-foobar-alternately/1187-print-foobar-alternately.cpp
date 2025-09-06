class FooBar {
private:
    int n;
    mutex m;
    condition_variable cv;
    int flag;
public:
    FooBar(int n) {
        this->n = n;
        flag = 1;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
            
        	// printFoo() outputs "foo". Do not change or remove this line.
        	if(flag == 0){
                cv.wait(lock);
            }
          
            printFoo();
            flag = 0;
            cv.notify_all();
            
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	if(flag == 1){
                cv.wait(lock);
            }
            printBar();
            flag = 1;
            cv.notify_all();
            
        }
    }
};