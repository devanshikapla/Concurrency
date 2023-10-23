class Foo {
public:
    int cnt = 0;
    mutex mtx;
    condition_variable cv;

    Foo() {
        cnt = 1;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        unique_lock < mutex > lock(mtx);
        printFirst();
        cnt = 2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        unique_lock < mutex > lock(mtx);
        while(cnt != 2){
            cv.wait(lock);

        }
        printSecond();
        cnt = 3;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        unique_lock < mutex > lock(mtx);
        while(cnt != 3){
            cv.wait(lock);
        }
        printThird();
    }
};
