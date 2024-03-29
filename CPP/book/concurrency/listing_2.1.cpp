#include <thread>

void do_something(int& i) {
    ++i;
}

struct func {
    int& i;

    func(int& i_) : i(i_) {
        printf("Constructor of func:%d\n", i_);
    }

    void operator()() {
        for (unsigned j=0;j<1000000;++j) {
            do_something(i); // Hidden Problems
        }
        printf("%d\n", i);
    }
};


void oops() {
    int some_local_state = 0;
    func my_func(some_local_state); // call constructor of func

    std::thread my_thread(my_func);

    /*
    thread对象销毁前，必须调用detach()或者join()两者之一
    对于某个给定的线程，只能调用一次join()或者detach()
    可通过joinable()判断线程是否已经被join或者detach
    detach的线程，归属权和控制权会转移给C++ runtime library，以确保资源回收
    */
    // my_thread.join(); 
    my_thread.detach(); // detach()、join()二选一
    assert(!my_thread.joinable());
}

int main() {
    oops();
}
